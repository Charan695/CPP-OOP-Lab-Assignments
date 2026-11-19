#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// Abstract base class because area() is a pure virtual function.
class Shape {
public:
    virtual double area() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    explicit Circle(double r) : radius(r) {}
    double area() const override { return 3.141592653589793 * radius * radius; }
    void display() const override { cout << "Circle area: " << area() << '\n'; }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override { return length * width; }
    void display() const override { cout << "Rectangle area: " << area() << '\n'; }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override { return 0.5 * base * height; }
    void display() const override { cout << "Triangle area: " << area() << '\n'; }
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(5));
    shapes.push_back(make_unique<Rectangle>(4, 6));
    shapes.push_back(make_unique<Triangle>(3, 8));

    cout << "===== Runtime Polymorphism =====\n";
    for (const auto& shape : shapes) shape->display();
    return 0;
}
