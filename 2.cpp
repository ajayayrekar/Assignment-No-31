/*2. Write a C++ program to add two numbers using single inheritance. Accept these two
numbers from the user in base class and display the sum of these two numbers in
derived class.*/

#include<iostream>
using namespace std;

class AddNumbers {
protected:
    int num1, num2;
public:
    void getNumbers() {
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
    }
};

class Sum : public AddNumbers {
public:
    void displaySum() {
        cout << "Sum: " << num1 + num2 << endl;
    }
};

int main() {
    Sum s;
    s.getNumbers();
    s.displaySum();
    return 0;
}
