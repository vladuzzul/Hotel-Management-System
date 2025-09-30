#ifndef MENUS_H
#define MENUS_H
#include "../include/Functions.h"
#include "../include/Settings.h"
#include <iostream>
#include <string>

int displayMainMenu(){
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
    std::cout << "\033[1;90m4:\033[0m \033[1;37mEmployee management\033[0m\n";
    std::cout << "\033[1;90m5:\033[0m \033[1;37mGet full report\033[0m\n";
    std::cout << "\033[1;90m6:\033[0m \033[1;37mSettings\033[0m\n";
    std::cout << "\033[1;90m7:\033[0m \033[1;37mLeave\033[0m\n\n";
    std::cout << "========================================\n";
    int option = ReadUntilInt("\033[1;32mOption: \033[0m");
    std::cout << "\033[H\033[J\n";
    std::cout << "\033c";
    return option;
}

int displayRoomMenu(){
    std::string title = hotel_name;
    
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
    int suboption = ReadUntilInt("\033[1;32mOption: \033[0m");

    std::cout << "\033[H\033[J\n";
    std::cout << "\033c";
    return suboption;
}

int displayReservationMenu(){
    std::string title = hotel_name;
    
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
    int suboption = ReadUntilInt("\033[1;32mOption: \033[0m");
    std::cout << "\033[H\033[J\n";
    std::cout << "\033c";
    return suboption;
}

int displayProfileMenu(){
    std::string title = hotel_name;
    
    int totalWidth = 40-26; // -26 is for " Client Profile Management"
    int padding = (totalWidth - title.length()) / 2;
    if (padding < 0) padding = 0;

    std::cout << "========================================\n";
    std::cout << std::string(padding, ' ') << "\033[1;34m" << hotel_name << " Client Profile Management\033[0m\n";
    std::cout << "========================================\n\n";
    std::cout << "\033[1;90m1:\033[0m \033[1;37mSee all profiles\033[0m\n";
    std::cout << "\033[1;90m2:\033[0m \033[1;37mDelete profile\033[0m\n";
    std::cout << "\033[1;90m3:\033[0m \033[1;37mModify profile\033[0m\n";
    std::cout << "\033[1;90m4:\033[0m \033[1;37mSearch profile\033[0m\n";
    std::cout << "\033[1;90m5:\033[0m \033[1;37mGo back\033[0m\n\n";
    std::cout << "========================================\n";
    int suboption = ReadUntilInt("\033[1;32mOption: \033[0m");
    std::cout << "\033[H\033[J\n";
    std::cout << "\033c";
    return suboption;
}

int displaySettingsMenu(){
    std::string title = hotel_name;
    int totalWidth = 40-9; // -9 is for " Settings"
    int padding = (totalWidth - title.length()) / 2;
    if (padding < 0) padding = 0;

    std::cout << "========================================\n";
    std::cout << std::string(padding, ' ') << "\033[1;34m" << hotel_name << " Settings\033[0m\n";
    std::cout << "========================================\n\n";
    std::cout << "\033[1;90m1:\033[0m \033[1;37mChange hotel name\033[0m\n";
    std::cout << "\033[1;90m2:\033[0m \033[1;37mChange hotel password\033[0m\n";
    std::cout << "\033[1;90m3:\033[0m \033[1;37mReset database\033[0m\n";
    std::cout << "\033[1;90m4:\033[0m \033[1;37mGo back\033[0m\n\n";
    std::cout << "========================================\n";
    int suboption = ReadUntilInt("\033[1;32mOption: \033[0m");
    std::cout << "\033[H\033[J\n";
    std::cout << "\033c";
    return suboption;
}

int displayEmployeeMenu(){
    std::string title = hotel_name;
    
    int totalWidth = 40 - 20; // -20 is for " Employee Management"
    int padding = (totalWidth - title.length()) / 2;
    if (padding < 0) padding = 0;

    std::cout << "========================================\n";
    std::cout << std::string(padding, ' ') << "\033[1;34m" << hotel_name << " Employee Management\033[0m\n";
    std::cout << "========================================\n\n";
    std::cout << "\033[1;90m1:\033[0m \033[1;37mView all employees\033[0m\n";
    std::cout << "\033[1;90m2:\033[0m \033[1;37mAdd new employee\033[0m\n";
    std::cout << "\033[1;90m3:\033[0m \033[1;37mDelete employee\033[0m\n";
    std::cout << "\033[1;90m4:\033[0m \033[1;37mModify employee role\033[0m\n";
    std::cout << "\033[1;90m5:\033[0m \033[1;37mSearch employee\033[0m\n";
    std::cout << "\033[1;90m6:\033[0m \033[1;37mGo back\033[0m\n\n";
    std::cout << "========================================\n";

    int suboption = ReadUntilInt("\033[1;32mOption: \033[0m");
    std::cout << "\033[H\033[J\n";
    std::cout << "\033c";
    return suboption;
}

bool confirmEnter() {
    std::cout << "\033[H\033[J\n";
    et:
    std::string title = hotel_name;
    int totalWidth = 40-29; // -29 is for " Room and Reservation Manager"
    int padding = (totalWidth - title.length()) / 2;
    if (padding < 0) padding = 0;

    std::cout << "========================================\n";
    std::cout << std::string(padding, ' ') << "\033[1;34m" << hotel_name << " Room and Reservation Manager" << "\033[0m\n";
    std::cout << "========================================\n";
    std::cout << "\033[1;33mDefault password is 1234" << "\033[0m\n";
    std::cout << "\033[1;33mEnter '0' to reset the database.\033[0m\n\n";

    int password = ReadUntilInt("\033[1;32mEnter password: \033[0m");
    if (password == 0) {
        int resetSuccess = 1;
        resetDatabase(resetSuccess);
        if (resetSuccess == 1) {
            return 0;
        }
        std::cout << "\033[H\033[J\n";
        goto et;
    }
    if (password == hotel_password) {
        std::cout << "\033[H\033[J\n";
        return true;
    } else {
        std::cout << "\033[H\033[J\n";
        std::cout << "\n\033[1;31mIncorrect password. Try again.\033[0m\n";
        goto et;
    }
}


#endif // MENUS_H