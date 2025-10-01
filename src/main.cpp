#include <iostream>
#include <stdexcept>
#include "../include/Camera.h"
#include "../include/Reservation.h"
#include "../include/Profile.h"
#include "../include/Classes.h"
#include "../include/Functions.h"
#include "../include/Menus.h"
#include "../include/Employee.h"

int main() {
    std::vector<Camera> cameras;
    std::vector<Reservation> reservations;
    std::vector<Profile> profiles;
    std::vector<Employee> employees;

    int option = 0;
    int suboption;

    LoadSettings();

    std::cout << "\033[H\033[J\n";

    if (confirmEnter()){
        initialiseCamera(cameras);
        initialiseReservation(reservations);
        initialiseProfile(profiles);
        initialiseEmployee(employees);
        while (option != 6) {
            em:
            std::string title = hotel_name;
            switch (displayMainMenu()) {
                case 1: {
                    suboption = 0;
                    while (suboption != 7) {
                        switch (displayRoomMenu()) {
                            case 1: {
                                std::cout << "\033[H\033[J\n";
                                showCameras(cameras, reservations);
                                suboption = 0;
                                while (suboption != 1) {
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 2: {
                                std::cout << "\033[H\033[J\n";
                                showAvailableCameras(cameras);
                                suboption = 0;
                                while (suboption != 1) {
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 3: {
                                std::cout << "\033[H\033[J\n";
                                addCamera(cameras);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 4: {
                                std::cout << "\033[H\033[J\n";
                                int id;
                                id = ReadUntilInt("\033[1;37mEnter room id: \033[0m");
                                deleteCamera(cameras, id);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 5: {
                                std::cout << "\033[H\033[J\n";
                                int id;
                                id = ReadUntilInt("\033[1;37mEnter room id: \033[0m");
                                modifyCameraPrice(cameras, id);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 6: {
                                std::cout << "\033[H\033[J\n";
                                int id;
                                id = ReadUntilInt("\033[1;37mEnter room id: \033[0m");
                                searchCamera(cameras, id, reservations);
                                suboption = 0;
                                while (suboption != 1) {
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 7: {
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                goto em;
                            }
                            default: {
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033[1;91m!! Invalid option !!\033[0m\n";
                            }
                        }
                    }
                    break;
                }
                case 2: {
                    suboption = 0;
                    while (suboption != 7) {
                        switch (displayReservationMenu()) {
                            case 1: {
                                std::cout << "\033[H\033[J\n";
                                showReservations(reservations, cameras);
                                suboption = 0;
                                while (suboption != 1){
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 2: {
                                std::cout << "\033[H\033[J\n";
                                addReservation(reservations, cameras, profiles);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 3: {
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter reservation name: \033[0m";
                                std::getline(std::cin, name);
                                deleteReservation(reservations, name, cameras);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 4: {
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter reservation name: \033[0m";
                                std::getline(std::cin, name);
                                modifyReservation(reservations, cameras, name, profiles);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 5: {
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter reservation name: \033[0m";
                                std::getline(std::cin, name);
                                searchReservation(reservations, name, cameras);
                                suboption = 0;
                                while (suboption != 1){
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 6: {
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter reservation name: \033[0m";
                                std::getline(std::cin, name);
                                generateBill(reservations, cameras, name, profiles);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 7: {
                                std::cout << "\033[H\033[J\n";
                                goto em;
                            }
                            default: {
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033[1;31m!! Invalid option !!\033[0m\n";
                                std::cout << "\033c";
                                break;
                            }
                        }
                    }
                    break;
                }
                case 3:{
                    suboption = 0;
                    std::cout << "\033[H\033[J\n";
                    while (suboption != 5) {
                        switch (displayProfileMenu()) {
                            case 1: {
                                std::cout << "\033[H\033[J\n";
                                showProfiles(profiles);
                                suboption = 0;
                                while (suboption != 1){
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 2: {
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter profile name: \033[0m";
                                std::getline(std::cin, name);
                                deleteProfile(profiles, name);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 3: {
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter profile name: \033[0m";
                                std::getline(std::cin, name);
                                modifyProfile(profiles, name);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 4: {
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter profile name: \033[0m";
                                std::getline(std::cin, name);
                                searchProfile(profiles, name);
                                suboption = 0;
                                while (suboption != 1){
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 5: {
                                std::cout << "\033[H\033[J\n";
                                goto em;
                            }
                            default: {
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033[1;31m!! Invalid option !!\033[0m\n";
                                std::cout << "\033c";
                                break;
                            }
                        }
                    }
                    break;
                }
                case 4:{
                    std::cout << "\033[H\033[J\n";
                    suboption = 0;
                    while (suboption != 6){
                        switch(displayEmployeeMenu()){
                            case 1:{
                                std::cout << "\033[H\033[J\n";
                                showEmployees(employees);
                                suboption = 0;
                                while (suboption != 1){
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 2:{
                                std::cout << "\033[H\033[J\n";
                                addEmployee(employees);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 3:{
                                std::cout << "\033[H\033[J\n";
                                int id;
                                id = ReadUntilInt("\033[1;37mEnter employee id: \033[0m");
                                deleteEmployee(employees, id);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 4:{
                                std::cout << "\033[H\033[J\n";
                                int id;
                                id = ReadUntilInt("\033[1;37mEnter employee id: \033[0m");
                                modifyEmployee(employees, id);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 5:{
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter employee name: \033[0m";
                                std::getline(std::cin, name);
                                searchEmployee(employees, name);
                                suboption = 0;
                                while (suboption != 1){
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 6:{
                                std::cout << "\033[H\033[J\n";
                                goto em;
                            }
                            default:{
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033[1;31m!! Invalid option !!\033[0m\n";
                            }
                        }
                    }
                }
                case 5:{
                    std::cout << "\033[H\033[J\n";
                    suboption = 0;
                    while (suboption != 1){
                        getReport(reservations, cameras, employees, profiles);
                        suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                        if (suboption == 1) {
                            std::cout << "\033[H\033[J\n";
                            std::cout << "\033c";
                            break;
                        }
                        else {
                            std::cout << "\033[H\033[J\n";
                            std::cout << "\033[1;31m!! Invalid option !!\033[0m\n";
                            suboption = 0;
                        }

                    }
                    goto em;
                }
                case 6:{
                    std::cout << "\033[H\033[J\n";
                    suboption = 0;
                    while (suboption != 2) {
                        switch (displaySettingsMenu()) {
                            case 1: {
                                ChangeName(hotel_name);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 2: {
                                ChangePassword(hotel_password);
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 3:{
                                std::cout << "\033[H\033[J\n";
                                int choice = 1;
                                resetDatabase(choice);
                                if(choice == 1){
                                    cameras.clear();
                                    reservations.clear();
                                    profiles.clear();
                                    employees.clear();
                                    LoadSettings();
                                }
                                suboption = 0;
                                while (suboption != 1){
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033c";
                                break;
                            }
                            case 4: {
                                std::cout << "\033[H\033[J\n";
                                goto em;
                            }
                            default: {
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033[1;31m!! Invalid option !!\033[0m\n";
                                std::cout << "\033c";
                                break;
                            }
                        }
                    }
                    break;
                }

                case 7:{
                    std::cout << "\033[H\033[J\n";
                    std::cout << "\n\033[1;32mHave a nice day!\033[0m\n\n";
                    return 0;
                }
                default:{
                    std::cout << "\033[H\033[J\n";
                    std::cout << "\033[1;31m!! Invalid option !!\033[0m\n";
                    std::cout << "\033c";
                    break;
                }
            }
        }
    }
}