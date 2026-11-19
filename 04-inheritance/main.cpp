#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(const string& n, int a) : name(n), age(a) {}
    void displayPerson() const {
        cout << "Name: " << name << "\nAge: " << age << '\n';
    }
};

// Single inheritance: Student inherits from Person.
class Student : public Person {
protected:
    string rollNumber;
    string course;
public:
    Student(const string& n, int a, const string& roll, const string& c)
        : Person(n, a), rollNumber(roll), course(c) {}
    void displayStudent() const {
        displayPerson();
        cout << "Roll number: " << rollNumber << "\nCourse: " << course << '\n';
    }
};

// Multilevel inheritance: GraduateStudent -> Student -> Person.
class GraduateStudent : public Student {
private:
    string researchTopic;
public:
    GraduateStudent(const string& n, int a, const string& roll,
                    const string& c, const string& topic)
        : Student(n, a, roll, c), researchTopic(topic) {}
    void displayGraduateStudent() const {
        displayStudent();
        cout << "Research topic: " << researchTopic << '\n';
    }
};

int main() {
    GraduateStudent student("Meera", 23, "PG2026", "M.Tech AI", "Machine Learning");
    cout << "===== University Management =====\n";
    student.displayGraduateStudent();
    return 0;
}
