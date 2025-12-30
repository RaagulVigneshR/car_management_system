#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Car class definition
class Car {
private: 
    string brand;
    string model;
    int year;
    string licensePlate;
    double price;

public:
    Car(string b, string m, int y, string lp, double p)
        : brand(b), model(m), year(y), licensePlate(lp), price(p) {}

    // Getters
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    string getLicensePlate() const { return licensePlate; }
    double getPrice() const { return price; }

    // Display car information
    void display() const {
        cout << "| " << setw(12) << left << brand
             << "| " << setw(15) << left << model
             << "| " << setw(6) << left << year
             << "| " << setw(12) << left << licensePlate
             << "| $" << setw(10) << fixed << setprecision(2) << price << " |" << endl;
    }

    // Check if license plate matches
    bool matchesPlate(const string& plate) const {
        return licensePlate == plate;
    }
};

// CarManager class definition
class CarManager {
private: 
    vector<Car> cars;

public:
    // Add a new car
    void addCar(const Car& car) {
        cars.push_back(car);
        cout << "\n✓ Car added successfully!" << endl;
    }

    // Remove car by license plate
    bool removeCar(const string& licensePlate) {
        auto it = find_if(cars. begin(), cars.end(),
                         [&licensePlate](const Car& car) {
                             return car.matchesPlate(licensePlate);
                         });

        if (it != cars.end()) {
            cars.erase(it);
            cout << "\n✓ Car removed successfully!" << endl;
            return true;
        }
        cout << "\n✗ Car not found!" << endl;
        return false;
    }

    // Display all cars
    void displayAllCars() const {
        if (cars.empty()) {
            cout << "\n⚠ No cars in inventory!" << endl;
            return;
        }

        cout << "\n" << string(70, '=') << endl;
        cout << "| " << setw(12) << left << "Brand"
             << "| " << setw(15) << left << "Model"
             << "| " << setw(6) << left << "Year"
             << "| " << setw(12) << left << "License"
             << "| " << setw(12) << left << "Price" << "|" << endl;
        cout << string(70, '=') << endl;

        for (const auto& car : cars) {
            car.display();
        }
        cout << string(70, '=') << endl;
    }

    // Search car by license plate
    void searchCar(const string& licensePlate) const {
        auto it = find_if(cars. begin(), cars.end(),
                         [&licensePlate](const Car& car) {
                             return car.matchesPlate(licensePlate);
                         });

        if (it != cars. end()) {
            cout << "\n" << string(70, '=') << endl;
            cout << "| " << setw(12) << left << "Brand"
                 << "| " << setw(15) << left << "Model"
                 << "| " << setw(6) << left << "Year"
                 << "| " << setw(12) << left << "License"
                 << "| " << setw(12) << left << "Price" << "|" << endl;
            cout << string(70, '=') << endl;
            it->display();
            cout << string(70, '=') << endl;
        } else {
            cout << "\n✗ Car not found!" << endl;
        }
    }

    // Get total inventory value
    double getTotalInventoryValue() const {
        double total = 0;
        for (const auto& car : cars) {
            total += car.getPrice();
        }
        return total;
    }

    // Get number of cars
    int getCarCount() const {
        return cars. size();
    }
};

// Display menu
void displayMenu() {
    cout << "\n" << string(50, '*') << endl;
    cout << "*" << setw(48) << left << " CAR MANAGEMENT SYSTEM" << "*" << endl;
    cout << string(50, '*') << endl;
    cout << "1. Add a new car" << endl;
    cout << "2. Remove a car" << endl;
    cout << "3. Display all cars" << endl;
    cout << "4. Search car by license plate" << endl;
    cout << "5. View inventory value" << endl;
    cout << "6. Exit" << endl;
    cout << string(50, '*') << endl;
    cout << "Enter your choice (1-6): ";
}

int main() {
    CarManager manager;
    int choice;
    string brand, model, licensePlate;
    int year;
    double price;

    // Add sample cars
    manager.addCar(Car("Toyota", "Camry", 2022, "ABC123", 25000.00));
    manager.addCar(Car("Honda", "Civic", 2021, "XYZ789", 22000.00));
    manager.addCar(Car("BMW", "X5", 2023, "BMW001", 65000.00));

    cout << "\n===========================================" << endl;
    cout << "     Welcome to Car Management System" << endl;
    cout << "===========================================" << endl;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
        case 1: {
            cout << "\n--- Add New Car ---" << endl;
            cout << "Enter brand: ";
            getline(cin, brand);
            cout << "Enter model: ";
            getline(cin, model);
            cout << "Enter year: ";
            cin >> year;
            cin.ignore();
            cout << "Enter license plate: ";
            getline(cin, licensePlate);
            cout << "Enter price:  $";
            cin >> price;
            cin.ignore();

            manager.addCar(Car(brand, model, year, licensePlate, price));
            break;
        }
        case 2: {
            cout << "\n--- Remove Car ---" << endl;
            cout << "Enter license plate:  ";
            getline(cin, licensePlate);
            manager.removeCar(licensePlate);
            break;
        }
        case 3: {
            manager.displayAllCars();
            break;
        }
        case 4: {
            cout << "\n--- Search Car ---" << endl;
            cout << "Enter license plate: ";
            getline(cin, licensePlate);
            manager.searchCar(licensePlate);
            break;
        }
        case 5: {
            cout << "\n" << string(50, '-') << endl;
            cout << "Total Cars in Inventory: " << manager. getCarCount() << endl;
            cout << fixed << setprecision(2);
            cout << "Total Inventory Value: $" << manager.getTotalInventoryValue() << endl;
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
