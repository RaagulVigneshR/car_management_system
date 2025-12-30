# Car Management System

A simple and efficient C++ command-line application for managing a car inventory system.

## Features

- ✅ **Add Cars**: Add new cars to the inventory with details like brand, model, year, license plate, and price
- ✅ **Remove Cars**: Remove cars from the inventory by license plate
- ✅ **View All Cars**: Display all cars in a formatted table
- ✅ **Search Functionality**: Search for specific cars by license plate
- ✅ **Inventory Value**: Calculate and display total inventory value
- ✅ **User-Friendly Menu**: Interactive command-line interface

## Requirements

- C++ Compiler (g++, clang, or MSVC)
- C++ Standard Library (C++11 or later)
- Operating System: Windows, macOS, or Linux

## Installation

### Option 1: MinGW on Windows
1. Download MinGW-w64 from [mingw-w64.org](https://www.mingw-w64.org/)
2. Install with these settings:
   - Architecture: x86_64
   - Threads: posix
3. Add `C:\mingw-w64\bin` to your system PATH
4. Restart your terminal

### Option 2: Linux
```bash
sudo apt-get install build-essential
```

### Option 3: macOS
```bash
xcode-select --install
```

## Compilation & Execution

### Compile the Program
```bash
g++ -o CarManagement main.cpp -std=c++11
```

### Run the Program
```bash
./CarManagement          # Linux/macOS
CarManagement. exe        # Windows
```

## Usage

Once the program starts, you'll see an interactive menu:

```
**************************************************
*             CAR MANAGEMENT SYSTEM             *
**************************************************
1. Add a new car
2. Remove a car
3. Display all cars
4. Search car by license plate
5. View inventory value
6. Exit
**************************************************
```

### Example Operations

**Adding a Car:**
```
Enter your choice:  1
Enter brand: Honda
Enter model: Accord
Enter year: 2022
Enter license plate: HND456
Enter price: $28000
```

**Searching a Car:**
```
Enter your choice: 4
Enter license plate:  ABC123
```

**Viewing Inventory Value:**
```
Enter your choice: 5
Total Cars in Inventory: 5
Total Inventory Value: $150000.00
```

## Project Structure

- **Car Class**: Represents an individual car with properties (brand, model, year, license plate, price)
- **CarManager Class**: Manages the collection of cars with CRUD operations
- **Main Function**: Handles user interaction through a menu-driven interface

## Data Members

### Car Class
- `brand` (string): Car manufacturer
- `model` (string): Car model name
- `year` (int): Manufacturing year
- `licensePlate` (string): Unique license plate number
- `price` (double): Car price

### CarManager Class
- `cars` (vector<Car>): Vector containing all cars in inventory

## Member Functions

### Car Class
- `getBrand()`: Returns the brand of the car
- `getModel()`: Returns the model of the car
- `getYear()`: Returns the manufacturing year
- `getLicensePlate()`: Returns the license plate
- `getPrice()`: Returns the price of the car
- `display()`: Displays car information in formatted output
- `matchesPlate()`: Checks if license plate matches

### CarManager Class
- `addCar()`: Adds a new car to inventory
- `removeCar()`: Removes a car by license plate
- `displayAllCars()`: Shows all cars in a table format
- `searchCar()`: Searches for a car by license plate
- `getTotalInventoryValue()`: Calculates total inventory value
- `getCarCount()`: Returns number of cars in inventory

## Sample Data

The program comes with 3 pre-loaded sample cars:
1. Toyota Camry (2022) - License: ABC123 - $25,000
2. Honda Civic (2021) - License: XYZ789 - $22,000
3. BMW X5 (2023) - License: BMW001 - $65,000

## Error Handling

- ✓ Validates user input
- ✓ Handles invalid menu choices
- ✓ Notifies user when car is not found
- ✓ Confirms successful operations

## Future Enhancements

- [ ] Save/load data to/from files
- [ ] Sort cars by price, year, or brand
- [ ] Filter cars by brand or year
- [ ] Update car details
- [ ] Export inventory to CSV
- [ ] GUI implementation

## License

This project is open source and available for educational purposes. 

## Author

Created as a basic car management system demonstration in C++. 

## Support

For issues or questions, please create an issue in the repository.
