#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    int englishMarks;
    int mathMarks;
    int scienceMarks;
    double average;
    char grade;

public:
    Student(int roll, const string& n, int eng, int math, int sci) {
        rollNumber = roll;
        name = n;
        englishMarks = eng;
        mathMarks = math;
        scienceMarks = sci;
        calculateAverage();
    }

    void calculateAverage() {
        average = static_cast<double>(englishMarks + mathMarks + scienceMarks) / 3.0;
        if (average >= 90) {
            grade = 'A';
        } else if (average >= 75) {
            grade = 'B';
        } else if (average >= 60) {
            grade = 'C';
        } else {
            grade = 'F';
        }
    }

    void display() const {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "English Marks: " << englishMarks << endl;
        cout << "Math Marks: " << mathMarks << endl;
        cout << "Science Marks: " << scienceMarks << endl;
        cout << "Average Marks: " << fixed << setprecision(2) << average << endl;
        cout << "Grade: " << grade << endl;
        cout << "--------------------------" << endl;
    }

    int getRollNumber() const {
        return rollNumber;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void displayAllStudents() const {
        for (const Student& student : students) {
            student.display();
        }
    }

    void deleteStudent(int rollNumber) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getRollNumber() == rollNumber) {
                students.erase(it);
                cout << "Student with Roll Number " << rollNumber << " deleted successfully." << endl;
                return;
            }
        }
        cout << "Student with Roll Number " << rollNumber << " not found." << endl;
    }
};

int main() {
    StudentManager studentManager;

    char choice;
    do {
        cout << "Student Report Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int roll;
                string name;
                int eng, math, sci;

                cout << "Enter Roll Number: ";
                cin >> roll;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter English Marks: ";
                cin >> eng;
                cout << "Enter Math Marks: ";
                cin >> math;
                cout << "Enter Science Marks: ";
                cin >> sci;

                Student student(roll, name, eng, math, sci);
                studentManager.addStudent(student);
                cout << "Student added successfully." << endl;
                break;
            }

            case '2':
                studentManager.displayAllStudents();
                break;

            case '3': {
                int roll;
                cout << "Enter Roll Number to Delete: ";
                cin >> roll;
                studentManager.deleteStudent(roll);
                break;
            }

            case '4':
                cout << "Exiting Student Report Management System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != '4');

    return 0;
}
