/*5. Write a C++ program to define a base class Item (item-no, name, price).
Derive a class Discounted-Item (discount-percent). A customer purchases

'n' items. Display the item-wise bill and total amount using appropriate
format.*/

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

class Item {
protected:
    int item_no;
    string name;
    float price;

public:
    void getData() {
        cout << "Enter item number: ";
        cin >> item_no;
        cin.ignore();
        cout << "Enter item name: ";
        getline(cin, name);
        cout << "Enter item price: ";
        cin >> price;
    }

    void displayData() {
        cout << setw(10) << item_no << setw(20) << name << setw(10) << price << endl;
    }

    float getPrice() {
        return price;
    }
};

class Discounted_Item : public Item {
private:
    float discount_percent;

public:
    void getData() {
        Item::getData();
        cout << "Enter discount percentage: ";
        cin >> discount_percent;
    }

    void displayData() {
        Item::displayData();
        cout << setw(15) << "Discounted Price: " << setw(10) << price - ((discount_percent / 100) * price) << endl;
    }
};

int main() {
    int n;
    float total_amount = 0;
    vector<Discounted_Item> items;

    cout << "Enter the number of items: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        Discounted_Item item;
        item.getData();
        items.push_back(item);
        total_amount += item.getPrice() - ((item.getPrice() * item.discount_percent) / 100);
    }

    cout << endl;
    cout << setw(10) << "Item No." << setw(20) << "Item Name" << setw(10) << "Price" << setw(20) << "Discounted Price" << endl;
    cout << setw(10) << "--------" << setw(20) << "---------" << setw(10) << "-----" << setw(20) << "----------------" << endl;

    for (int i = 0; i < n; i++) {
        items[i].displayData();
    }

    cout << "\nTotal amount: " << total_amount << endl;

    return 0;
}
