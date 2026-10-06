#include <iostream>
using namespace std;

class Rectangle {
    float length, breadth;   // private data members

public:
    // defined inside the class
    void setData(float l, float b) {
        length = l;
        breadth = b;
    }

    float area() {
        return length * breadth;
    }

    // declared here, defined outside
    float perimeter();
    void display();
};

// defined outside the class
float Rectangle::perimeter() {
    return 2 * (length + breadth);
}

void Rectangle::display() {
    cout << "Length    : " << length << endl;
    cout << "Breadth   : " << breadth << endl;
    cout << "Area      : " << area() << endl;
    cout << "Perimeter : " << perimeter() << endl;
}

int main() {
    Rectangle r;
    float l, b;
    cout << "Enter length and breadth: ";
    cin >> l >> b;
    r.setData(l, b);
    r.display();
    return 0;
}