#include <iostream>     // Standard input-output stream header file
#include <algorithm>    // For STL algorithms like sort and find
#include <vector>       // For vector container
#include <string>       // For using std::string
using namespace std;

class Item {
public:
    string name;  // Changed from char array to string for better input handling
    int quantity;
    int cost;
    int code;

    // Overloading equality operator
    bool operator==(const Item& i1) const {
        return code == i1.code; // Check if codes are equal
    }

    // Overloading less-than operator for sorting
    bool operator<(const Item& i1) const {
        return code < i1.code; // Compare based on code
    }
};

vector<Item> o1;  // Global vector to store Item objects

void print(Item& i1);
void display();
void insert();
void search();
void dlt();
bool compare(const Item& i1, const Item& i2) {
    return i1.cost < i2.cost; // Compare items by cost
}

int main() {
    int ch;
    do {
        cout << "\n* * * * * Menu * * * * *";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Sort";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;

        case 4:
            sort(o1.begin(), o1.end(), compare);
            cout << "\n\nSorted on Cost:";
            display();
            break;

        case 5:
            dlt();
            break;

        case 6:
            exit(0);

        default:
            cout << "\nInvalid choice. Please try again.";
        }

    } while (ch != 6);

    return 0;
}

// Function to insert an item
void insert() {
    Item i1;
    cout << "\nEnter Item Name: ";
    cin >> i1.name;
    cout << "Enter Item Quantity: ";
    cin >> i1.quantity;
    cout << "Enter Item Cost: ";
    cin >> i1.cost;
    cout << "Enter Item Code: ";
    cin >> i1.code;
    o1.push_back(i1);
}

// Function to display all items
void display() {
    for_each(o1.begin(), o1.end(), print);
}

// Function to print a single item
void print(Item& i1) {
    cout << "\nItem Name: " << i1.name;
    cout << "\nItem Quantity: " << i1.quantity;
    cout << "\nItem Cost: " << i1.cost;
    cout << "\nItem Code: " << i1.code;
    cout << "\n";
}

// Function to search for an item by code
void search() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to search: ";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end()) {
        cout << "\nNot found!";
    } else {
        cout << "\nFound!";
        print(*p); // Display found item
    }
}

// Function to delete an item by code
void dlt() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to delete: ";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end()) {
        cout << "\nNot found!";
    } else {
        o1.erase(p);
        cout << "\nDeleted!";
    }
}

