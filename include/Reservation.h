//
// Created by Vlad Cozma on 27.12.2024.
//

#ifndef HOTEL_ROOM_REZERVATION_MANAGER_RESERVATION_H
#define HOTEL_ROOM_REZERVATION_MANAGER_RESERVATION_H
#include "Classes.h"
#include "Profile.h"
#include "Camera.h"
#include "Settings.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

std::ofstream rout("Reservation.txt", std::ios::app);

bool checkOverBook(const std::vector<Reservation>& reservations, int roomNum, const std::string& check_in, const std::string& check_out) {
    for (const auto& reservation : reservations)
        if (reservation.room_number == roomNum)
            if (check_in < reservation.check_out && check_out > reservation.check_in) {
                std::cout << "\nOverbooked with reservation number " << reservation.id << "\n";
                std::cout << "\tReservation name: " << reservation.client_name << "\n";
                std::cout << "\tCheck in date: " << reservation.check_in << "\n";
                std::cout << "\tCheck out date: " << reservation.check_out << "\n\n";
                return true;
            }
    return false;
}

void initialiseReservation(std::vector<Reservation>& reservations) {
    std::ifstream rin("Reservation.txt");
    if (!rin.is_open()) {
        std::cout << "\nNo inventory file found. Starting with an empty inventory.\n";
        return;
    }

    std::string line;
    while (std::getline(rin, line)) {
        size_t pos;
        Reservation reservation;

        pos = line.find(',');
        reservation.id = std::stoi(line.substr(0, pos));
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
        reservation.room_number = std::stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        reservation.payment = std::stod(line);

        reservations.push_back(reservation);
    }
    rin.close();
}

void saveReservation(const std::vector<Reservation>& reservations) {
    rout.close();
    rout.open("Reservation.txt", std::ios::trunc);
    for (const auto& reservation : reservations) {
        rout << reservation.id << ","
             << reservation.client_name << ","
             << reservation.check_in << ","
             << reservation.check_out << ","
             << reservation.room_number << ","
             << std::fixed << std::setprecision(2) << reservation.payment << "\n";
    }
    rout.close();
}

void addReservation(std::vector<Reservation>& reservations, std::vector<Camera>& cameras, std::vector<Profile>& profiles){
    Reservation reservation;
    if (!cameras.empty()){
        reservation.id = ReadUntilInt("\033[1;37mEnter reservation id: \033[0m");
        std::cout << "\033[1;37mEnter client's name: \033[0m"; std::getline(std::cin, reservation.client_name);
        et:
        reservation.room_number = ReadUntilInt("\033[1;37mEnter client's room number: \033[0m");
        bool found = false;
        if (reservation.room_number == -1) return;
        for (const auto& camera : cameras){
            if (reservation.room_number == camera.id) {
                found = true;
            }
        }
        if (!found) {
            std::cout << "\033[1;31m!! Room not found !!\033[93m\nPress -1 to go back\033[0m\n";
            goto et;
        }
        std::cout << "\033[1;37mEnter check-in date (DD.MM.YYYY): \033[0m"; std::getline(std::cin, reservation.check_in);
        std::cout << "\033[1;37mEnter check-out date (DD.MM.YYYY): \033[0m"; std::getline(std::cin, reservation.check_out);
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
            std::cout << "\n!! New profile created !!\n";
        }

        reservation.payment = std::round(reservation.payment * 100) / 100;

        saveProfile(profiles);
        reservations.push_back(reservation);
        saveReservation(reservations);

        std::cout << "\n!! Reservation successfully added !!\n";
    }
    else{
        std::cout << "\n\033[1;31m!! Reservations cannot be made without rooms !!\033[0m\n";
        ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
    }
    
}

void showReservations(const std::vector<Reservation>& reservations, const std::vector<Camera>& cameras){
    bool showed = false;
    for (const auto& reservation : reservations) {
        std::cout << "\n\033[1;34mReservation num " << reservation.id << ":\033[0m\n"
             << "\t\033[1;90m" << "Client name:\033[0m \033[1;37m" << reservation.client_name << "\033[0m\n"
             << "\t\033[1;90m" << "Client room number:\033[0m \033[1;37m" << reservation.room_number << "\033[0m\n"
             << "\t\033[1;90m" << "Check-in date:\033[0m \033[1;37m" << reservation.check_in << "\033[0m\n"
             << "\t\033[1;90m" << "Check-out date:\033[0m \033[1;37m" << reservation.check_out << "\033[0m\n";
        for (const auto& camera : cameras){
            if (reservation.room_number == camera.id) {
                std::cout << "\t" << "\033[1;90mRoom type:\033[0m \033[1;37m" << camera.type << "\033[0m\n";
                continue;
            }
        }
        std::cout << "\t" << "\033[1;90mReservation cost of stay:\033[0m \033[1;37m" << reservation.payment << "$\033[0m\n";
        std::cout << "\t" << reservationStatus(reservation.check_in, reservation.check_out) << "\n";
        showed = true;
    }
    if (!showed) std::cout << "\n\033[1;31m!! No reservations registered yet !!\033[0m\n";
}

void modifyReservation(std::vector<Reservation>& reservations, std::vector<Camera>& cameras, const std::string& reservation_name, const std::vector<Profile>& profiles) {
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

            reservation.room_number = ReadUntilInt("\033[1;37mEnter client's room number: \033[0m");
            std::cout << "\033[1;37mEnter check-in date (DD.MM.YYYY): \033[0m"; std::getline(std::cin, reservation.check_in);
            std::cout << "\033[1;37mEnter check-out date (DD.MM.YYYY): \033[0m"; std::getline(std::cin, reservation.check_out);

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
            std::cout << "\n!! Reservation successfully modified !!\n";
            return;
        }
    }
    std::cout << "\n!! Reservation not found !!\n";
}

void searchReservation(const std::vector<Reservation>& reservations, const std::string& reservation_name,const std::vector<Camera>& cameras){
    int nr = 0;
    bool showed = false;
    for (const auto& reservation : reservations) {
        if (equal_strings(reservation.client_name, reservation_name)) {
            std::cout << "\n\033[1;34mReservation num " << reservation.id << ":\033[0m\n"
                 << "\t\033[1;90m" << "Client name:\033[0m \033[1;37m" << reservation.client_name << "\033[0m\n"
                 << "\t\033[1;90m" << "Client room number:\033[0m \033[1;37m" << reservation.room_number << "\033[0m\n"
                 << "\t\033[1;90m" << "Check-in date:\033[0m \033[1;37m" << reservation.check_in << "\033[0m\n"
                 << "\t\033[1;90m" << "Check-out date:\033[0m \033[1;37m" << reservation.check_out << "\033[0m\n";
            for (const auto& camera : cameras){
                if (reservation.room_number == camera.id) {
                    std::cout << "\t" << "\033[1;90mRoom type:\033[0m \033[1;37m" << camera.type << "\033[0m\n";
                    continue;
                }
            }
            std::cout << "\t" << "\033[1;90mReservation cost of stay:\033[0m \033[1;37m" << reservation.payment << "$\033[0m\n";
            std::cout << "\t" << reservationStatus(reservation.check_in, reservation.check_out) << "\n";
            showed = true;
            nr++;
        }
    }
    if (!showed) std::cout << "\n\033[1;31m!! Reservation not found !!\033[0m\n";
    if (nr > 1) std::cout << reservation_name << " has " << nr << " reservations\n";
}

void deleteReservation(std::vector<Reservation>& reservations, const std::string& reservation_name, std::vector<Camera>& cameras){
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
            std::cout << "\n!! Reservation successfully deleted !!\n";
            return;
        }
    }
    std::cout << "\n!! Reservation not found !!\n";
}

void getReport(const std::vector<Reservation>& reservations, const std::vector<Camera>& cameras) {
    double total = 0;
    int occupied = 0;

    // Calculate total income and occupied rooms
    for (const auto& reservation : reservations) {
        for (const auto& camera : cameras) {
            if (reservation.room_number == camera.id) {
                total += reservation.payment;
            }
        }
    }
    for (const auto& camera : cameras) {
        if (camera.availability > 0) occupied += 1;
    }

    
    std::string title = hotel_name;
    int totalWidth = 40-15; // -15 is for " Report Summary"
    int padding = (totalWidth - title.length()) / 2;
    if (padding < 0) padding = 0;

    std::cout << "========================================\n";
    std::cout << std::string(padding, ' ') << "\033[1;34m" << hotel_name << " Report Summary\033[0m\n";
    std::cout << "========================================\n\n";
    std::cout << "\033[1;90mTotal income:\033[1;37m " << total << "$\033[0m\n";
    std::cout << "\033[1;90mNumber of rooms:\033[1;37m " << cameras.size() << "\033[0m\n";
    std::cout << "\033[1;90mOccupied rooms:\033[1;37m " << occupied << "\033[0m\n";
    std::cout << "\033[1;90mAvailable rooms:\033[1;37m " << cameras.size() - occupied << "\033[0m\n";
    std::cout << "\033[1;90mNumber of reservations:\033[1;37m " << reservations.size() << "\033[0m\n";
    std::cout << "\n========================================\n";
}

void generateBill(const std::vector<Reservation>& reservations,const std::vector<Camera>& cameras, const std::string& name, const std::vector<Profile>& profiles){
    std::ofstream bout("Bill.txt", std::ios::trunc);
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

            std::cout << "\nBill successfully generated!\n";
            bout.close();
            std::string filename = "bill.txt";
#if defined(_WIN32) || defined(_WIN64)
            std::string command = "notepad.exe " + filename;
                system(command.c_str());
#elif defined(__linux__)
            std::string command = "gedit " + filename;
                system(command.c_str());
#elif defined(__APPLE__) && defined(__MACH__)
            std::string command = "open " + filename;
            system(command.c_str());
#else
            std::cerr << "Operating system not supported." << std::endl;
                return 1;
#endif
            return;
        }
    }
    std::cout << "\n!! Reservation not found !!\n";
}

#endif //HOTEL_ROOM_REZERVATION_MANAGER_RESERVATION_H