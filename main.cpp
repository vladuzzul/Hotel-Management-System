#include <iostream>
#include "Camera.h"
#include "Reservation.h"
#include "Profile.h"
#include "Classes.h"
#include "Functions.h"
using namespace std;

int main() {
    vector<Camera> cameras;
    vector<Reservation> reservations;
    vector<Profile> profiles;

    initialiseCamera(cameras);
    initialiseReservation(reservations);
    initialiseProfile(profiles);

    int option = 0;
    int suboption;

    cout << "\033[H\033[J\n";

    while (option != 5) {

        cout << "\n=== " << hotel_name << " Room and Reservation manager === \n\n";
        cout << "1: Room management\n2: Reservation management\n3: Profile management\n4: Get full report\n5. Leave\n\n\n";
        option = ReadUntilInt("Option: ");
        cout << "\033[H\033[J\n";
        switch (option) {
            case 1: {
                suboption = 0;
                while (suboption != 7) {
                    cout << "\n=== " << hotel_name << " Room management === \n\n";
                    cout << "1: See all rooms\n2: See available rooms\n3: Add room\n4: Delete room\n5: Modify room price\n6: Search room\n7: Go back\n\n\n";
                    suboption = ReadUntilInt("Option: ");
                    cout << "\033[H\033[J\n";
                    switch (suboption) {
                        case 1: {
                            cout << "\033[H\033[J\n";
                            showCameras(cameras, reservations);
                            suboption = 0;
                            while (suboption != 1){
                                suboption = ReadUntilInt("\nPress 1 to go back: ");
                            }
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 2: {
                            cout << "\033[H\033[J\n";
                            showAvailableCameras(cameras);
                            suboption = 0;
                            while (suboption != 1){
                                suboption = ReadUntilInt("\nPress 1 to go back: ");
                            }
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 3: {
                            cout << "\033[H\033[J\n";
                            addCamera(cameras);
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 4: {
                            cout << "\033[H\033[J\n";
                            int id;
                            id = ReadUntilInt("Enter room id: ");
                            deleteCamera(cameras, id);
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 5: {
                            cout << "\033[H\033[J\n";
                            int id;
                            id = ReadUntilInt("Enter room id: ");
                            modifyCameraPrice(cameras, id);
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 6: {
                            cout << "\033[H\033[J\n";
                            int id;
                            id = ReadUntilInt("Enter room id: ");
                            searchCamera(cameras, id, reservations);
                            suboption = 0;
                            while (suboption != 1){
                                suboption = ReadUntilInt("\nPress 1 to go back: ");
                            }
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 7: {
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        default: {
                            cout << "\033[H\033[J\n";
                            cout << "!! Invalid option !!\n";
                        }
                    }
                }
                break;
            }
            case 2: {
                suboption = 0;
                cout << "\033[H\033[J\n";
                while (suboption != 7) {
                    cout << "\n === " << hotel_name << " Reservation management === \n\n";
                    cout << "1: See all reservations\n2: Add reservation\n3: Delete reservation\n4: Modify reservation\n5: Search reservation\n6: Generate bill\n7: Go back\n\n\n";
                    suboption = ReadUntilInt("Option: ");
                    cout << "\033[H\033[J\n";
                    switch (suboption) {
                        case 1: {
                            cout << "\033[H\033[J\n";
                            showReservations(reservations, cameras);
                            suboption = 0;
                            while (suboption != 1){
                                suboption = ReadUntilInt("\nPress 1 to go back: ");
                            }
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 2: {
                            cout << "\033[H\033[J\n";
                            addReservation(reservations, cameras, profiles);
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 3: {
                            cout << "\033[H\033[J\n";
                            string name;
                            cout << "Enter reservation name: ";
                            getline(cin, name);
                            deleteReservation(reservations, name, cameras);
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 4: {
                            cout << "\033[H\033[J\n";
                            string name;
                            cout << "Enter reservation name: ";
                            getline(cin, name);
                            modifyReservation(reservations, cameras, name, profiles);
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 5: {
                            cout << "\033[H\033[J\n";
                            string name;
                            cout << "Enter reservation name: ";
                            getline(cin, name);
                            searchReservation(reservations, name, cameras);
                            suboption = 0;
                            while (suboption != 1){
                                suboption = ReadUntilInt("\nPress 1 to go back: ");
                            }
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 6: {
                            cout << "\033[H\033[J\n";
                            string name;
                            cout << "Enter reservation name: ";
                            getline(cin, name);
                            generateBill(reservations, cameras, name, profiles);
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 7: {
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        default: {
                            cout << "\033[H\033[J\n";
                            cout << "!! Invalid option !!\n";
                            break;
                        }
                    }
                }
                break;
            }
            case 3:{
                suboption = 0;
                cout << "\033[H\033[J\n";
                while (suboption != 5) {
                    cout << "\n === " << hotel_name << " Client Profile management === \n\n";
                    cout << "1: See all profiles\n2: Search profile\n3: Modify profile\n4: Delete profile\n5: Go back\n\n\n";
                    suboption = ReadUntilInt("Option: ");
                    cout << "\033[H\033[J\n";
                    switch (suboption) {
                        case 1: {
                            cout << "\033[H\033[J\n";
                            showProfiles(profiles);
                            suboption = 0;
                            while (suboption != 1){
                                suboption = ReadUntilInt("\nPress 1 to go back: ");
                            }
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 2: {
                            cout << "\033[H\033[J\n";
                            string name;
                            cout << "Enter profile name: ";
                            getline(cin, name);
                            searchProfile(profiles, name);
                            suboption = 0;
                            while (suboption != 1){
                                suboption = ReadUntilInt("\nPress 1 to go back: ");
                            }
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 3: {
                            cout << "\033[H\033[J\n";
                            string name;
                            cout << "Enter profile name: ";
                            getline(cin, name);
                            modifyProfile(profiles, name);
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 4: {
                            cout << "\033[H\033[J\n";
                            string name;
                            cout << "Enter profile name: ";
                            getline(cin, name);
                            deleteProfile(profiles, name);
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        case 5: {
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        default: {
                            cout << "\033[H\033[J\n";
                            cout << "!! Invalid option !!\n";
                            break;
                        }
                    }
                }
                break;
            }
            case 4:{
                cout << "\033[H\033[J\n";
                suboption = 0;
                while (suboption != 1){
                    getReport(reservations, cameras);
                    suboption = ReadUntilInt("\nPress 1 to go back: ");
                    cout << "\033[H\033[J\n";
                }
                break;
            }
            case 5:{
                cout << "\033[H\033[J\n";
                cout << "\nHave a nice day!\n\n";
                break;
            }
            default:{
                cout << "\033[H\033[J\n";
                cout << "!! Invalid option !!\n";
                break;
            }
        }
    }
    return 0;
}
