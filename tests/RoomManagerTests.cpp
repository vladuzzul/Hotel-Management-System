#include "RoomManager.cpp" // Include the implementation file
#include <gtest/gtest.h>

// Test adding a room
TEST(RoomManagerTests, AddRoom) {
    RoomManager manager;
    manager.addRoom(1, "Deluxe Room", 150.0);

    const auto& rooms = manager.getRooms();
    ASSERT_EQ(rooms.size(), 1);
    EXPECT_EQ(rooms[0].id, 1);
    EXPECT_EQ(rooms[0].name, "Deluxe Room");
    EXPECT_EQ(rooms[0].price, 150.0);
}

// Test adding a room with duplicate ID
TEST(RoomManagerTests, AddRoomDuplicateID) {
    RoomManager manager;
    manager.addRoom(1, "Deluxe Room", 150.0);

    EXPECT_THROW(manager.addRoom(1, "Standard Room", 100.0), std::runtime_error);
}

// Test deleting a room
TEST(RoomManagerTests, DeleteRoom) {
    RoomManager manager;
    manager.addRoom(1, "Deluxe Room", 150.0);
    manager.deleteRoom(1);

    const auto& rooms = manager.getRooms();
    ASSERT_TRUE(rooms.empty());
}

// Test deleting a non-existent room
TEST(RoomManagerTests, DeleteNonExistentRoom) {
    RoomManager manager;
    EXPECT_THROW(manager.deleteRoom(1), std::runtime_error);
}

// Test retrieving rooms
TEST(RoomManagerTests, GetRooms) {
    RoomManager manager;
    manager.addRoom(1, "Deluxe Room", 150.0);
    manager.addRoom(2, "Standard Room", 100.0);

    const auto& rooms = manager.getRooms();
    ASSERT_EQ(rooms.size(), 2);
    EXPECT_EQ(rooms[0].id, 1);
    EXPECT_EQ(rooms[1].id, 2);
}
