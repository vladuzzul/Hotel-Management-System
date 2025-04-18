#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Classes.h"
#include "Functions.h"
#include <fstream>
#include <iostream>
#include <vector>

std::ofstream eout("Employee.txt", std::ios::app);

void initialiseEmployee(std::vector<Employee>& Employees) {
    std::ifstream pin("Employee.txt");
    if (!pin.is_open()) {
        std::cout << "No employee file found. Starting with an empty employee database. \n";
        return;
    }

    std::string line;
    while (std::getline(pin, line)) {
        size_t pos;
        Employee employee;

        pos = line.find(',');
        employee.id = std::stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(',');
        employee.name = line.substr(0, pos);
        line.erase(0, pos + 1);

        employee.role = line;
        Employees.push_back(employee);
    }
}

void saveEmployee(const std::vector<Employee>& employees) {
    eout.close();
    eout.open("Employee.txt", std::ios::trunc);
    for (const auto& employee : employees)
        eout << employee.id << "," << employee.name << "," << employee.role << "\n";
    eout.close();
}

void showEmployees(const std::vector<Employee>& employees) {
    if (employees.empty()) {
        std::cout << "\n\033[1;31m!! No employees registered yet !!\033[0m\n";
        return;
    }
    else{
        std::cout << "\033[1;90m---------------------------------\n\033[0m";
        for (const auto& employee : employees) {
            std::cout << "\033[1;90mID: \033[1;37m" << employee.id << "\n";
            std::cout << "\033[1;90mName: \033[1;37m" << employee.name << "\n";
            std::cout << "\033[1;90mRole: \033[1;37m" << employee.role << "\n";
            std::cout << "\033[1;90m---------------------------------\n\033[0m";
        }
    }
    
}

void addEmployee(std::vector<Employee>& employees) {
    Employee employee;
    std::cout << "\n\033[1;90mEnter employee ID: \033[1;37m";
    std::cin >> employee.id;
    std::cin.ignore();
    std::cout << "\n\033[1;90mEnter employee name: \033[1;37m";
    std::getline(std::cin, employee.name);
    std::cout << "\n\033[1;90mEnter employee role: \033[1;37m";
    std::getline(std::cin, employee.role);
    employees.push_back(employee);
    saveEmployee(employees);
}

void modifyEmployee(std::vector<Employee>& employees, int id) {
    if (employees.empty()) {
        std::cout << "\n\033[1;31m!! No employees registered yet !!\033[0m\n";
        return;
    }
    else{
    bool showed = false;
    for (auto& employee : employees) {
        if (employee.id == id) {
            std::cout << "\n\033[1;90mCurrent role: \033[1;37m" << employee.role << "\n\033[0m\n";
            std::cout << "\n\033[1;90mEnter new role: \033[1;37m";
            std::getline(std::cin, employee.role);
            saveEmployee(employees);
            std::cout << "\n!! Employee successfully modified !!\n";
            showed = true;
        }
    }
    if (!showed)
        std::cout << "\n\033[1;31m!! Employee not found !!\033[0m\n";
    }
}

void deleteEmployee(std::vector<Employee>& employees, int id) {
    if (employees.empty()) {
        std::cout << "\n\033[1;31m!! No employees registered yet !!\033[0m\n";
        return;
    }
    else {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->id == id) {
                employees.erase(it);
                saveEmployee(employees);
                std::cout << "\nEmployee successfully deleted!\n";
                return;
            }
        }
    std::cout << "\n\033[1;31m!! Employee not found !!\033[0m\n";   
    }
}

void searchEmployee(const std::vector<Employee>& employees, const std::string& name) {
    if (employees.empty()) {
        std::cout << "\n\033[1;31m!! No employees registered yet !!\033[0m\n";
        return;
    }
    else {
    bool found = false;
    for (const auto& employee : employees) {
        if (equal_strings(employee.name, name)) {
            std::cout << "\n\033[1;90mID \033[1;37mName \033[1;90mRole\n\033[0m";
            std::cout << "\033[1;90m" << employee.id << " \033[1;37m" << employee.name << " \033[1;90m" << employee.role << "\n\033[0m";
            found = true;
        }
    }
    if (!found)
    std::cout << "\n\033[1;31m!! Employee not found !!\033[0m\n";   
    }
}

#endif // EMPLOYEE_H