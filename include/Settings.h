// 
// Created by Cozma Vlad on 04.04.2025.
//

#ifndef HOTEL_ROOM_REZERVATION_MANAGER_SETTINGS_H
#define HOTEL_ROOM_REZERVATION_MANAGER_SETTINGS_H
#include <string>
#include <iostream>
#include <fstream>

std::string hotel_name;

void LoadSettings() {
    std::ifstream settings("database/Settings.txt");
    if (!settings.is_open()) {
        std::ofstream newFile("database/Settings.txt");
        newFile.close();
        std::cout << "\nNo settings file found. Starting with default settings.\n";
        hotel_name = "Your hotel's";
        return;
    }
    else {
        std::getline(settings, hotel_name);
        if (hotel_name.rfind("Hotel Name: ", 0) == 0) {
            hotel_name = hotel_name.substr(12); // Remove "Hotel Name: " prefix
        } else {
            hotel_name = "Your hotel's";
        }
        settings.close();
    }
}

void ChangeSettings(std::string& hotel_name) {
    std::cout << "\n\033[1;90mCurrent hotel name: \033[0m\033[1;37m" << hotel_name << "\033[0m\n";
    std::cout << "\033[1;90mEnter new hotel name: \033[0m";
    std::getline(std::cin, hotel_name);
    std::cout << "\n\033[1;32mHotel name successfully changed to " << hotel_name << "\033[0m\n";
    std::cout << "\n\033[1;90mSettings saved successfully!\033[0m\n";

    std::ofstream settings("database/Settings.txt");
    if (settings.is_open()) {
        settings << "Hotel Name: " << hotel_name << std::endl;
        settings.close();
    } else {
        std::cout << "\n\033[1;31mError: Unable to save settings to file.\033[0m\n";
    }
}

void resetDatabase(int& iChoice) {
    std::cout << "\n\033[1;90mAre you sure you want to reset the database? (y/n): \033[0m";
    char choice;
    std::cin >> choice;
    if (choice != 'y' && choice != 'Y') {
        std::cout << "\n\033[1;31mDatabase reset cancelled.\033[0m\n";
        iChoice = 0;
        return;
    }
    std::cout << "\n";
    DeleteFile("Employee.txt");
    DeleteFile("Camera.txt");
    DeleteFile("Reservation.txt");
    DeleteFile("Client_profile.txt");
    DeleteFile("Bill.txt");
    DeleteFile("Settings.txt");
    std::cout << "\n\033[1;32mDatabase reset successfully!\033[0m\n";
    return;
}

#endif // HOTEL_ROOM_REZERVATION_MANAGER_SETTINGS_H