#include <iostream>
#include <cstring>
using namespace std;

class Book {
    char *title;
    char *author;
    float price;

public:
    // parameterized constructor
    Book(const char *t, const char *a, float p) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        author = new char[strlen(a) + 1];
        strcpy(author, a);
        price = p;
        cout << "Parameterized constructor called\n";
    }

    // copy constructor (deep copy)
    Book(const Book &b) {
        title = new char[strlen(b.title) + 1];
        strcpy(title, b.title);
        author = new char[strlen(b.author) + 1];
        strcpy(author, b.author);
        price = b.price;
        cout << "Copy constructor called\n";
    }

    void display() {
        cout << "Title  : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Price  : " << price << endl;
    }

    // destructor
    ~Book() {
        cout << "Destructor called for: " << title << endl;
        delete[] title;
        delete[] author;
    }
};

int main() {
    Book b1("C++ Programming", "Bjarne Stroustrup", 599.50);
    Book b2 = b1;   // copy constructor

    cout << "\n--- Original Object ---\n";
    b1.display();
    cout << "\n--- Copied Object ---\n";
    b2.display();
    cout << "\n";
    return 0;
}