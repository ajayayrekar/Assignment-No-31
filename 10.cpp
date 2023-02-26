/*10. Consider two base classes
worker(int code, char name, float salary),
officer(float DA, HRA)
class manger(float TA(is 10% of salary), gross salary) is derived from both base
classes.
Write necessary member functions.*/

#include <iostream>
#include <string>

using namespace std;

class Worker {
protected:
    int code;
    string name;
    float salary;
public:
    Worker(int code, string name, float salary) : code(code), name(name), salary(salary) {}

    virtual void display() {
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Officer : public Worker {
protected:
    float DA;
    float HRA;
public:
    Officer(int code, string name, float salary, float DA, float HRA) : Worker(code, name, salary), DA(DA), HRA(HRA) {}

    virtual void display() {
        Worker::display();
        cout << "DA: " << DA << endl;
        cout << "HRA: " << HRA << endl;
    }
};

class Manager : public Officer {
protected:
    float TA;
    float grossSalary;
public:
    Manager(int code, string name, float salary, float DA, float HRA, float TA)
        : Officer(code, name, salary, DA, HRA), TA(TA), grossSalary(salary + DA + HRA + TA) {}

    virtual void display() {
        Officer::display();
        cout << "TA: " << TA << endl;
        cout << "Gross Salary: " << grossSalary << endl;
    }
};

int main() {
    Manager m(123, "John Doe", 50000, 10000, 5000, 5000);
    m.display();

    return 0;
}
