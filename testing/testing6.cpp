#include <iostream>
#include <string>

using namespace std;

class Shape
{
protected:
	double x;
	double y;

public:
	Shape(double xPos = 0, double yPos = 0) : x(xPos), y(yPos) {}

	virtual double area() const = 0;

	virtual void display() const
	{
		cout << "Position: (" << x << ", " << y << ")" << endl;
	}

	void setPosition(double xPos, double yPos)
	{
		x = xPos;
		y = yPos;
	}
	double getX() const { return x; }
	double getY() const { return y; }

	~Shape() {}
};

class Rectangle : public Shape
{
private:
	double length;
	double width;

public:
	Rectangle(double l = 0, double w = 0, double xPos = 0, double yPos = 0)
		: Shape(xPos, yPos), length(l), width(w) {}

	double area() const override
	{
		return length * width;
	}

	void display() const override
	{
		cout << "Rectangle Details:" << endl;
		Shape::display(); // Call base class display
		cout << "Length: " << length << endl;
		cout << "Width: " << width << endl;
		cout << "Area: " << area() << endl;
	}

	void setDimensions(double l, double w)
	{
		length = l;
		width = w;
	}

	double getLength() const { return length; }
	double getWidth() const { return width; }
};

int main()
{
	Rectangle r;
	//Shape *pShape = r; // This can only work if we are passing a address of r, not the object itself

	//Shape s(0, 1); // This cannot work because Shape is an obstract class because it contains a pure virtual function

	//Rectangle r = s;

	r.display();
}