/*6. Write a C++ program to demonstrate how a common friend function can
be used to exchange the private values of two classes. (Use call by
reference method).*/

#include<iostream>
using namespace std;

class ClassA; // Forward Declaration

class ClassB {
    int b;
public:
    ClassB() {
        b = 0;
    }
    void setData(int x) {
        b = x;
    }
    void displayData() {
        cout << "Value of B = " << b << endl;
    }
    friend void exchangeValues(ClassA&, ClassB&);
};

class ClassA {
    int a;
public:
    ClassA() {
        a = 0;
    }
    void setData(int x) {
        a = x;
    }
    void displayData() {
        cout << "Value of A = " << a << endl;
    }
    friend void exchangeValues(ClassA&, ClassB&);
};

void exchangeValues(ClassA& objA, ClassB& objB) {
    int temp = objA.a;
    objA.a = objB.b;
    objB.b = temp;
}

int main() {
    ClassA objA;
    ClassB objB;

    objA.setData(10);
    objB.setData(20);

    cout << "Before Exchange:" << endl;
    objA.displayData();
    objB.displayData();

    exchangeValues(objA, objB);

    cout << "\nAfter Exchange:" << endl;
    objA.displayData();
    objB.displayData();

    return 0;
}
