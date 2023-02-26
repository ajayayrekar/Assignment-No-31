/*9. Write a C++ program to implement the following class hierarchy:
Student: id, name
StudentExam (derived from Student): Marks of 6 subjects
StudentResult (derived from StudentExam) : percentage
Define appropriate functions to accept and display details.
Create 'n' objects of the StudentResult class and display the marklist.*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
protected:
    int id;
    string name;
public:
    void setId(int i) { id = i; }
    void setName(string n) { name = n; }
    int getId() const { return id; }
    string getName() const { return name; }
};

class StudentExam : public Student {
protected:
    int marks[6];
public:
    void setMarks(int m[]) {
        for (int i = 0; i < 6; i++) {
            marks[i] = m[i];
        }
    }
    int* getMarks() { return marks; }
};

class StudentResult : public StudentExam {
private:
    float percentage;
public:
    void setPercentage() {
        int total = 0;
        for (int i = 0; i < 6; i++) {
            total += marks[i];
        }
        percentage = (float) total / 6;
    }
    float getPercentage() const { return percentage; }
    void display() const {
        cout << setw(5) << id << "  " << setw(10) << name << "  ";
        for (int i = 0; i < 6; i++) {
            cout << setw(5) << marks[i] << " ";
        }
        cout << "   " << fixed << setprecision(2) << percentage << "%" << endl;
    }
};
int main() {
    int choice, n, id, marks[6];
    string name;
    StudentResult sr[10];

    do {
        cout << "\nMenu\n";
        cout << "====\n";
        cout << "1. Enter student details\n";
        cout << "2. Display marklist\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of students: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter details of student " << i + 1 << endl;
                    cout << "ID: ";
                    cin >> id;
                    sr[i].setId(id);
                    cin.ignore();
                    cout << "Name: ";
                    getline(cin, name);
                    sr[i].setName(name);
                    cout << "Marks in 6 subjects: ";
                    for (int j = 0; j < 6; j++) {
                        cin >> marks[j];
                    }
                    sr[i].setMarks(marks);
                    sr[i].setPercentage();
                }
                break;
            case 2:
                cout << "\nMarklist\n";
                cout << "========\n";
                cout << setw(5) << "ID" << "  " << setw(10) << "Name" << "  ";
                for (int i = 1; i <= 6; i++) {
                    cout << "Sub" << i << " ";
                }
                cout << "   %\n";
                for (int i = 0; i < n; i++) {
                    sr[i].display();
                }
                break;
            case 3:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
