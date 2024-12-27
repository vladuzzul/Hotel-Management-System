# Hotel Room and Reservation Manager

## 🏨 Overview

The **Hotel Room and Reservation Manager** is a comprehensive, console-based application that simplifies the management of hotel rooms, reservations, and client profiles. Designed for efficiency and user-friendliness, this application enables hotel staff to perform essential operations such as room assignments, billing, and profile management.

Explore the full project on [GitHub](https://github.com/vladuzzul/Hotel-Management-System).

---

## ⚙️ Features

### Room Management
- View all rooms or check availability.
- Add, delete, or modify room details (e.g., price).
- Search for specific rooms based on ID.

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
- **C++ Compiler**: Supports C++17 or later (e.g., GCC).
- **CMake** (optional): For streamlined building.
- **Standard Library**: Includes `<iostream>`, `<vector>`, `<string>`, `<sstream>`, `<iomanip>`.

### Installation Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/vladuzzul/Hotel-Management-System.git
   cd Hotel-Management-System
   ```
2. Compile the project:
   ```bash
   g++ -std=c++17 main.cpp -o hotel_manager
   ```
3. Run the application:
   ```bash
   ./hotel_manager
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

## 🔎 Code Highlights

### Modular Design
- Core functionality is encapsulated in separate headers (`Functions.h`, `Classes.h`, `Reservation.h`, `Profile.h`, `Camera.h`), ensuring a clean and maintainable structure.

### Date Utilities
- Features robust functions for date conversions, timestamp calculations, and date comparisons.

### User-Friendly Interface
- Incorporates dynamic screen-clearing commands to provide a seamless navigation experience.

---

## ❤️ Contributing

Contributions are always welcome! Feel free to:
- Fork the repository.
- Submit pull requests for new features or bug fixes.
- Open issues for feature suggestions or reporting bugs.

---
