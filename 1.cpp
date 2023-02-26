/*1. Define a class Person with instance members name and age. Also define member
functions setName(), setAge(), getName(), getAge(). Now define class Employee by
inheriting Person class. In the Employee class define empid and salary as instance
members. Also define setEmpid, setSalary, getEmpid, getSalary.*/

#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void setName(string n) {
        name = n;
    }
    void setAge(int a) {
        age = a;
    }
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
};

class Employee : public Person {
protected:
    int empid;
    float salary;

public:
    void setEmpid(int id) {
        empid = id;
    }
    void setSalary(float s) {
        salary = s;
    }
    int getEmpid() {
        return empid;
    }
    float getSalary() {
        return salary;
    }
};

int main() {
    Employee emp1;
    emp1.setName("John");
    emp1.setAge(25);
    emp1.setEmpid(123);
    emp1.setSalary(5000.0);

    cout << "Employee name: " << emp1.getName() << endl;
    cout << "Employee age: " << emp1.getAge() << endl;
    cout << "Employee ID: " << emp1.getEmpid() << endl;
    cout << "Employee salary: " << emp1.getSalary() << endl;

    return 0;
}
