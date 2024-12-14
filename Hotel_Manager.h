//
// Created by Vlad Cozma on 13.12.2024.
//

#ifndef HOTEL_ROOM_REZERVATION_MANAGER_HOTEL_MANAGER_H
#define HOTEL_ROOM_REZERVATION_MANAGER_HOTEL_MANAGER_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

string hotel_name {"Your hotel's"};

ofstream camout("Camera.txt", ios::app);
ofstream rout("Reservation.txt", ios::app);

int dateToTimestamp(const std::string& date) {
    tm tm = {};
    istringstream ss(date);
    ss >> get_time(&tm, "%d.%m.%Y");
    if (ss.fail()) {
        cout << "Invalid date provided"
    }
    return

    mktime(&tm);
}

int daysDifference(const std::string& date1, const std::string& date2) {
    int timestamp1 = dateToTimestamp(date1);
    int timestamp2 = dateToTimestamp(date2);
    return abs((timestamp2 - timestamp1) / (60 * 60 * 24));
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

void initialiseCamera(vector<Camera>& cameras) {
    ifstream camin("Camera.txt");
    if (!camin.is_open()) {
        cout << "No inventory file found. Starting with an empty inventory.\n";
        return;
    }

    string line;
    while (getline(camin, line)) {
        size_t pos = 0;
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
    cout << "Enter camera id: "; cin >> camera.id;
    cout << "Enter camera price: "; cin >> camera.price;
    cin.ignore();
    cout << "Enter camera type: "; getline(cin, camera.type);
    camera.availability = 0;
    cameras.push_back(camera);
    saveCamera(cameras);
    cout << "\n!! Camera successfully added !!\n";
}

void showCameras(vector<Camera> cameras, vector<Reservation> reservations){
    bool showed = false;
    for (const auto& camera : cameras) {
        cout << "\nCamera number " << camera.id << ":\n"
             << "\t" << "Camera price per night: " << camera.price << "$\n"
             << "\t" << "Camera type: " << camera.type << "\n"
             << "\t" << "Camera availability: ";
        if (camera.availability == 0) cout << "available\n";
        else {
            cout << "not available\n";
            for (const auto& reservation : reservations){
                if (reservation.room_number == camera.id){
                    cout << "\tRoom occupied by: " << reservation.client_name << "\n";
                }
            }
        }
        showed = true;
    }
    if (!showed) cout << "\n!! No cameras registered yet !!\n";
}

void searchCamera(const vector<Camera>& cameras, const int& camera_id, const vector<Reservation>& reservations){
    bool showed = false;
    for (const auto& camera : cameras) {
        if (camera.id == camera_id) {
            cout << "\nCamera number " << camera.id << ":\n"
                 << "\t" << "Camera price per night: " << camera.price << "$\n"
                 << "\t" << "Camera type: " << camera.type << "\n"
                 << "\t" << "Camera availability: ";
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
    if (!showed) cout << "\n!! Camera not found !!\n";
}

void deleteCamera(vector<Camera> &cameras, const int& camera_id){
    for (auto it = cameras.begin(); it != cameras.end(); ++it) {
        if (it -> id == camera_id) {
            cameras.erase(it);
            saveCamera(cameras);
            cout << "\nCamera successfully deleted!\n";
            return;
        }
    }
    cout << "\n!! Camera not found !!\n";
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

void addReservation(vector<Reservation>& reservations, vector<Camera>& cameras){
    Reservation reservation;
    cout << "Enter reservation id: "; cin >> reservation.id;
    cin.ignore();
    cout << "Enter client's name: "; getline(cin, reservation.client_name);
    cout << "Enter client's room number: "; cin >> reservation.room_number;
    cin.ignore();
    cout << "Enter check-in date (DD.MM.YYYY): "; getline(cin, reservation.check_in);
    cout << "Enter check-out date (DD.MM.YYYY): "; getline(cin, reservation.check_out);
    for (auto& camera : cameras){
        if (reservation.room_number == camera.id){
            camera.availability += 1;
            saveCamera(cameras);
        }
    }
    reservations.push_back(reservation);
    saveReservation(reservations);
    cout << "\n!! Reservation successfully added !!\n";
}

void showReservations(vector<Reservation> reservations, vector<Camera> cameras){
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
            }
        }
        showed = true;
    }
    if (!showed) cout << "\n!! No reservations registered yet !!\n";
}

void searchReservation(const vector<Reservation>& reservations, const string& reservation_name, vector<Camera> cameras){
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
            cout << "\n";
            showed = true;
            nr++;
        }
    }
    if (!showed) cout << "\n!! Registration not found !!\n";
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

#endif //HOTEL_ROOM_REZERVATION_MANAGER_HOTEL_MANAGER_H