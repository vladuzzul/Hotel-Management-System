//
// Created by Vlad Cozma on 23.12.2024.
//

#ifndef HOTEL_ROOM_REZERVATION_MANAGER_FUNCTIONS_H
#define HOTEL_ROOM_REZERVATION_MANAGER_FUNCTIONS_H
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

int dateToTimestamp(const std::string& date) {
    tm tm = {};
    istringstream ss(date);
    ss >> get_time(&tm, "%d.%m.%Y");
    if (ss.fail()) {
        cout << "Invalid date provided\n";
    }
    return mktime(&tm);
}

int daysDifference(const std::string& date1, const std::string& date2) {
    int timestamp1 = dateToTimestamp(date1);
    int timestamp2 = dateToTimestamp(date2);
    return abs((timestamp2 - timestamp1) / (60 * 60 * 24));
}

string reservationStatus(const string& check_in, const string& check_out) {
    time_t now = time(nullptr);
    int checkInTimestamp = dateToTimestamp(check_in);
    int checkOutTimestamp = dateToTimestamp(check_out);

    if (checkInTimestamp == -1 || checkOutTimestamp == -1) {
        return "\033[1;31mInvalid date format.\033[0m";
    }

    if (now < checkInTimestamp) {
        int daysUntilCheckIn = (checkInTimestamp - now) / (60 * 60 * 24);
        return "\033[1;90mDays until check-in:\033[0m \033[1;37m" + to_string(daysUntilCheckIn) + " days\033[0m";
    }
    else if (now >= checkInTimestamp && now <= checkOutTimestamp) {
        return "\033[1;37mReservation in progress.\033[0m";
    }
    else {
        int daysSinceCheckOut = (now - checkOutTimestamp) / (60 * 60 * 24);
        return "\033[1;90mDays since check-out:\033[0m \033[1;37m" + to_string(daysSinceCheckOut) + " days\033[0m";
    }
}

double ReadUntilInt(const string& text){
    double num;
    while (true) {
        cout << text;
        cin >> num;
        if (cin.fail()) {
            cout << "Please enter a valid number!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}

bool equal_strings(const string& lhs, const string& rhs){
    if (lhs.size() != rhs.size()){
        return false;
    }

    auto lit = begin(lhs);
    auto rit = begin(rhs);

    while (lit != end(lhs) and rit != end(rhs)){
        if (toupper(*lit) != toupper(*rit)){
            return false;
        }
        ++lit;
        ++rit;
    }
    return true;
}

#endif //HOTEL_ROOM_REZERVATION_MANAGER_FUNCTIONS_H
