//
// Created by Vlad Cozma on 23.12.2024.
//

#ifndef HOTEL_ROOM_REZERVATION_MANAGER_FUNCTIONS_H
#define HOTEL_ROOM_REZERVATION_MANAGER_FUNCTIONS_H
#include <sstream>
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
        return "Invalid date format.";
    }

    if (now < checkInTimestamp) {
        int daysUntilCheckIn = (checkInTimestamp - now) / (60 * 60 * 24);
        return "Days until check-in: " + to_string(daysUntilCheckIn) + " days";
    }
    else if (now >= checkInTimestamp && now <= checkOutTimestamp) {
        return "Reservation in progress.";
    }
    else {
        int daysSinceCheckOut = (now - checkOutTimestamp) / (60 * 60 * 24);
        return "Days since check-out: " + to_string(daysSinceCheckOut) + " days";
    }
}

bool equal_strings(const string& lhs, const string& rhs){
    if (lhs.size() != rhs.size()){
        return false;
    }

    auto lit = cbegin(lhs);
    auto rit = cbegin(rhs);

    while (lit != cend(lhs) and rit != cend(rhs)){
        if (toupper(*lit) != toupper(*rit)){
            return false;
        }
        ++lit;
        ++rit;
    }
    return true;
}

#endif //HOTEL_ROOM_REZERVATION_MANAGER_FUNCTIONS_H
