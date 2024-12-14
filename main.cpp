#include <iostream>
#include "Hotel_Manager.h"
using namespace std;

int main() {
    vector<Camera> cameras;
    vector<Reservation> reservations;

    initialiseCamera(cameras);
    initialiseReservation(reservations);

    int option = 0;
    int suboption = 0;

    while (option != 3) {
        cout << "\n === " << hotel_name << " Room and Reservation manager === \n\n";
        cout << "1: Room management\n2: Reservation management\n3: Leave\n\n\nOption: ";
        cin >> option;

        switch (option) {
            case 1: {
                suboption = 0;
                while (suboption != 5) {
                    cout << "\033[H\033[J\n";
                    cout << "\n === " << hotel_name << " Room management === \n\n";
                    cout << "1: See all rooms\n2: Add room\n3: Delete room\n4: Search room\n5: Go back\n\n\nOption: ";
                    cin >> suboption;
                    switch (suboption) {
                        case 1: {
                            showCameras(cameras, reservations);
                            break;
                        }
                        case 2: {
                            addCamera(cameras);
                            break;
                        }
                        case 3: {
                            int id;
                            cout << "Enter room id: ";
                            cin >> id;
                            deleteCamera(cameras, id);
                            break;
                        }
                        case 4: {
                            int id;
                            cout << "Enter room id: ";
                            cin >> id;
                            searchCamera(cameras, id, reservations);
                            break;
                        }
                        case 5: {
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        default: {
                            cout << "!! Invalid option !!\n";
                        }
                    }
                }
                break;
            }
            case 2: {
                suboption = 0;
                while (suboption != 5) {
                    cout << "\033[H\033[J\n";
                    cout << "\n === " << hotel_name << " Reservation management === \n\n";
                    cout << "1: See all reservations\n2: Add reservation\n3: Delete reservation\n4: Search reservation\n5. Go back\n\n\nOption: ";
                    cin >> suboption;
                    switch (suboption) {
                        case 1: {
                            showReservations(reservations, cameras);
                            cout << "\n\n";
                            break;
                        }
                        case 2: {
                            addReservation(reservations, cameras);
                            break;
                        }
                        case 3: {
                            string name;
                            cout << "Enter reservation name: ";
                            cin.ignore();
                            getline(cin, name);
                            deleteReservation(reservations, name, cameras);
                            break;
                        }
                        case 4: {
                            string name;
                            cout << "Enter reservation name: ";
                            cin.ignore();
                            getline(cin, name);
                            searchReservation(reservations, name, cameras);
                            break;
                        }
                        case 5: {
                            cout << "\033[H\033[J\n";
                            break;
                        }
                        default: {
                            cout << "!! Invalid option !!\n";
                            break;
                        }
                    }
                }
                break;
            }
            case 3:{
                cout << "\nHave a nice day!\n\n";
                break;
            }
            default:{
                cout << "!! Invalid option !!\n";
                break;
            }
        }
    }
    return 0;
}