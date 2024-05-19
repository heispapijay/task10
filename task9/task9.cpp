#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.142;

class Shape {
protected:
    int a, b;

public:
    Shape() {}
    Shape(int a, int b) : a(a), b(b) {}

    int getA() const {
        return a;
    }

    int getB() const {
        return b;
    }

    void setA(int a) {
        this->a = a;
    }

    void setB(int b) {
        this->b = b;
    }

    virtual double getArea() const = 0; 
    virtual double getPerimeter() const = 0; 

    virtual ~Shape() {
        cout << "Shape destructor\n";
    }

    void displayInfo() const {
        cout << "Shape with dimensions: a = " << a << ", b = " << b << endl;
    }
};

class Rectangle : public Shape {
public:
    Rectangle() : Shape() {}
    Rectangle(int a, int b) : Shape(a, b) {}

    double getArea() const override {
        return static_cast<double>(a) * b;
    }

    double getPerimeter() const override {
        return 2 * (a + b);
    }

    ~Rectangle() override {
        cout << "Rectangle destructor\n";
    }
};

class Square : public Rectangle {
public:
    Square() : Rectangle() {}
    Square(int a) : Rectangle(a, a) {}

    ~Square() override {
        cout << "Square destructor\n";
    }
};

int main() {
    Square square(5);
    Rectangle rectangle(5, 10);

    square.displayInfo();
    cout << "Square area: " << square.getArea() << endl;
    cout << "Square perimeter: " << square.getPerimeter() << endl;
    cout << endl;

    rectangle.displayInfo();
    cout << "Rectangle area: " << rectangle.getArea() << endl;
    cout << "Rectangle perimeter: " << rectangle.getPerimeter() << endl;
    cout << endl;

    return 0;
}