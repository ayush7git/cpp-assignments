#include <iostream>
#include <string>
using namespace std;

class Student {
    int rollNo;
    string name;
    float marks[3];
    float total, percentage;

public:
    void accept() {
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter marks of 3 subjects: ";
        for (int i = 0; i < 3; i++)
            cin >> marks[i];
    }

    void calculate() {
        total = 0;
        for (int i = 0; i < 3; i++)
            total += marks[i];
        percentage = total / 3;
    }

    void display() {
        cout << "\n--- Student Details ---\n";
        cout << "Roll No    : " << rollNo << endl;
        cout << "Name       : " << name << endl;
        cout << "Total      : " << total << endl;
        cout << "Percentage : " << percentage << "%" << endl;
        cout << "Result     : " << (percentage >= 40 ? "PASS" : "FAIL") << endl;
    }
};

int main() {
    Student s;
    s.accept();
    s.calculate();
    s.display();
    return 0;
} 