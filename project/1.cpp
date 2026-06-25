#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
public:
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        totalVehicles++;
    }
    ~Vehicle() {}

    void setData(int id, string manu, string mod, int y)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = y;
    }
    int getID()
    {
        return vehicleID;
    }
    void display()
    {
        cout << "Vehicle ID     : " << vehicleID << endl;
        cout << "Manufacturer   : " << manufacturer << endl;
        cout << "Model          : " << model << endl;
        cout << "Year           : " << year << endl;
    }
};
int Vehicle::totalVehicles = 0;

// Single Inheritance
class Car : public Vehicle
{
protected:
    string fuelType;

public:
    void setCarData(int id, string manu, string mod, int y, string fuel)
    {
        setData(id, manu, mod, y);
        fuelType = fuel;
    }
    void displayCar()
    {
        display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// Multiple Inheritance
class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    void setElectricData(int id, string manu, string mod, int y, string fuel, int battery)
    {
        setCarData(id, manu, mod, y, fuel);
        batteryCapacity = battery;
    }
    void displayElectric()
    {
        displayCar();
        cout << "Battery Capacity: " << batteryCapacity << endl;
    }
};

// MultiLevel Inheritance
class SportsCar : public ElectricCar
{
    int topSpeed;

public:
    void setSportsData(int id, string manu, string mod, int y, string fuel, int battery, int speed)
    {
        setElectricData(id, manu, mod, y, fuel, battery);
        topSpeed = speed;
    }
    void displaySports()
    {
        displayElectric();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

// Multiple Inheritance
class Aircraft
{
protected:
    int flightRange;

public:
    void setRange(int range)
    {
        flightRange = range;
    }
};

// Multiple Inheritance
class FlyingCar : public Car, public Aircraft
{
public:
    void setFlyingData(int id, string manu, string mod, int y,
                       string fuel, int range)
    {
        setCarData(id, manu, mod, y, fuel);
        setRange(range);
    }

    void displayFlying()
    {
        displayCar();
        cout << "Flight Range : " << flightRange << " km" << endl;
    }
};

// Hierarchical Inheritance
class Sedan : public Car
{
};

class SUV : public Car
{
};

// Vehicle Registry
class VehicleRegistry
{
    Car cars[50];
    int count = 0;

public:
    void addVehicle()
    {
        int id, year;
        string manu, model, fuel;

        cout << "\nEnter Vehicle ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Manufacturer: ";
        getline(cin, manu);

        cout << "Enter Model: ";
        getline(cin, model);

        cout << "Enter Year: ";
        cin >> year;
        cin.ignore();

        cout << "Enter Fuel Type: ";
        getline(cin, fuel);

        cars[count].setCarData(id, manu, model, year, fuel);
        count++;

        cout << "\nVehicle Added Successfully!\n";
    }

    void viewVehicles()
    {
        if (count == 0)
        {
            cout << "\nNo Vehicles Found!\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << "\n------------------\n";
            cout << "\t", cars[i].displayCar();
        }
    }

    void searchVehicle()
    {
        int id;
        cout << "\nEnter Vehicle ID: ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (cars[i].getID() == id)
            {
                cout << "\nVehicle Found: \n";
                cout << "\t", cars[i].displayCar();
                return;
            }
        }

        cout << "\nVehicle Not Found!\n";
    }
};

int main()
{
    VehicleRegistry vr;
    int choice;

    do
    {
        cout << "\n===== VEHICLE REGISTRY SYSTEM =====";
        cout << "\n1. Add Vehicle";
        cout << "\n2. View All Vehicles";
        cout << "\n3. Search Vehicle";
        cout << "\n4. Total Vehicles";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            vr.addVehicle();
            break;

        case 2:
            vr.viewVehicles();
            break;

        case 3:
            vr.searchVehicle();
            break;

        case 4:
            cout << "\nTotal Vehicles Created: "
                 << Vehicle::totalVehicles << endl;
            break;

        case 5:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
