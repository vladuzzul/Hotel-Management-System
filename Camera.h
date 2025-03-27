//
// Created by Vlad Cozma on 27.12.2024.
//

#ifndef HOTEL_ROOM_REZERVATION_MANAGER_CAMERA_H
#define HOTEL_ROOM_REZERVATION_MANAGER_CAMERA_H
#include "Functions.h"
#include "Classes.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

ofstream camout("Camera.txt", ios::app);

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
    camera.id = ReadUntilInt("\033[1;37mEnter room id: \033[0m");
    camera.price = ReadUntilInt("\033[1;37mEnter room price: \033[0m");
    cout << "\033[1;37mEnter room type: \033[0m"; getline(cin, camera.type);
    camera.availability = 0;
    cameras.push_back(camera);
    saveCamera(cameras);
    cout << "\n\033[1;37m!! Room successfully added !!\033[0m\n";
}

void showCameras(const vector<Camera>& cameras,const vector<Reservation>& reservations) {
    bool showed = false;
    for (const auto &camera: cameras) {
        cout << "\n\033[1;34mRoom number " << camera.id << ":\033[0m\n"
            << "\t\033[1;90mRoom price per night:\033[0m \033[1;37m" << camera.price << "$\033[0m\n"
             << "\t\033[1;90mRoom type:\033[0m \033[1;37m" << camera.type << "\033[0m\n"
             << "\t\033[1;90mRoom availability:\033[0m \033[1;37m";
        if (camera.availability == 0) cout << "available\033[0m\n";
        else {
            cout << "not available\033[0m\n";
            for (const auto &reservation: reservations) {
                if (reservation.room_number == camera.id) {
                    cout << "\033[0m\t\033[1;90mRoom booked by:\033[0m \033[1;37m" << reservation.client_name << "\033[0m\n";
                }
            }
        }
        showed = true;
    }
    if (!showed) cout << "\n\033[1;31m!! No rooms registered yet !!\033[0m\n";
}

void showAvailableCameras(const vector<Camera>& cameras){
    bool showed = false;
    for (const auto& camera : cameras) {
        if (camera.availability == 0){
            cout << "\n\033[1;34mRoom number " << camera.id << ":\033[0m\n"
            << "\t\033[1;90mRoom price per night:\033[0m \033[1;37m" << camera.price << "$\033[0m\n"
             << "\t\033[1;90mRoom type:\033[0m \033[1;37m" << camera.type << "\033[0m\n";
            showed = true;
        }

    }
    if (!showed) cout << "\033[1;91m!! No rooms available !!\033[0m\n";
}

void searchCamera(const vector<Camera>& cameras, const int& camera_id, const vector<Reservation>& reservations){
    bool showed = false;
    for (const auto& camera : cameras) {
        if (camera.id == camera_id) {
            cout << "\n\033[1;34mRoom number " << camera.id << ":\033[0m\n"
            << "\t\033[1;90mRoom price per night:\033[0m \033[1;37m" << camera.price << "$\033[0m\n"
             << "\t\033[1;90mRoom type:\033[0m \033[1;37m" << camera.type << "\033[0m\n"
             << "\t\033[1;90mRoom availability:\033[0m \033[1;37m";
        if (camera.availability == 0) cout << "available\033[0m\n";
        else {
            cout << "not available\033[0m\n";
            for (const auto &reservation: reservations) {
                if (reservation.room_number == camera.id) {
                    cout << "\033[0m\t\033[1;90mRoom booked by:\033[0m \033[1;37m" << reservation.client_name << "\033[0m\n";
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
            camera.price = ReadUntilInt("\033[1;37mEnter new price: \033[0m");
            saveCamera(cameras);
            cout << "\n!! Room price successfully modified !!\n";
            return;
        }
    }
    cout << "\n!! Room not found !!\n";
}

#endif //HOTEL_ROOM_REZERVATION_MANAGER_CAMERA_H