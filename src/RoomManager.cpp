#include "Camera.h"
#include <vector>
#include <string>
#include <stdexcept> // For exception handling

class Room {
public:
    int id;
    std::string name;
    double price;

    Room(int id, const std::string &name, double price)
        : id(id), name(name), price(price) {}
};

class RoomManager {
private:
    std::vector<Room> rooms;

public:
    void addRoom(int id, const std::string &name, double price) {
        for (const auto &room : rooms) {
            if (room.id == id) {
                throw std::runtime_error("Room with this ID already exists.");
            }
        }
        rooms.emplace_back(id, name, price);
    }

    void deleteRoom(int id) {
        auto it = std::remove_if(rooms.begin(), rooms.end(),
                                 [id](const Room &room) { return room.id == id; });
        if (it == rooms.end()) {
            throw std::runtime_error("Room with this ID does not exist.");
        }
        rooms.erase(it, rooms.end());
    }

    const std::vector<Room> &getRooms() const {
        return rooms;
    }
};