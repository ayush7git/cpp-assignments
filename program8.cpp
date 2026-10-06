#include <iostream>
#include <string>
using namespace std;

// ---------- Part A: Single inheritance (Person -> Student) ----------
class Person {
protected:
    string name;
    int age;

public:
    void getPerson() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
    }

    void showPerson() {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
};

class Student : public Person {
    int rollNo;
    float marks;

public:
    void getStudent() {
        getPerson();
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void showStudent() {
        showPerson();
        cout << "Roll : " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }
};

// ---------- Part B: Multilevel inheritance (Vehicle -> Car -> ElectricCar) ----------
class Vehicle {
protected:
    string company;
    int wheels;

public:
    void getVehicle() {
        cout << "Enter company: ";
        cin.ignore();
        getline(cin, company);
        cout << "Enter number of wheels: ";
        cin >> wheels;
    }

    void showVehicle() {
        cout << "Company : " << company << endl;
        cout << "Wheels  : " << wheels << endl;
    }
};

class Car : public Vehicle {
protected:
    string model;
    int seats;

public:
    void getCar() {
        getVehicle();
        cout << "Enter model: ";
        cin.ignore();
        getline(cin, model);
        cout << "Enter number of seats: ";
        cin >> seats;
    }

    void showCar() {
        showVehicle();
        cout << "Model   : " << model << endl;
        cout << "Seats   : " << seats << endl;
    }
};

class ElectricCar : public Car {
    int batteryCapacity;   // in kWh
    int range;             // in km

public:
    void getElectricCar() {
        getCar();
        cout << "Enter battery capacity (kWh): ";
        cin >> batteryCapacity;
        cout << "Enter range (km): ";
        cin >> range;
    }

    void showElectricCar() {
        showCar();
        cout << "Battery : " << batteryCapacity << " kWh" << endl;
        cout << "Range   : " << range << " km" << endl;
    }
};

int main() {
    cout << "===== Single Inheritance: Person -> Student =====\n";
    Student s;
    s.getStudent();
    cout << "\n--- Student Details ---\n";
    s.showStudent();

    cout << "\n===== Multilevel Inheritance: Vehicle -> Car -> ElectricCar =====\n";
    ElectricCar e;
    e.getElectricCar();
    cout << "\n--- Electric Car Details ---\n";
    e.showElectricCar();

    return 0;
}