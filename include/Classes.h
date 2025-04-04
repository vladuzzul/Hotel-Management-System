//
// Created by Vlad Cozma on 27.12.2024.
//

#ifndef HOTEL_ROOM_REZERVATION_MANAGER_CLASSES_H
#define HOTEL_ROOM_REZERVATION_MANAGER_CLASSES_H
#include <string>

class Camera {
public:
    int id;
    double price;
    std::string type;
    int availability = 0;
};

class Reservation {
public:
    int id;
    std::string client_name;
    std::string check_in;
    std::string check_out;
    int room_number;
    double payment;
};

class Profile {
public:
    std::string name;
    int visits = 0;
};

#endif //HOTEL_ROOM_REZERVATION_MANAGER_CLASSES_H
