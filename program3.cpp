#include <iostream>
#include <string>
using namespace std;

class Product {
    int id;
    string name;
    float price;
    int sales[12];   // monthly sales (quantity)

public:
    void accept() {
        cout << "Enter product id: ";
        cin >> id;
        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter price per unit: ";
        cin >> price;
        cout << "Enter monthly sales for 12 months: ";
        for (int i = 0; i < 12; i++)
            cin >> sales[i];
    }

    int totalQuantity() {
        int sum = 0;
        for (int i = 0; i < 12; i++)
            sum += sales[i];
        return sum;
    }

    float totalBill() {
        return totalQuantity() * price;
    }

    void display() {
        cout << "\nProduct ID     : " << id << endl;
        cout << "Name           : " << name << endl;
        cout << "Price          : " << price << endl;
        cout << "Total Quantity : " << totalQuantity() << endl;
        cout << "Total Bill     : " << totalBill() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    Product p[10];   // array of product objects (max 10)
    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        cout << "\n--- Product " << i + 1 << " ---\n";
        p[i].accept();
    }

    cout << "\n===== Product Details =====";
    for (int i = 0; i < n; i++)
        p[i].display();

    return 0;
}