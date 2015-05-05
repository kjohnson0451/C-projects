/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * 
 *
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>

class Polygon {
protected:
  int width, height;
public:
  void set_values (int a, int b)
  { width=a; height=b;}
};

class Rectangle: public Polygon {
public:
  int area ()
  { return width * height; }
};

class Triangle: public Polygon {
public:
  int area ()
  { return width * height / 2; }
};
  
int main () {
  Rectangle rect;
  Triangle trgl;

  unsigned short width, height;

  std::cout << "Width: ";
  std::cin >> width;

  std::cout << "Height: ";
  std::cin >> height;

  rect.set_values (width,height);
  trgl.set_values (width,height);

  std::cout << "The area of the rectangle is " << rect.area() << '\n';
  std::cout << "The area of the triangle is "<< trgl.area() << '\n';
  return 0;
}
