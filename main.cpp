#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;

// Plain struct with model and price removed
struct Car {
    string brand;
    int year;
    string licensePlate;
};

// Add a new car
void addCar(vector<Car>& cars, const Car& car) {
    cars.push_back(car);
    cout << "\n✓ Car added successfully!" << endl;
}

// Remove car by license plate
bool removeCar(vector<Car>& cars, const string& licensePlate) {
    auto it = find_if(cars.begin(), cars.end(),
                      [&licensePlate](const Car& c) {
                          return c.licensePlate == licensePlate;
                      });

    if (it != cars.end()) {
        cars.erase(it);
        cout << "\n✓ Car removed successfully!" << endl;
        return true;
    }
    cout << "\n✗ Car not found!" << endl;
    return false;
}

// Display a single car (formatting helper)
void displayCar(const Car& car) {
    cout << "| " << setw(12) << left << car.brand
         << "| " << setw(6) << left << car.year
         << "| " << setw(12) << left << car.licensePlate
         << " |" << endl;
}

// Display all cars
void displayAllCars(const vector<Car>& cars) {
    if (cars.empty()) {
        cout << "\n⚠ No cars in inventory!" << endl;
        return;
    }

    cout << "\n" << string(50, '=') << endl;
    cout << "| " << setw(12) << left << "Brand"
         << "| " << setw(6) << left << "Year"
         << "| " << setw(12) << left << "License" << " |" << endl;
    cout << string(50, '=') << endl;

    for (const auto& car : cars) {
        displayCar(car);
    }
    cout << string(50, '=') << endl;
}

// Search car by license plate
void searchCar(const vector<Car>& cars, const string& licensePlate) {
    auto it = find_if(cars.begin(), cars.end(),
                      [&licensePlate](const Car& c) {
                          return c.licensePlate == licensePlate;
                      });

    if (it != cars.end()) {
        cout << "\n" << string(50, '=') << endl;
        cout << "| " << setw(12) << left << "Brand"
             << "| " << setw(6) << left << "Year"
             << "| " << setw(12) << left << "License" << " |" << endl;
        cout << string(50, '=') << endl;
        displayCar(*it);
        cout << string(50, '=') << endl;
    } else {
        cout << "\n✗ Car not found!" << endl;
    }
}

// Get number of cars
int getCarCount(const vector<Car>& cars) {
    return static_cast<int>(cars.size());
}

// Display menu
void displayMenu() {
    cout << "\n" << string(50, '*') << endl;
    cout << "*" << setw(48) << left << " CAR MANAGEMENT SYSTEM" << "*" << endl;
    cout << string(50, '*') << endl;
    cout << "1. Add a new car" << endl;
    cout << "2. Remove a car" << endl;
    cout << "3. Display all cars" << endl;
    cout << "4. Search car by license plate" << endl;
    cout << "5. View inventory count" << endl;
    cout << "6. Exit" << endl;
    cout << string(50, '*') << endl;
    cout << "Enter your choice (1-6): ";
}

int main() {
    vector<Car> cars;
    int choice;
    string brand, licensePlate;
    int year;

    // Add sample cars (model and price removed)
    addCar(cars, Car{"Toyota", 2022, "ABC123"});
    addCar(cars, Car{"Honda", 2021, "XYZ789"});
    addCar(cars, Car{"BMW", 2023, "BMW001"});

    cout << "\n===========================================" << endl;
    cout << "     Welcome to Car Management System" << endl;
    cout << "===========================================" << endl;

    while (true) {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n✗ Invalid input! Please enter a number between 1 and 6." << endl;
            continue;
        }
        cin.ignore(); // Clear input buffer

        switch (choice) {
        case 1: {
            cout << "\n--- Add New Car ---" << endl;
            cout << "Enter brand: ";
            getline(cin, brand);
            cout << "Enter year: ";
            if (!(cin >> year)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n✗ Invalid year. Operation cancelled." << endl;
                break;
            }
            cin.ignore();
            cout << "Enter license plate: ";
            getline(cin, licensePlate);

            addCar(cars, Car{brand, year, licensePlate});
            break;
        }
        case 2: {
            cout << "\n--- Remove Car ---" << endl;
            cout << "Enter license plate:  ";
            getline(cin, licensePlate);
            removeCar(cars, licensePlate);
            break;
        }
        case 3: {
            displayAllCars(cars);
            break;
        }
        case 4: {
            cout << "\n--- Search Car ---" << endl;
            cout << "Enter license plate: ";
            getline(cin, licensePlate);
            searchCar(cars, licensePlate);
            break;
        }
        case 5: {
            cout << "\n" << string(50, '-') << endl;
            cout << "Total Cars in Inventory: " << getCarCount(cars) << endl;
            cout << string(50, '-') << endl;
            break;
        }
        case 6: {
            cout << "\n✓ Thank you for using Car Management System!" << endl;
            cout << "Goodbye!" << endl;
            return 0;
        }
        default:
            cout << "\n✗ Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
