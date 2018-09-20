#include <iostream>
#include <vector>

// Shape class
class Shape {
  public:
  virtual std::ostream& print(std::ostream& out) const = 0;
  
  
  friend std::ostream& operator<<(std::ostream& out, const Shape& shape) {
    return shape.print(out);
  }
  virtual ~Shape() {};
};

// Point class
class Point : public Shape {
  private:
  int m_x, m_y, m_z;
  public:
  Point(int x, int y, int z) : m_x(x), m_y(y), m_z(z) {}
  
  virtual std::ostream& print(std::ostream& out) const override {
    out << "Point(" << m_x << ", " << m_y << ", " << m_z << ")";
    return out;
  }
};

// Triangle class
class Triangle : public Shape {
  private:
    Point m_p1, m_p2, m_p3;
  public:
  Triangle(Point p1, Point p2, Point p3) : m_p1(p1), m_p2(p2), m_p3(p3) {}
  
  virtual std::ostream& print(std::ostream& out) const override {
    out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
    return out;
  }
};

// Circle class
class Circle : public Shape {
  private:
  Point m_center;
  int m_radius;
  
  public:
  Circle(Point center, int radius) : m_center(center), m_radius(radius) {}
  
  virtual std::ostream& print(std::ostream& out) const override {
    out << "Circle(" << m_center << ", " << m_radius << ")";
    return out;
  }
  
  int GetRadius() const {
    return m_radius;
  }
};

Circle getLargestRadius(std::vector<Shape*>& v) {
  int max_radius(0);
  Circle* max_shape(nullptr);
  for (const auto& e : v) {
    Circle* circle = dynamic_cast<Circle*> (e);
    if (circle != nullptr) {
      int this_radius = circle->GetRadius();
      if (this_radius > max_radius) {
        max_radius = this_radius;
        max_shape = circle;
      }
    }
  }
  if (max_shape != nullptr) {
    return *max_shape;
  }
  else return Circle(Point(0, 0, 0), 0);
}
 
int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));
 
	// print each shape in vector v on its own line here
	for (const auto& element : v) {
	  std::cout << *element << '\n';
	}
 
 	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function
 
	// delete each element in the vector here
}


