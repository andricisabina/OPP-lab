#include <iostream>

#include <iostream>
#include <string>
using namespace std;

//Virtual
// Abstract base class
class Shape {
public:
    // Constructor
    Shape(const string& name) : name_(name) {}

    // Pure virtual function to calculate area (abstract method)
    virtual double CalculateArea() const = 0;

    // Virtual function to display shape information
    virtual void DisplayDetails() const {
        cout << "Shape: " << name_ << endl;
    }

protected:
    string name_;
};

// Derived class for a circle
class Circle : public Shape {
public:
    // Constructor
    Circle(const string& name, double radius) : Shape(name), radius_(radius) {}

    // Override method to calculate the area of a circle
    double CalculateArea() const override {
        return 3.14 * radius_ * radius_;
    }

    // Override method to display information about the circle
    void DisplayDetails() const override {
        Shape::DisplayDetails();
        cout << "Type: Circle\nRadius: " << radius_ << endl;
    }

private:
    double radius_;
};

// Derived class for a rectangle
class Rectangle : public Shape {
public:
    // Constructor
    Rectangle(const string& name, double length, double width)
        : Shape(name), length_(length), width_(width) {}

    // Override method to calculate the area of a rectangle
    double CalculateArea() const override {
        return length_ * width_;
    }

    // Override method to display information about the rectangle
    void DisplayDetails() const override {
        Shape::DisplayDetails();
        cout << "Type: Rectangle\nLength: " << length_ << "\nWidth: " << width_ << endl;
    }

private:
    double length_;
    double width_;
};

int main() {
    // Creating an object of type Circle and calling virtual methods
   //ircle circle("My Circle", 5.0);
  //circle.DisplayDetails();
  //cout << "Area: " << circle.CalculateArea() << endl;

  //cout << "\n------------------------\n";

    // Creating an object of type Rectangle and calling virtual methods
  //Rectangle rectangle("My Rectangle", 4.0, 6.0);
  //rectangle.DisplayDetails();
  //cout << "Area: " << rectangle.CalculateArea() << endl;

    //Implementare vector de 4 elemente care sa contina atat obiecte sircle cat si rectangle si sa evidentiez apelul moetedeloer virtuale/ pur vitrtuale


    Shape* v[4];
    //Shape **v;
    //v= new Shape*[4];
    v[0] = new Circle('c1', 12);
    v[1] = new Rectangle ('r1', 10, 9);
    v[2] = new Rectangle('r2', 3, 16);
    v[0] = new Circle('c2', 6);

    v[0]->DisplayDetails();
    v[1]->DisplayDetails();
    v[2]->DisplayDetails();
    v[3]->DisplayDetails();
   

    return 0;
}
