//
// Created by Vlad Cozma on 27.12.2024.
//

#ifndef HOTEL_ROOM_REZERVATION_MANAGER_CLASSES_H
#define HOTEL_ROOM_REZERVATION_MANAGER_CLASSES_H
#include <string>
using namespace std;

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
    double payment;
};

class Profile{
public:
    string name;
    int visits = 0;
};

#endif //HOTEL_ROOM_REZERVATION_MANAGER_CLASSES_H
