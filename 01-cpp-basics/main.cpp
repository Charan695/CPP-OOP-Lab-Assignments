#include <iostream>
#include <string>
using namespace std;

int main() {
    int age = 19;
    float height = 175.5f;
    double percentage = 88.75;
    char grade = 'A';
    bool enrolled = true;
    string name = "Student";
    const double PI = 3.14159;

    cout << "===== C++ Fundamentals =====\n";
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;

    cout << "\n--- Data Types and Variables ---\n";
    cout << "Name: " << name << "\nAge: " << age
         << "\nHeight: " << height << "\nPercentage: " << percentage
         << "\nGrade: " << grade << "\nEnrolled: " << boolalpha << enrolled
         << "\nConstant PI: " << PI << '\n';

    int a = 12, b = 5;
    cout << "\n--- Arithmetic Operators ---\n";
    cout << "a + b = " << a + b << '\n';
    cout << "a - b = " << a - b << '\n';
    cout << "a * b = " << a * b << '\n';
    cout << "a / b = " << a / b << " (integer division)\n";
    cout << "a % b = " << a % b << '\n';
    cout << "\n--- Relational and Logical Operators ---\n";
    cout << "a > b: " << (a > b) << '\n';
    cout << "(a > 10 && b < 10): " << (a > 10 && b < 10) << '\n';
    int counter = 0;
    cout << "Before increment: " << counter << '\n';
    cout << "After increment: " << ++counter << '\n';
    return 0;
}
