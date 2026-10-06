#include <iostream>
#include <string>
using namespace std;

class Employee {
    int id;
    string name;
    float salary, bonus;

public:
    // default constructor
    Employee() {
        id = 0;
        name = "Not Assigned";
        salary = 0;
        bonus = 0;
    }

    // parameterized constructor
    Employee(int i, string n, float s, float b) {
        id = i;
        name = n;
        salary = s;
        bonus = b;
    }

    float totalSalary() {
        return salary + bonus;
    }

    void display() {
        cout << "ID           : " << id << endl;
        cout << "Name         : " << name << endl;
        cout << "Basic Salary : " << salary << endl;
        cout << "Bonus        : " << bonus << endl;
        cout << "Total Salary : " << totalSalary() << endl;
    }
};

int main() {
    Employee e1;                                    // default constructor
    Employee e2(101, "Rahul", 30000, 5000);         // parameterized constructor

    cout << "--- Employee 1 (Default) ---\n";
    e1.display();
    cout << "\n--- Employee 2 (Parameterized) ---\n";
    e2.display();
    return 0;
}