# Hotel Room and Reservation Manager

## 🏨 Overview

The **Hotel Room and Reservation Manager** is a console-based application designed to simplify hotel operations. It provides tools for managing rooms, reservations, and client profiles, making it easier for hotel staff to handle day-to-day tasks efficiently.

---

## ⚙️ Features

### Room Management
- View all rooms or check availability.
- Add, delete, or modify room details (e.g., price).
- Search for specific rooms by ID.

### Reservation Management
- Add, modify, or delete reservations.
- View all reservations or search by name.
- Generate bills for completed reservations.

### Profile Management
- Manage client profiles (add, search, modify, delete).
- Link client profiles with reservations for seamless tracking.

### Reporting
- Generate detailed reports summarizing room usage and reservations.

---

## 🛠️ Installation

### Prerequisites

Ensure the following are installed on your system:
- **C++ Compiler**: Supports C++17 or later (e.g., GCC, Clang, MSVC).
- **CMake**: For streamlined building.
- **Git**: For cloning the repository.

---

### Installation Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/vladuzzul/Hotel-Management-System.git
   cd Hotel-Management-System
   ```
2. Create a build directory and navigate into it:
   ```bash
   mkdir build
   cd build
   ```
3. Run CMake to configure the project:
   ```bash
   cmake ..
   ```
4. Build the application:
   ```bash
   cmake --build .
   ```
5. Run the application:
   ```bash
   ./Hotel_Room_Rezervation_Manager
   ```

---

## 🔄 Usage

Launch the application and navigate through the intuitive menu:

1. **Room Management**: Manage hotel rooms (view, add, delete, modify, search).
2. **Reservation Management**: Oversee reservations (view, add, delete, modify, generate bills).
3. **Profile Management**: Handle client profiles (view, search, modify, delete).
4. **Generate Reports**: Access a summary of hotel operations.
5. **Exit**: Quit the application.

Use numeric inputs to select menu options.

---

## 🧪 Testing

This project includes unit tests for core functionality using the Google Test framework.

### Running Tests

1. Ensure the project is built with the test target:
   ```bash
   cmake -S . -B build
   cmake --build build
   ```

2. Run the tests using `ctest`:
   ```bash
   cd build
   ctest
   ```

3. View detailed test output:
   ```bash
   ctest --output-on-failure
   ```

---

## ❤️ Contributing

Contributions are welcome! To contribute:
- Fork the repository.
- Submit pull requests for new features or bug fixes.
- Open issues for feature suggestions or bug reports.

---

## 🛠️ Technologies Used

- **Programming Language**: C++ (C++17 standard)
- **Build System**: CMake
- **Version Control**: Git
- **Testing Framework**: [Google Test](https://github.com/google/googletest)

---

## 🎥 Demo

Check out the live demo of the application in action:

[![Demo Video](https://img.youtube.com/vi/your-demo-video-id/0.jpg)](https://www.youtube.com/watch?v=your-demo-video-id)
