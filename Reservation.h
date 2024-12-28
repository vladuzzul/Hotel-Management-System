//
// Created by Vlad Cozma on 27.12.2024.
//

#ifndef HOTEL_ROOM_REZERVATION_MANAGER_RESERVATION_H
#define HOTEL_ROOM_REZERVATION_MANAGER_RESERVATION_H
#include "Classes.h"
#include "Profile.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

string hotel_name {"Your hotel's"};

ofstream rout("Reservation.txt", ios::app);

bool checkOverBook(const vector<Reservation>& reservations, int roomNum, const string& check_in, const string& check_out){
    for(const auto& reservation : reservations)
        if (reservation.room_number == roomNum)
            if (check_in < reservation.check_out && check_out > reservation.check_in){
                cout << "\nOverbooked with reservation number " << reservation.id << "\n";
                cout << "\tReservation name: " << reservation.client_name << "\n";
                cout << "\tCheck in date: " << reservation.check_in << "\n";
                cout << "\tCheck out date: " << reservation.check_out << "\n\n";
                return true;
            }
    return false;
}

void initialiseReservation(vector<Reservation>& reservations) {
    ifstream rin("Reservation.txt");
    if (!rin.is_open()) {
        cout << "\nNo inventory file found. Starting with an empty inventory.\n";
        return;
    }

    string line;
    while (getline(rin, line)) {
        size_t pos;
        Reservation reservation;

        pos = line.find(',');
        reservation.id = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(',');
        reservation.client_name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        reservation.check_in = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        reservation.check_out = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        reservation.room_number = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        reservation.payment = stod(line);

        reservations.push_back(reservation);
    }
    rin.close();
}

void saveReservation(const vector<Reservation>& reservations) {
    rout.close();
    rout.open("Reservation.txt", ios::trunc);
    for (const auto& reservation : reservations) {
        rout << reservation.id << ","
             << reservation.client_name << ","
             << reservation.check_in << ","
             << reservation.check_out << ","
             << reservation.room_number << ","
             << fixed << setprecision(2) << reservation.payment << "\n";
    }
    rout.close();
}

void addReservation(vector<Reservation>& reservations, vector<Camera>& cameras, vector<Profile>& profiles){
    Reservation reservation;
    reservation.id = ReadUntilInt("Enter reservation id: ");
    cout << "Enter client's name: "; getline(cin, reservation.client_name);
    et:
    reservation.room_number = ReadUntilInt("Enter client's room number: ");
    cout << "Enter check-in date (DD.MM.YYYY): "; getline(cin, reservation.check_in);
    cout << "Enter check-out date (DD.MM.YYYY): "; getline(cin, reservation.check_out);
    if (checkOverBook(reservations, reservation.room_number, reservation.check_in, reservation.check_out))
        goto et;
    for (auto& camera : cameras){
        if (reservation.room_number == camera.id){
            reservation.payment = daysDifference(reservation.check_in, reservation.check_out) * camera.price;
            camera.availability += 1;
            saveCamera(cameras);
        }
    }

    bool showed = false;
    for (auto& profile : profiles)
        if (equal_strings(reservation.client_name, profile.name)){
            profile.visits++;
            if (profile.visits <= 3){
                reservation.payment -= reservation.payment * 0.05; // 5% discount
            }
            else if (profile.visits > 3 && profile.visits <= 5){
                reservation.payment -= reservation.payment * 0.1; // 10% discount
            }
            else if (profile.visits > 5){
                reservation.payment -= reservation.payment * 0.15; // 15% discount
            }
            showed = true;
        }

    if (!showed){
        // Add profile
        Profile profile;
        profile.name = reservation.client_name;
        profile.visits++;
        profiles.push_back(profile);
        cout << "\n!! New profile created !!\n";
    }

    reservation.payment = round(reservation.payment * 100) / 100;

    saveProfile(profiles);
    reservations.push_back(reservation);
    saveReservation(reservations);

    cout << "\n!! Reservation successfully added !!\n";
}

void showReservations(const vector<Reservation>& reservations, const vector<Camera>& cameras){
    bool showed = false;
    for (const auto& reservation : reservations) {
        cout << "\nReservation num " << reservation.id << ":\n"
             << "\t" << "Client name: " << reservation.client_name << "\n"
             << "\t" << "Client room number: " << reservation.room_number << "\n"
             << "\t" << "Check-in date: " << reservation.check_in << "\n"
             << "\t" << "Check-out date: " << reservation.check_out << "\n";
        for (const auto& camera : cameras){
            if (reservation.room_number == camera.id) {
                cout << "\t" << "Room type: " << camera.type << "\n";
                continue;
            }
        }
        cout << "\t" << "Reservation cost of stay: " << reservation.payment << "$\n";
        cout << "\t" << reservationStatus(reservation.check_in, reservation.check_out) << "\n";
        showed = true;
    }
    if (!showed) cout << "\n!! No reservations registered yet !!\n";
}

void modifyReservation(vector<Reservation>& reservations, vector<Camera>& cameras, const string& reservation_name, const vector<Profile>& profiles) {
    for (auto& reservation : reservations) {
        if (equal_strings(reservation.client_name, reservation_name)) {
            for (auto& camera : cameras) {
                if (reservation.room_number == camera.id) {
                    camera.availability = 0;
                    reservation.payment = 0;
                }
            }

            reservation.room_number = 0;
            reservation.check_in = "";
            reservation.check_out = "";

            reservation.room_number = ReadUntilInt("Enter client's room number: ");
            cout << "Enter check-in date (DD.MM.YYYY): "; getline(cin, reservation.check_in);
            cout << "Enter check-out date (DD.MM.YYYY): "; getline(cin, reservation.check_out);

            for (auto& camera : cameras) {
                if (reservation.room_number == camera.id) {
                    reservation.payment = daysDifference(reservation.check_in, reservation.check_out) * camera.price;
                    for (auto& profile : profiles)
                        if (equal_strings(reservation.client_name, profile.name)){
                            if (profile.visits <= 3 && profile.visits > 1){
                                reservation.payment -= reservation.payment * 0.05; // 5% discount
                            }
                            else if (profile.visits > 3 && profile.visits <= 5){
                                reservation.payment -= reservation.payment * 0.1; // 10% discount
                            }
                            else if (profile.visits > 5){
                                reservation.payment -= reservation.payment * 0.15; // 15% discount
                            }
                        }
                    camera.availability += 1;
                }
            }

            saveCamera(cameras);
            saveReservation(reservations);
            cout << "\n!! Reservation successfully modified !!\n";
            return;
        }
    }
    cout << "\n!! Reservation not found !!\n";
}

void searchReservation(const vector<Reservation>& reservations, const string& reservation_name,const vector<Camera>& cameras){
    int nr = 0;
    bool showed = false;
    for (const auto& reservation : reservations) {
        if (equal_strings(reservation.client_name, reservation_name)) {
            cout << "\nReservation num " << reservation.id << ":\n"
                 << "\t" << "Client name: " << reservation.client_name << "\n"
                 << "\t" << "Client room number: " << reservation.room_number << "\n"
                 << "\t" << "Check-in date: " << reservation.check_in << "\n"
                 << "\t" << "Check-out date: " << reservation.check_out << "\n";
            for (const auto& camera : cameras){
                if (reservation.room_number == camera.id) {
                    cout << "\t" << "Room type: " << camera.type << "\n";
                }
            }
            cout << "\t" << "Reservation cost of stay: " << reservation.payment << "$\n";
            cout << "\t" << reservationStatus(reservation.check_in, reservation.check_out) << "\n";
            cout << "\n";
            showed = true;
            nr++;
        }
    }
    if (!showed) cout << "\n!! Reservation not found !!\n";
    if (nr > 1) cout << reservation_name << " has " << nr << " reservations\n";
}

void deleteReservation(vector<Reservation>& reservations, const string& reservation_name, vector<Camera>& cameras){
    for (auto it = reservations.begin(); it != reservations.end(); ++it) {
        if (equal_strings(it -> client_name, reservation_name)) {
            for (auto& camera : cameras){
                if (it -> room_number == camera.id){
                    camera.availability -= 1;
                    saveCamera(cameras);
                }
            }
            reservations.erase(it);
            saveReservation(reservations);
            cout << "\n!! Reservation successfully deleted !!\n";
            return;
        }
    }
    cout << "\n!! Reservation not found !!\n";
}

void getReport(const vector<Reservation>& reservations, const vector<Camera>& cameras){
    cout << "\n=== " << hotel_name << " Report ===\n\n";
    double total = 0;
    int occupied = 0;
    for (const auto& reservation : reservations) {
        for (const auto& camera : cameras){
            if (reservation.room_number == camera.id) {
                total += reservation.payment;
            }
        }
    }
    for (const auto& camera : cameras){
        if (camera.availability > 0) occupied +=1;
    }
    cout << "Total income: " << total << "$\n";
    cout << "Number of rooms: " << cameras.size() << '\n';
    cout << "Occupied rooms: " << occupied << endl;
    cout << "Available rooms: " << cameras.size() - occupied << '\n';
    cout << "Number of reservations: " << reservations.size() << '\n';
}

void generateBill(const vector<Reservation>& reservations,const vector<Camera>& cameras, const string& name, const vector<Profile>& profiles){
    ofstream bout("Bill.txt", ios::trunc);
    for (const auto & reservation : reservations){
        if (equal_strings(reservation.client_name, name)){
            bout << "\nThank you for choosing " << hotel_name << "!\n";
            bout << "\nBill for " << reservation.client_name << "\n";
            bout << "\tBooked room type: ";
            double price;
            for (const auto& camera : cameras){
                if (reservation.room_number == camera.id) {
                    bout << camera.type << "\n";
                    price = camera.price;
                }
            }
            bout << "\tNights checked in: " << daysDifference(reservation.check_in, reservation.check_out) << "\n";
            bout << "\tPrice per night: " << price << "$\n\n";
            bout << "Reservation period: " << reservation.check_in << " - " << reservation.check_out << "\n\n";

            for (auto& profile : profiles)
                if (equal_strings(reservation.client_name, profile.name)){
                    if (profile.visits <= 3 && profile.visits > 1){
                        switch(profile.visits){
                            case 2:{
                                bout << "You got a 5% discount for your 2nd visit!\n";
                                break;
                            }
                            case 3:{
                                bout << "You got a 5% discount for your 3rd visit!\n";
                                break;
                            }
                        }
                    }
                    else if (profile.visits > 3 && profile.visits <= 5){
                        bout << "You got a 10% discount for your " << profile.visits << "th visit!\n";
                        break;
                    }
                    else if (profile.visits > 5){
                        bout << "You got a 15% discount for your " << profile.visits << "th visit!\n";
                        break;
                    }
                }

            bout << "Total payment: " << reservation.payment << "$\n";
            bout << "\n\nPlease leave us a review on Google!";
            bout << "\nHope you had a great time!\n";

            cout << "\nBill successfully generated!\n";
            bout.close();
            string filename = {"bill.txt"};
#if defined(_WIN32) || defined(_WIN64)
            string command = "notepad.exe " + filename;
                system(command.c_str());
#elif defined(__linux__)
            string command = "gedit " + filename;
                system(command.c_str());
#elif defined(__APPLE__) && defined(__MACH__)
            string command = "open " + filename;
            system(command.c_str());
#else
            cerr << "Operating system not supported." << std::endl;
                return 1;
#endif
            return;
        }
    }
    cout << "\n!! Reservation not found !!\n";
}

#endif //HOTEL_ROOM_REZERVATION_MANAGER_RESERVATION_H