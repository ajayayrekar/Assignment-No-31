/*4. Write a C++ program to design a base class Person (name, address,
phone_no). Derive a class Employee (eno, ename) from Person. Derive a
class Manager (designation, department name, basic-salary) from
Employee. Write a menu driven program to:
a. Accept all details of 'n' managers.
b. Display manager having highest salary*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Person {
protected:
    string name;
    string address;
    string phone_no;
public:
    void getData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter phone number: ";
        getline(cin, phone_no);
    }
};

class Employee : public Person {
protected:
    int eno;
    string ename;

public:
    void getEmployeeData() {
        cout << "Enter employee number: ";
        cin >> eno;
        cin.ignore();
        cout << "Enter employee name: ";
        getline(cin, ename);
    }
};

class Manager : public Employee {
private:
    string designation;
    string dept_name;
    float basic_salary;

public:
    void getManagerData() {
        cout << "Enter designation: ";
        getline(cin, designation);
        cout << "Enter department name: ";
        getline(cin, dept_name);
        cout << "Enter basic salary: ";
        cin >> basic_salary;
        cin.ignore();
    }

    float getSalary() {
        return basic_salary;
    }

    void displayData() {
        cout << "Manager name: " << name << endl;
        cout << "Employee number: " << eno << endl;
        cout << "Employee name: " << ename << endl;
        cout << "Designation: " << designation << endl;
        cout << "Department name: " << dept_name << endl;
        cout << "Basic salary: " << basic_salary << endl;
    }
};

int main() {
    int n, choice;
    vector<Manager> managers;

    cout << "Enter the number of managers: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        Manager m;
        m.getData();
        m.getEmployeeData();
        m.getManagerData();
        managers.push_back(m);
    }

    do {
        cout << "\n1. Display Manager with highest salary\n2. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Manager highest_sal_manager = managers[0];
                for (int i = 1; i < n; i++) {
                    if (managers[i].getSalary() > highest_sal_manager.getSalary()) {
                        highest_sal_manager = managers[i];
                    }
                }
                cout << "\nManager with highest salary: \n";
                highest_sal_manager.displayData();
                break;
            }
            case 2: {
                cout << "Exiting...";
                break;
            }
            default: {
                cout << "Invalid choice. Try again." << endl;
            }
        }
    } while (choice != 2);

    return 0;
}
