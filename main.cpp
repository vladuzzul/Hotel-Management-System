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

    while (option != 4) {
        cout << "\n=== " << hotel_name << " Room and Reservation manager === \n\n";
        cout << "1: Room management\n2: Reservation management\n3: Get full report\n4. Leave\n\n\nOption: ";
        cin >> option;

        switch (option) {
            case 1: {
                suboption = 0;
                while (suboption != 7) {
                    cout << "\033[H\033[J\n";
                    cout << "\n=== " << hotel_name << " Room management === \n\n";
                    cout << "1: See all rooms\n2: See available rooms\n3: Add room\n4: Delete room\n5: Modify room price\n6: Search room\n7: Go back\n\n\nOption: ";
                    cin >> suboption;
                    switch (suboption) {
                        case 1: {
                            showCameras(cameras, reservations);
                            suboption = 0;
                            while (suboption != 1){
                                cout << "\nPress 1 to go back: ";
                                cin >> suboption;
                            }
                            break;
                        }
                        case 2: {
                            showAvailableCameras(cameras);
                            suboption = 0;
                            while (suboption != 1){
                                cout << "\nPress 1 to go back: ";
                                cin >> suboption;
                            }
                            break;
                        }
                        case 3: {
                            addCamera(cameras);
                            break;
                        }
                        case 4: {
                            int id;
                            cout << "Enter room id: ";
                            cin >> id;
                            deleteCamera(cameras, id);
                            break;
                        }
                        case 5: {
                            int id;
                            cout << "Enter camera id: ";
                            cin >> id;
                            modifyCameraPrice(cameras, id);
                            break;
                        }
                        case 6: {
                            int id;
                            cout << "Enter room id: ";
                            cin >> id;
                            searchCamera(cameras, id, reservations);
                            suboption = 0;
                            while (suboption != 1){
                                cout << "\nPress 1 to go back: ";
                                cin >> suboption;
                            }
                            break;
                        }
                        case 7: {
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
                while (suboption != 6) {
                    cout << "\033[H\033[J\n";
                    cout << "\n === " << hotel_name << " Reservation management === \n\n";
                    cout << "1: See all reservations\n2: Add reservation\n3: Delete reservation\n4: Modify reservation\n5: Search reservation\n6: Go back\n\n\nOption: ";
                    cin >> suboption;
                    switch (suboption) {
                        case 1: {
                            showReservations(reservations, cameras);
                            suboption = 0;
                            while (suboption != 1){
                                cout << "\nPress 1 to go back: ";
                                cin >> suboption;
                            }
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
                            modifyReservation(reservations, cameras, name);
                            break;
                        }
                        case 5: {
                            string name;
                            cout << "Enter reservation name: ";
                            cin.ignore();
                            getline(cin, name);
                            searchReservation(reservations, name, cameras);
                            suboption = 0;
                            while (suboption != 1){
                                cout << "\nPress 1 to go back: ";
                                cin >> suboption;
                            }
                            break;
                        }
                        case 6: {
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
                suboption = 0;
                while (suboption != 1){
                    getReport(reservations, cameras);
                    cout << "\nPress 1 to go back: ";
                    cin >> suboption;
                }
                break;
            }
            case 4:{
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