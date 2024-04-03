/*
Implementation of map. Test can be found in separate file called Test_stdmap.cpp.
Tanishk Singh Bisht
Fawaz Sapa
*/

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ctime>

struct EmployeeInfo {
    int age;
    int salary;
    int emplNumber;
};

class EmployeeDatabase {
public:
    // Insert a new employee into the database.
    void insert(int sin, const EmployeeInfo& empl) {
        if (!employees.insert({ sin, empl }).second) {
            std::cout << "Employee with SIN " << sin << " already exists." << std::endl;
        }
        else {
            std::cout << "Employee with SIN " << sin << " added." << std::endl;

        }
    }

    // Remove an employee from the database.
    void remove(int sin) {
        if (employees.erase(sin) == 0) {
            std::cout << "Employee with SIN " << sin << " not found." << std::endl;
        }
        else {
            std::cout << "Employee with SIN " << sin << " removed." << std::endl;

        }
    }

    // Display all employees in the database to console.
    void display() const {
        for (const auto& pair : employees) {
            std::cout << "SIN: " << pair.first
                << ", Age: " << pair.second.age
                << ", Salary: " << pair.second.salary
                << ", Employee Number: " << pair.second.emplNumber << std::endl;
        }
    }

    // Populate the database with random employee records.
    void populateDatabase(int numOfEmployees) {
        std::srand(std::time(nullptr)); 
        for (int i = 0; i < numOfEmployees; ++i) {
            EmployeeInfo empl;
            empl.age = 25 + std::rand() % 45; 
            empl.salary = 50000 + (std::rand() % 6) * 10000; 
            empl.emplNumber = i + 1;
            int sin = 100000000 + std::rand() % 900000000; 
            employees[sin] = empl;
        }
    }

    // Write the employee database to a file.
    void writeToFile(const std::string& filename) {
        std::ofstream outfile(filename);
        if (outfile.is_open()) {
            for (const auto& pair : employees) {
                outfile << "SIN: " << pair.first
                    << ", Age: " << pair.second.age
                    << ", Salary: " << pair.second.salary
                    << ", Employee Number: " << pair.second.emplNumber << std::endl;
            }
            outfile.close();
        }
        else {
            std::cerr << "Unable to open file for writing: " << filename << std::endl;
        }
    }
    bool find(int sin) {
        return employees.find(sin) != employees.end();
    }


private:
    std::map<int, EmployeeInfo> employees;
};

