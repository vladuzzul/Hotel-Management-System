//
// Created by Vlad Cozma on 27.12.2024.
//

#ifndef HOTEL_ROOM_REZERVATION_MANAGER_PROFILE_H
#define HOTEL_ROOM_REZERVATION_MANAGER_PROFILE_H
#include "Classes.h"
#include "Functions.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


ofstream pout("Client_profile.txt", ios::app);

void initialiseProfile(vector<Profile>& profiles){
    ifstream pin("Client_profile.txt");
    if(!pin.is_open()){
        cout << "No profile file found. Starting with a empty profile database. \n";
        return;
    }

    string line;
    while(getline(pin, line)){
        size_t pos;
        Profile profile;

        pos = line.find(',');
        profile.name = line.substr(0, pos);
        line.erase(0, pos+1);

        profile.visits += stoi(line);
        profiles.push_back(profile);
    }
}

void saveProfile(const vector<Profile>& profiles){
    pout.close();
    pout.open("Client_profile.txt", ios::trunc);

    for (const auto& profile : profiles)
        pout << profile.name << "," << profile.visits << '\n';
    pout.close();
}

void showProfiles(const vector<Profile>& profiles){
    bool showed = false;
    for (auto& profile : profiles){
        cout << "Client " << profile.name << " has a number of " << profile.visits << " reservations.\n\n";
        showed = true;
    }
    if (!showed)
        cout << "\n!! No profiles registered yet !!\n";
}

void modifyProfile(vector<Profile>& profiles, const string& name){
    bool showed = false;
    for (auto& profile : profiles){
        if (equal_strings(profile.name, name)){
            cout << "\nCurrent number of visits: " << profile.visits << '\n';
            profile.visits = ReadUntilInt("Enter new number of visits: ");
            saveProfile(profiles);
            cout << "\n!! Profile successfully modified !!\n";
            showed = true;
        }
    }
    if (!showed)
        cout << "\n!! Profile not found !!\n";

}

void searchProfile(const vector<Profile>& profiles, const string& name){
    bool showed = false;
    for (const auto& profile : profiles) {
        if (equal_strings(profile.name, name)){
            cout << "\nClient " << profile.name << " has a number of " << profile.visits << " reservations.\n";
        }
        showed = true;
    }
    if (!showed) cout << "\n!! Room not found !!\n";
}

void deleteProfile(vector<Profile>& profiles, const string& name){
    for (auto it = profiles.begin(); it != profiles.end(); ++it) {
        if (equal_strings(it -> name, name)){
            profiles.erase(it);
            saveProfile(profiles);
            cout << "\nProfile successfully deleted!\n";
            return;
        }
    }
    cout << "\n!! Profile not found !!\n";
}

#endif //HOTEL_ROOM_REZERVATION_MANAGER_PROFILE_H