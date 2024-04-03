/*
Test code for std::map
Tanishk Singh Bisht
Fawaz Sapa
*/

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "timer.h"

using namespace std;

struct estimatedSize {
    int data[1024];
};

struct EmployeeInfo {
    int age;
    int salary;
    int emplNumber;
};

class EmployeeDatabase {
public:
    void insert(int sin, const EmployeeInfo& empl) {
        employees.insert({ sin, empl });
    }

    void populateDatabase(int numOfEmployees) {
        srand(static_cast<unsigned>(time(nullptr)));
        for (int i = 0; i < numOfEmployees; ++i) {
            EmployeeInfo empl = { 25 + rand() % 45, 50000 + (rand() % 6) * 10000, i + 1 };
            int sin = 100000000 + rand() % 900000000;
            insert(sin, empl);
        }
        cout << "Database populated with " << numOfEmployees << " employees.\n";
    }
    bool find(int sin) {
        return employees.find(sin) != employees.end();
    }


private:
    map<int, EmployeeInfo> employees;
};

//Stress Test
void test_MaximumSize() {
    map<int, estimatedSize> largeMap;
    int counter = 0;
    size_t estimatedMaxInsertions = 800000000 / sizeof(estimatedSize);

    try {
        for (size_t i = 0; i < estimatedMaxInsertions; ++i) {
            largeMap[counter++] = estimatedSize{};
            if (counter % 10000 == 0) {
                cout << "Reached size: " << counter << endl;
            }

            // Conservative check to avoid bad_alloc
            if (i >= estimatedMaxInsertions * 0.9) { // Stop at 90% of the estimated max
                cout << "Approaching estimated maximum capacity based on available system memory." << endl;
                break;
            }
        }
    }
    catch (const bad_alloc&) {
        cout << "bad_alloc caught. Maximum map size likely reached at " << counter << " elements." << endl;
    }

    cout << "Test concluded with " << counter << " elements inserted." << endl;
    system("pause");
    cout << endl;
}

// Load test
void test_Load(EmployeeDatabase& db) {
    const int numberOfInsertions = 100000; // Number of times insert is called
    srand(static_cast<unsigned>(time(nullptr))); // Seed for random generation

    Timer timer;
    timer.start();
    for (int i = 0; i < numberOfInsertions; ++i) {
        EmployeeInfo empl = { 25 + rand() % 45, 50000 + (rand() % 6) * 10000, i };
        int sin = rand(); // Simplified SIN for this test
        db.insert(sin, empl);
    }
    timer.stop();

    cout << "Load test (Insert) completed after " << numberOfInsertions << " insertions. "
        << "Time taken: " << timer.currtime() << " seconds.\n";
    system("pause");
    cout << endl;
}

// Test for Search Speed
void test_SearchSpeed(EmployeeDatabase& db) {
    Timer timer;
    int searchKey = 100000000 + rand() % 900000000; // Random SIN to search for

    timer.start();
    bool found = db.find(searchKey);
    timer.stop();

    if (found) {
        cout << "Employee with SIN " << searchKey << " found. ";
    }
    else {
        cout << "Employee with SIN " << searchKey << " not found. ";
    }
    cout << "Search took " << timer.currtime() << " seconds.\n";
    system("pause");
    cout << endl;
}

int main() {
    EmployeeDatabase db;

    cout << "Starting Test for Maximum Size...\n";
    test_MaximumSize();

    cout << "\nStarting Load Test...\n";
    test_Load(db);

    cout << "\nStarting Test for Search Speed...\n";
    test_SearchSpeed(db);

    cout << "All tests completed. Check the console output and validate against expected outcomes.\n";

    return 0;
}
