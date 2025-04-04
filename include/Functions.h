//
// Created by Vlad Cozma on 23.12.2024.
//

#ifndef HOTEL_ROOM_REZERVATION_MANAGER_FUNCTIONS_H
#define HOTEL_ROOM_REZERVATION_MANAGER_FUNCTIONS_H
#include <sstream>
#include <iomanip>
#include <iostream>

int dateToTimestamp(const std::string& date) {
    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%d.%m.%Y");
    if (ss.fail()) {
        std::cout << "Invalid date provided\n";
    }
    return std::mktime(&tm);
}

int daysDifference(const std::string& date1, const std::string& date2) {
    int timestamp1 = dateToTimestamp(date1);
    int timestamp2 = dateToTimestamp(date2);
    return std::abs((timestamp2 - timestamp1) / (60 * 60 * 24));
}

std::string reservationStatus(const std::string& check_in, const std::string& check_out) {
    std::time_t now = std::time(nullptr);
    int checkInTimestamp = dateToTimestamp(check_in);
    int checkOutTimestamp = dateToTimestamp(check_out);

    if (checkInTimestamp == -1 || checkOutTimestamp == -1) {
        return "\033[1;31mInvalid date format.\033[0m";
    }

    if (now < checkInTimestamp) {
        int daysUntilCheckIn = (checkInTimestamp - now) / (60 * 60 * 24);
        return "\033[1;90mDays until check-in:\033[0m \033[1;37m" + std::to_string(daysUntilCheckIn) + " days\033[0m";
    } else if (now >= checkInTimestamp && now <= checkOutTimestamp) {
        return "\033[1;37mReservation in progress.\033[0m";
    } else {
        int daysSinceCheckOut = (now - checkOutTimestamp) / (60 * 60 * 24);
        return "\033[1;90mDays since check-out:\033[0m \033[1;37m" + std::to_string(daysSinceCheckOut) + " days\033[0m";
    }
}

double ReadUntilInt(const std::string& text){
    double num;
    while (true) {
        std::cout << text;
        std::cin >> num;
        if (std::cin.fail()) {
            std::cout << "Please enter a valid number!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return num;
        }
    }
}

bool equal_strings(const std::string& lhs, const std::string& rhs){
    if (lhs.size() != rhs.size()){
        return false;
    }

    auto lit = std::begin(lhs);
    auto rit = std::begin(rhs);

    while (lit != std::end(lhs) and rit != std::end(rhs)){
        if (std::toupper(*lit) != std::toupper(*rit)){
            return false;
        }
        ++lit;
        ++rit;
    }
    return true;
}

#endif //HOTEL_ROOM_REZERVATION_MANAGER_FUNCTIONS_H
