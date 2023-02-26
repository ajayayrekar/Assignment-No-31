/*8 - In a bank, different customers have savings account. Some customers may
have taken a loan from the bank. So bank always maintain information about
bank depositors and borrowers.
Design a Base class Customer (name, phone-number). Derive a class
Depositor(accno, balance) from Customer.
Again, derive a class Borrower (loan-no, loan-amt) from Depositor.
Write necessary member functions to read and display the details of ‘n’
customers.*/

#include<iostream>
using namespace std;

// Base Class
class Customer{
protected:
    string name;
    string phone;
public:
    void read(){
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Phone Number: ";
        cin >> phone;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phone << endl;
    }
};

// Derived Class 1
class Depositor : public Customer{
protected:
    int accNo;
    float balance;
public:
    void read(){
        Customer::read();
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Balance: ";
        cin >> balance;
    }
    void display(){
        Customer::display();
        cout << "Account Number: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived Class 2
class Borrower : public Depositor{
protected:
    int loanNo;
    float loanAmt;
public:
    void read(){
        Depositor::read();
        cout << "Enter Loan Number: ";
        cin >> loanNo;
        cout << "Enter Loan Amount: ";
        cin >> loanAmt;
    }
    void display(){
        Depositor::display();
        cout << "Loan Number: " << loanNo << endl;
        cout << "Loan Amount: " << loanAmt << endl;
    }
};

int main(){
    int n;
    cout << "Enter the number of customers: ";
    cin >> n;
    Borrower b[n]; // Array of Borrower objects
    for(int i=0;i<n;i++){
        cout << "\nEnter Details of Customer " << i+1 << endl;
        b[i].read();
    }
    cout << "\nCustomer Details:\n";
    for(int i=0;i<n;i++){
        cout << "\nCustomer " << i+1 << endl;
        b[i].display();
    }
    return 0;
}
