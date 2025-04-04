#include <iostream>
#include <stdexcept>
#include "../include/Camera.h"
#include "../include/Reservation.h"
#include "../include/Profile.h"
#include "../include/Classes.h"
#include "../include/Functions.h"

int main() {
    try {
        std::vector<Camera> cameras;
        std::vector<Reservation> reservations;
        std::vector<Profile> profiles;

        initialiseCamera(cameras);
        initialiseReservation(reservations);
        initialiseProfile(profiles);

        int option = 0;
        int suboption;
        
        LoadSettings();

        std::cout << "\033[H\033[J\n";

        while (option != 6) {
            std::string title = hotel_name;
            int totalWidth = 40-29; // -29 is for " Room and Reservation Manager"
            int padding = (totalWidth - title.length()) / 2;
            if (padding < 0) padding = 0;

            std::cout << "========================================\n";
            std::cout << std::string(padding, ' ') << "\033[1;34m" << hotel_name << " Room and Reservation Manager" << "\033[0m\n";
            std::cout << "========================================\n\n";
            std::cout << "\033[1;90m1:\033[0m \033[1;37mRoom management\033[0m\n";
            std::cout << "\033[1;90m2:\033[0m \033[1;37mReservation management\033[0m\n";
            std::cout << "\033[1;90m3:\033[0m \033[1;37mProfile management\033[0m\n";
            std::cout << "\033[1;90m4:\033[0m \033[1;37mGet full report\033[0m\n";
            std::cout << "\033[1;90m5:\033[0m \033[1;37mSettings\033[0m\n";
            std::cout << "\033[1;90m6:\033[0m \033[1;37mLeave\033[0m\n\n";
            std::cout << "========================================\n";
            option = ReadUntilInt("\033[1;32mOption: \033[0m");
            std::cout << "\033[H\033[J\n";

            switch (option) {
                case 1: {
                    suboption = 0;
                    while (suboption != 7) {
                        int totalWidth = 40-16; // -16 is for " Room Management"
                        int padding = (totalWidth - title.length()) / 2;
                        if (padding < 0) padding = 0;

                        std::cout << "========================================\n";
                        std::cout << std::string(padding, ' ') << "\033[1;34m" << hotel_name << " Room Management" << "\033[0m\n";
                        std::cout << "========================================\n\n";
                        std::cout << "\033[1;90m1:\033[0m \033[1;37mSee all rooms\033[0m\n";
                        std::cout << "\033[1;90m2:\033[0m \033[1;37mSee available rooms\033[0m\n";
                        std::cout << "\033[1;90m3:\033[0m \033[1;37mAdd room\033[0m\n";
                        std::cout << "\033[1;90m4:\033[0m \033[1;37mDelete room\033[0m\n";
                        std::cout << "\033[1;90m5:\033[0m \033[1;37mModify room price\033[0m\n";
                        std::cout << "\033[1;90m6:\033[0m \033[1;37mSearch room\033[0m\n";
                        std::cout << "\033[1;90m7:\033[0m \033[1;37mGo back\033[0m\n\n";
                        std::cout << "========================================\n";
                        suboption = ReadUntilInt("\033[1;32mOption: \033[0m");
                        std::cout << "\033[H\033[J\n";

                        switch (suboption) {
                            case 1: {
                                std::cout << "\033[H\033[J\n";
                                showCameras(cameras, reservations);
                                suboption = 0;
                                while (suboption != 1) {
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
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
                                break;
                            }
                            case 3: {
                                std::cout << "\033[H\033[J\n";
                                addCamera(cameras);
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            case 4: {
                                std::cout << "\033[H\033[J\n";
                                int id;
                                id = ReadUntilInt("\033[1;37mEnter room id: \033[0m");
                                deleteCamera(cameras, id);
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            case 5: {
                                std::cout << "\033[H\033[J\n";
                                int id;
                                id = ReadUntilInt("\033[1;37mEnter room id: \033[0m");
                                modifyCameraPrice(cameras, id);
                                std::cout << "\033[H\033[J\n";
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
                                break;
                            }
                            case 7: {
                                std::cout << "\033[H\033[J\n";
                                break;
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
                    std::cout << "\033[H\033[J\n";
                    while (suboption != 7) {
                        int totalWidth = 40-23; // -23 is for " Reservation Management"
                        int padding = (totalWidth - title.length()) / 2;
                        if (padding < 0) padding = 0;

                        std::cout << "========================================\n";
                        std::cout << std::string(padding, ' ') << "\033[1;34m" << hotel_name << " Reservation Management\033[0m\n";
                        std::cout << "========================================\n\n";
                        std::cout << "\033[1;90m1:\033[0m \033[1;37mSee all reservations\033[0m\n";
                        std::cout << "\033[1;90m2:\033[0m \033[1;37mAdd reservation\033[0m\n";
                        std::cout << "\033[1;90m3:\033[0m \033[1;37mDelete reservation\033[0m\n";
                        std::cout << "\033[1;90m4:\033[0m \033[1;37mModify reservation\033[0m\n";
                        std::cout << "\033[1;90m5:\033[0m \033[1;37mSearch reservation\033[0m\n";
                        std::cout << "\033[1;90m6:\033[0m \033[1;37mGenerate bill\033[0m\n";
                        std::cout << "\033[1;90m7:\033[0m \033[1;37mGo back\033[0m\n\n";
                        std::cout << "========================================\n";
                        suboption = ReadUntilInt("\033[1;32mOption: \033[0m");
                        std::cout << "\033[H\033[J\n";
                        switch (suboption) {
                            case 1: {
                                std::cout << "\033[H\033[J\n";
                                showReservations(reservations, cameras);
                                suboption = 0;
                                while (suboption != 1){
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            case 2: {
                                std::cout << "\033[H\033[J\n";
                                addReservation(reservations, cameras, profiles);
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            case 3: {
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter reservation name: \033[0m";
                                std::getline(std::cin, name);
                                deleteReservation(reservations, name, cameras);
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            case 4: {
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter reservation name: \033[0m";
                                std::getline(std::cin, name);
                                modifyReservation(reservations, cameras, name, profiles);
                                std::cout << "\033[H\033[J\n";
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
                                break;
                            }
                            case 6: {
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter reservation name: \033[0m";
                                std::getline(std::cin, name);
                                generateBill(reservations, cameras, name, profiles);
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            case 7: {
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            default: {
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033[1;31m!! Invalid option !!\033[0m\n";
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
                        int totalWidth = 40-26; // -26 is for " Client Profile Management"
                        int padding = (totalWidth - title.length()) / 2;
                        if (padding < 0) padding = 0;

                        std::cout << "========================================\n";
                        std::cout << std::string(padding, ' ') << "\033[1;34m" << hotel_name << " Client Profile Management\033[0m\n";
                        std::cout << "========================================\n\n";
                        std::cout << "\033[1;90m1:\033[0m \033[1;37mSee all profiles\033[0m\n";
                        std::cout << "\033[1;90m2:\033[0m \033[1;37mSearch profile\033[0m\n";
                        std::cout << "\033[1;90m3:\033[0m \033[1;37mModify profile\033[0m\n";
                        std::cout << "\033[1;90m4:\033[0m \033[1;37mDelete profile\033[0m\n";
                        std::cout << "\033[1;90m5:\033[0m \033[1;37mGo back\033[0m\n\n";
                        std::cout << "========================================\n";
                        suboption = ReadUntilInt("\033[1;32mOption: \033[0m");
                        std::cout << "\033[H\033[J\n";
                        switch (suboption) {
                            case 1: {
                                std::cout << "\033[H\033[J\n";
                                showProfiles(profiles);
                                suboption = 0;
                                while (suboption != 1){
                                    suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                                }
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            case 2: {
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
                                break;
                            }
                            case 3: {
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter profile name: \033[0m";
                                std::getline(std::cin, name);
                                modifyProfile(profiles, name);
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            case 4: {
                                std::cout << "\033[H\033[J\n";
                                std::string name;
                                std::cout << "\033[1;37mEnter profile name: \033[0m";
                                std::getline(std::cin, name);
                                deleteProfile(profiles, name);
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            case 5: {
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            default: {
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033[1;31m!! Invalid option !!\033[0m\n";
                                break;
                            }
                        }
                    }
                    break;
                }
                case 4:{
                    std::cout << "\033[H\033[J\n";
                    suboption = 0;
                    while (suboption != 1){
                        getReport(reservations, cameras);
                        suboption = ReadUntilInt("\n\033[1;32mPress 1 to go back: \033[0m");
                        std::cout << "\033[H\033[J\n";
                    }
                    break;
                }
                case 5:{
                    std::cout << "\033[H\033[J\n";
                    suboption = 0;
                    while (suboption != 2) {
                        std::string title = hotel_name;
                        int totalWidth = 40-9; // -9 is for " Settings"
                        int padding = (totalWidth - title.length()) / 2;
                        if (padding < 0) padding = 0;

                        std::cout << "========================================\n";
                        std::cout << std::string(padding, ' ') << "\033[1;34m" << hotel_name << " Settings\033[0m\n";
                        std::cout << "========================================\n\n";
                        std::cout << "\033[1;90m1:\033[0m \033[1;37mChange hotel name\033[0m\n";
                        std::cout << "\033[1;90m2:\033[0m \033[1;37mGo back\033[0m\n\n";
                        std::cout << "========================================\n";
                        suboption = ReadUntilInt("\033[1;32mOption: \033[0m");
                        std::cout << "\033[H\033[J\n";
                        switch (suboption) {
                            case 1: {
                                ChangeSettings(hotel_name);
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            case 2: {
                                std::cout << "\033[H\033[J\n";
                                break;
                            }
                            default: {
                                std::cout << "\033[H\033[J\n";
                                std::cout << "\033[1;31m!! Invalid option !!\033[0m\n";
                                break;
                            }
                        }
                    }
                    break;
                }
                case 6:{
                    std::cout << "\033[H\033[J\n";
                    std::cout << "\n\033[1;32mHave a nice day!\033[0m\n\n";
                    break;
                }
                default:{
                    std::cout << "\033[H\033[J\n";
                    std::cout << "\033[1;31m!! Invalid option !!\033[0m\n";
                    break;
                }
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
