/*3. Write a C++ program to calculate the percentage of a student using multi-level
inheritance. Accept the marks of three subjects in base class. A class will be derived
from the above mentioned class which includes a function to find the total marks
obtained and another class derived from this class which calculates and displays the
percentage of students.*/

#include<iostream>
using namespace std;

class Marks {
protected:
    int mark1, mark2, mark3;

public:
    void getMarks() {
        cout << "Enter marks of three subjects: ";
        cin >> mark1 >> mark2 >> mark3;
    }
};

class Total : public Marks {
protected:
    int total;

public:
    void calculateTotal() {
        total = mark1 + mark2 + mark3;
    }
};

class Percentage : public Total {
public:
    void calculatePercentage() {
        float percent = (float)total / 3.0;
        cout << "Percentage: " << percent << "%" << endl;
    }
};

int main() {
    Percentage p;
    p.getMarks();
    p.calculateTotal();
    p.calculatePercentage();
    return 0;
}
