#include <gtest/gtest.h>
#include "../src/RoomManager.cpp" // Include the correct RoomManager implementation

TEST(RoomTests, AddRoom) {
    RoomManager roomManager;
    roomManager.addRoom(101, "Single", 100.0); // Corrected method call
    const auto &rooms = roomManager.getRooms();
    ASSERT_EQ(rooms.size(), 1);
    ASSERT_EQ(rooms[0].id, 101);
    ASSERT_EQ(rooms[0].name, "Single");
    ASSERT_EQ(rooms[0].price, 100.0);
}

TEST(RoomTests, DeleteRoom) {
    RoomManager roomManager;
    roomManager.addRoom(102, "Double", 150.0); // Corrected method call
    roomManager.deleteRoom(102); // Corrected method call
    const auto &rooms = roomManager.getRooms();
    ASSERT_TRUE(rooms.empty());
}