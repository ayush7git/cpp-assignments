#include <iostream>
using namespace std;

// ---------- Part A: static data member and static member function ----------
class Counter {
    static int count;   // shared by all objects
    int id;

public:
    Counter() {
        count++;
        id = count;
    }

    static void showCount() {   // static member function
        cout << "Total objects created: " << count << endl;
    }

    void showId() {
        cout << "Object id: " << id << endl;
    }
};

int Counter::count = 0;   // definition of static member

// ---------- Part B: friend function comparing private data of two classes ----------
class B;   // forward declaration

class A {
    int value;
public:
    A(int v) { value = v; }
    friend void compare(A, B);
};

class B {
    int value;
public:
    B(int v) { value = v; }
    friend void compare(A, B);
};

void compare(A a, B b) {
    if (a.value > b.value)
        cout << "A (" << a.value << ") is greater than B (" << b.value << ")\n";
    else if (a.value < b.value)
        cout << "B (" << b.value << ") is greater than A (" << a.value << ")\n";
    else
        cout << "A and B are equal (" << a.value << ")\n";
}

// ---------- Part C: friend class accessing private members ----------
class Account {
    int balance;
public:
    Account(int b) { balance = b; }
    friend class Auditor;   // Auditor can access private members
};

class Auditor {
public:
    void showBalance(Account &acc) {
        cout << "Auditor sees balance: " << acc.balance << endl;
    }
};

int main() {
    cout << "--- Static members ---\n";
    Counter c1, c2, c3;
    c1.showId();
    c3.showId();
    Counter::showCount();

    cout << "\n--- Friend function ---\n";
    A a(50);
    B b(30);
    compare(a, b);

    cout << "\n--- Friend class ---\n";
    Account acc(10000);
    Auditor aud;
    aud.showBalance(acc);

    return 0;
}