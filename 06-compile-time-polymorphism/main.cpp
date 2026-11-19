#include <iostream>
#include <string>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Function overloading: same name, different parameter lists.
    void print() const {
        cout << real << (imag < 0 ? " - " : " + ")
             << (imag < 0 ? -imag : imag) << 'i';
    }
    void print(const string& label) const {
        cout << label;
        print();
    }

    // Operator overloading for addition of two complex numbers.
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};

int main() {
    Complex first(3, 4), second(2, -5);
    Complex sum = first + second;
    cout << "===== Compile-time Polymorphism =====\n";
    first.print("First number: ");
    cout << '\n';
    second.print("Second number: ");
    cout << '\n';
    sum.print("Sum: ");
    cout << '\n';
    return 0;
}
