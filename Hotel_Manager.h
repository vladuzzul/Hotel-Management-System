//
// Created by Vlad Cozma on 13.12.2024.
//

#ifndef HOTEL_ROOM_REZERVATION_MANAGER_HOTEL_MANAGER_H
#define HOTEL_ROOM_REZERVATION_MANAGER_HOTEL_MANAGER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Functions.h"
using namespace std;

string hotel_name {"Your hotel's"};

ofstream camout("Camera.txt", ios::app);
ofstream rout("Reservation.txt", ios::app);
ofstream pout("Client_profile.txt", ios::app);

class Camera{
public:
    int id;
    double price;
    string type;
    int availability = 0;
};

class Reservation{
public:
    int id;
    string client_name;
    string check_in;
    string check_out;
    int room_number;
};

// Introducing a new feature to see all
// the clients that booked a reservation

class Profile{
public:
    string name;
    int visits = 0;
};

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

void initialiseProfile(vector<Profile>& profiles){
    ifstream pin("Client_profile.txt");
    if(!pin.is_open()){
        cout << "No profile file found. Starting with a empty profile database. \n";
        return;
    }

    string line;
    while(getline(pin, line)){
        size_t pos;
        Profile profile;

        pos = line.find(',');
        profile.name = line.substr(0, pos);
        line.erase(0, pos+1);

        profile.visits += stoi(line);
        profiles.push_back(profile);
    }
}

void saveProfile(const vector<Profile>& profiles){
    pout.close();
    pout.open("Client_profile.txt", ios::trunc);

    for (const auto& profile : profiles)
        pout << profile.name << "," << profile.visits << '\n';
}

void showProfiles(const vector<Profile>& profiles){
    bool showed = false;
    for (auto& profile : profiles){
        cout << "Profile " << profile.name << " has a number of " << profile.visits << " reservations.\n";
        showed = true;
    }
    if (!showed)
        cout << "\n!! No profiles registered yet !!\n";
}

void modifyProfile(vector<Profile>& profiles, const string& name){
    bool showed = false;
    for (auto& profile : profiles){
        if (equal_strings(profile.name, name)){
            cout << "Current number of visits: " << profile.visits << '\n';
            cout << "Enter number of visits: "; cin >> profile.visits;
        }
        showed = true;
    }
    if (!showed)
        cout << "\n!! No profiles registered yet !!\n";
}

void searchProfile(const vector<Profile>& profiles, const string& name){
    bool showed = false;
    for (const auto& profile : profiles) {
        if (equal_strings(profile.name, name)){
            cout << "Profile " << profile.name << " has a number of " << profile.visits << " reservations.\n";
        }
        showed = true;
    }
    if (!showed) cout << "\n!! Room not found !!\n";
}

void deleteProfile(vector<Profile>& profiles, const string& name){
    for (auto it = profiles.begin(); it != profiles.end(); ++it) {
        if (equal_strings(it -> name, name)){
            profiles.erase(it);
            saveProfile(profiles);
            cout << "\nProfile successfully deleted!\n";
            return;
        }
    }
    cout << "\n!! Profile not found !!\n";
}

void initialiseCamera(vector<Camera>& cameras) {
    ifstream camin("Camera.txt");
    if (!camin.is_open()) {
        cout << "No inventory file found. Starting with an empty inventory.\n";
        return;
    }

    string line;
    while (getline(camin, line)) {
        size_t pos;
        Camera camera;

        pos = line.find(',');
        camera.id = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(',');
        camera.price = stod(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(',');
        camera.type = line.substr(0, pos);
        line.erase(0, pos + 1);

        camera.availability += stoi(line);

        cameras.push_back(camera);
    }
    camin.close();
}

void saveCamera(const vector<Camera>& cameras) {
    camout.close();
    camout.open("Camera.txt", ios::trunc);
    for (const auto& camera : cameras) {
        camout << camera.id << ","
               << fixed << setprecision(2) << camera.price << ","
               << camera.type << ","
               << camera.availability << "\n";
    }
    camout.close();
}

void addCamera(vector<Camera>& cameras){
    Camera camera;
    cout << "Enter room id: "; cin >> camera.id;
    cout << "Enter room price: "; cin >> camera.price;
    cin.ignore();
    cout << "Enter room type: "; getline(cin, camera.type);
    camera.availability = 0;
    cameras.push_back(camera);
    saveCamera(cameras);
    cout << "\n!! Room successfully added !!\n";
}

void showCameras(const vector<Camera>& cameras,const vector<Reservation>& reservations) {
    bool showed = false;
    for (const auto &camera: cameras) {
        cout << "\nRoom number " << camera.id << ":\n"
             << "\t" << "Room price per night: " << camera.price << "$\n"
             << "\t" << "Room type: " << camera.type << "\n"
             << "\t" << "Room availability: ";
        if (camera.availability == 0) cout << "available\n";
        else {
            cout << "not available\n";
            for (const auto &reservation: reservations) {
                if (reservation.room_number == camera.id) {
                    cout << "\tRoom occupied by: " << reservation.client_name << "\n";
                }
            }
        }
        showed = true;
    }
    if (!showed) cout << "\n!! No rooms registered yet !!\n";
}

void showAvailableCameras(const vector<Camera>& cameras){
    bool showed = false;
    for (const auto& camera : cameras) {
        if (camera.availability == 0){
            cout << "\nRoom number " << camera.id << ":\n"
                 << "\t" << "Room price per night: " << camera.price << "$\n"
                 << "\t" << "Room type: " << camera.type << "\n";
            showed = true;
        }

    }
    if (!showed) cout << "No rooms available\n";
}

void searchCamera(const vector<Camera>& cameras, const int& camera_id, const vector<Reservation>& reservations){
    bool showed = false;
    for (const auto& camera : cameras) {
        if (camera.id == camera_id) {
            cout << "\nRoom number " << camera.id << ":\n"
                 << "\t" << "Room price per night: " << camera.price << "$\n"
                 << "\t" << "Room type: " << camera.type << "\n"
                 << "\t" << "Room availability: ";
            if (camera.availability == 0) cout << "available\n";
            else {
                cout << "not available\n";
                for (const auto& reservation : reservations){
                    if (reservation.room_number == camera.id){
                        cout << "\tRoom occupied by: " << reservation.client_name << "\n";
                    }
                }
            }
            cout << "\n";
            showed = true;
        }
    }
    if (!showed) cout << "\n!! Room not found !!\n";
}

void deleteCamera(vector<Camera> &cameras, const int& camera_id){
    for (auto it = cameras.begin(); it != cameras.end(); ++it) {
        if (it -> id == camera_id) {
            cameras.erase(it);
            saveCamera(cameras);
            cout << "\nRoom successfully deleted!\n";
            return;
        }
    }
    cout << "\n!! Room not found !!\n";
}

void modifyCameraPrice(vector<Camera>& cameras,const int& id){
    for (auto& camera : cameras){
        if (camera.id == id){
            camera.price = 0;
            cout << "Enter new price: "; cin >> camera.price;
            saveCamera(cameras);
            cout << "\n!! Room price successfully modified !!\n";
            return;
        }
    }
    cout << "\n!! Room not found !!\n";
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

        reservation.room_number = stoi(line);

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
               << reservation.room_number << "\n";
    }
    rout.close();
}

void addReservation(vector<Reservation>& reservations, vector<Camera>& cameras, vector<Profile>& profiles){
    Reservation reservation;
    cout << "Enter reservation id: "; cin >> reservation.id;
    cin.ignore();
    cout << "Enter client's name: "; getline(cin, reservation.client_name);
    et:
    cout << "Enter client's room number: "; cin >> reservation.room_number;
    cin.ignore();
    cout << "Enter check-in date (DD.MM.YYYY): "; getline(cin, reservation.check_in);
    cout << "Enter check-out date (DD.MM.YYYY): "; getline(cin, reservation.check_out);
    if (checkOverBook(reservations, reservation.room_number, reservation.check_in, reservation.check_out))
        goto et;
    for (auto& camera : cameras){
        if (reservation.room_number == camera.id){
            camera.availability += 1;
            saveCamera(cameras);
        }
    }

    bool showed = false;
    for (auto& profile : profiles)
        if (equal_strings(reservation.client_name, profile.name)){
            profile.visits += 1;
            showed = true;
        }

    if (!showed){
        // Add profile
        Profile profile;
        profile.name = reservation.client_name;
        profile.visits++;
        profiles.push_back(profile);
        saveProfile(profiles);
        cout << "\n!! New profile created !!\n";
    }

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
                double payment = daysDifference(reservation.check_in, reservation.check_out) * camera.price;
                cout << "\t" << "Reservation cost of stay: " << payment << "$\n";
                continue;
            }
        }
        cout << "\t" << reservationStatus(reservation.check_in, reservation.check_out) << "\n";
        showed = true;
    }
    if (!showed) cout << "\n!! No reservations registered yet !!\n";
}

void modifyReservation(vector<Reservation>& reservations, vector<Camera>& cameras, const string& reservation_name) {
    for (auto& reservation : reservations) {
        if (equal_strings(reservation.client_name, reservation_name)) {
            for (auto& camera : cameras) {
                if (reservation.room_number == camera.id) {
                    camera.availability = 0;
                }
            }

            reservation.room_number = 0;
            reservation.check_in = "";
            reservation.check_out = "";

            cout << "Enter client's room number: "; cin >> reservation.room_number;
            cin.ignore();
            cout << "Enter check-in date (DD.MM.YYYY): "; getline(cin, reservation.check_in);
            cout << "Enter check-out date (DD.MM.YYYY): "; getline(cin, reservation.check_out);

            for (auto& camera : cameras) {
                if (reservation.room_number == camera.id) {
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
                    double payment = daysDifference(reservation.check_in, reservation.check_out) * camera.price;
                    cout << "\t" << "Reservation cost of stay: " << payment << "$\n";
                }
            }
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
                double payment = daysDifference(reservation.check_in, reservation.check_out) * camera.price;
                total += payment;
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

void generateBill(const vector<Reservation>& reservations,const vector<Camera>& cameras, const string& name){
    ofstream bout("Bill.txt", ios::trunc);
    for (const auto & reservation : reservations){
        if (equal_strings(reservation.client_name, name)){
            bout << "\nThank you for choosing " << hotel_name << "!\n";
            bout << "\nBill for " << reservation.client_name << "\n";
            bout << "\tBooked room type: ";
            double price, payment;
            for (const auto& camera : cameras){
                if (reservation.room_number == camera.id) {
                    bout << camera.type << "\n";
                    price = camera.price;
                    payment = daysDifference(reservation.check_in, reservation.check_out) * camera.price;
                }
            }
            bout << "\tNights checked in: " << daysDifference(reservation.check_in, reservation.check_out) << "\n";
            bout << "\tPrice per night: " << price << "$\n";
            bout << "\nTotal payment: " << payment << "$\n";
            bout << "\n\nPlease leave us a review on Google!";
            bout << "\nHope you had a great time!\n";

            cout << "\nBill successfully generated!\n";
            bout.close();
            return;
        }
    }
    cout << "\n!! Reservation not found !!\n";
}

#endif //HOTEL_ROOM_REZERVATION_MANAGER_HOTEL_MANAGER_H