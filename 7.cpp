/*7. Write class declarations and member function definitions for a C++ base
class to represent an Employee (emp-code, name).
Derive two classes as Fulltime (daily rate, number of days, salary) and
Parttime (number of working hours, hourly rate, salary).
Write a menu driven program to:
1. Accept the details of ‘n’ employees.
2. Display the details of ‘n’ employees.

3. Search a given Employee by emp-code.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
protected:
    string name;
    int empCode;
public:
    Employee() {}
    Employee(int code, string name) : empCode(code), name(name) {}
    virtual void input() {
        cout << "Enter employee code: ";
        cin >> empCode;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
    }
    virtual void display() {
        cout << "Employee code: " << empCode << endl;
        cout << "Name: " << name << endl;
    }
    int getCode() { return empCode; }
};

class Fulltime : public Employee {
private:
    int dailyRate;
    int numDays;
    int salary;
public:
    Fulltime() {}
    void input() override {
        Employee::input();
        cout << "Enter daily rate: ";
        cin >> dailyRate;
        cout << "Enter number of days: ";
        cin >> numDays;
        salary = dailyRate * numDays;
    }
    void display() override {
        Employee::display();
        cout << "Daily rate: " << dailyRate << endl;
        cout << "Number of days: " << numDays << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Parttime : public Employee {
private:
    int numHours;
    int hourlyRate;
    int salary;
public:
    Parttime() {}
    void input() override {
        Employee::input();
        cout << "Enter number of working hours: ";
        cin >> numHours;
        cout << "Enter hourly rate: ";
        cin >> hourlyRate;
        salary = numHours * hourlyRate;
    }
    void display() override {
        Employee::display();
        cout << "Number of working hours: " << numHours << endl;
        cout << "Hourly rate: " << hourlyRate << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    int choice, code;
    vector<Employee*> employees;
    while (true) {
        cout << "\n1. Add employee\n2. Display all employees\n3. Search by code\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\n1. Fulltime\n2. Parttime\n";
            cout << "Enter employee type: ";
            cin >> choice;
            Employee* emp;
            if (choice == 1)
                emp = new Fulltime();
            else
                emp = new Parttime();
            emp->input();
            employees.push_back(emp);
            break;
        }
        case 2: {
            if (employees.size() == 0) {
                cout << "No employees found.\n";
                break;
            }
            for (Employee* emp : employees) {
                emp->display();
                cout << endl;
            }
            break;
        }
        case 3: {
            if (employees.size() == 0) {
                cout << "No employees found.\n";
                break;
            }
            cout << "Enter employee code: ";
            cin >> code;
            bool found = false;
            for (Employee* emp : employees) {
                if (emp->getCode() == code) {
                    emp->display();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Employee not found.\n";
            break;
        }
        case 4:
            return 0;
        default:
            cout << "Invalid choice.\
