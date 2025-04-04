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
    std::ifstream settings("Settings.txt");
    if (settings.is_open()) {
        std::getline(settings, hotel_name);
        if (hotel_name.rfind("Hotel Name: ", 0) == 0) {
            hotel_name = hotel_name.substr(12); // Remove "Hotel Name: " prefix
        } else {
            hotel_name = "Your hotel's";
        }
        settings.close();
    } else {
        hotel_name = "Your hotel's";
        std::cout << "\n\033[1;31mError: Unable to load settings from file. Using default hotel name.\033[0m\n";
    }
}

void ChangeSettings(std::string& hotel_name) {
    std::cout << "\n\033[1;90mCurrent hotel name: \033[0m\033[1;37m" << hotel_name << "\033[0m\n";
    std::cout << "\033[1;90mEnter new hotel name: \033[0m";
    std::getline(std::cin, hotel_name);
    std::cout << "\n\033[1;32mHotel name successfully changed to " << hotel_name << "\033[0m\n";
    std::cout << "\n\033[1;90mSettings saved successfully!\033[0m\n";

    std::ofstream settings("Settings.txt");
    if (settings.is_open()) {
        settings << "Hotel Name: " << hotel_name << std::endl;
        settings.close();
    } else {
        std::cout << "\n\033[1;31mError: Unable to save settings to file.\033[0m\n";
    }
}

#endif // HOTEL_ROOM_REZERVATION_MANAGER_SETTINGS_H