# 🏨 Hotel Room and Reservation Manager

## 🔍 Overview

**Hotel Room and Reservation Manager** is a console-based application written in C++ for efficient hotel operations management. It provides features for managing rooms, reservations, clients, employees, and application settings.

---

## 🧩 Features

### 🛏️ Room Management
- View all rooms
- Check available rooms
- Add, remove, or update room price
- Search room by ID

### 📆 Reservation Management
- View all reservations
- Add, remove, or modify reservations
- Search reservation by name
- Generate invoices for clients

### 👤 Profile Management
- View all client profiles
- Search, modify, or delete profiles
- Link client profiles to reservations

### 👥 Employee Management
- View all employees
- Add new employee
- Change employee role
- Remove employee

### 📊 Reporting
- Generate full report: rooms, reservations, clients, and employees

### ⚙️ Settings
- Change the displayed hotel name in the interface
- Change the hotel system access password
- Reset the entire database

---

## 📁 Project Structure

```plaintext
Hotel-Management-System/
│
├── include/                   # Header files (declarations)
│   ├── Camera.h
│   ├── Classes.h
│   ├── Employee.h
│   ├── Functions.h
│   ├── Menus.h               # Menu options displayed in console
│   ├── Profile.h
│   ├── Reservation.h
│   └── Settings.h
│
├── src/                       # Source code (implementations)
│   └── main.cpp
│
├── CMakeLists.txt             # Build configuration
├── LICENSE  
└── README.md
```

---

## 🛠️ Installation

### ✅ Prerequisites

Make sure you have installed:
- **C++17** or newer (GCC / Clang / MSVC)
- **CMake**
- **Git**

### 🔧 Build Instructions

#### Clone the repository
```bash
git clone https://github.com/vladuzzul/Hotel-Management-System.git
cd Hotel-Management-System
```
#### Create build directory and compile
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
#### Run the application
```bash
./Hotel_Management_System
```

---

## 💻 Usage

After launching the application, you'll have access to an interactive console menu:

1. **Room management**
2. **Reservation management**
3. **Profile management**
4. **Employee management**
5. **Full report**
6. **Settings**
7. **Leave**

---

## 🤝 Contributing

Contributions are welcome! You can:
- Open an issue for bugs or suggestions
- Submit a pull request with new features
- Refactor or optimize code

---

## ⚙️ Tech Stack

- **Language**: C++ (C++17)
- **Build**: CMake
- **Version Control**: Git

---

## ©️ License

Distributed under the [MIT](LICENSE) license.
