#include <iostream>
#include <cmath>

using namespace std;
const double PI = 3.14159265358979323846;

class Point{
  double x,y;
  public:
  Point(): x(0), y(0){}
  Point(double x, double y){ Set(x,y); }
  void Set(double x, double y){
    this->x = x;
    this->y = y;
  }
  double getX() const { return x; }
  double getY() const { return y; }
  static bool isEqual(Point ob1, Point ob2);
  void Display() const;
};

bool Point::isEqual(Point ob1, Point ob2){
  return ob1.x == ob2.x && ob1.y == ob2.y;
}
void Point::Display() const {
  cout << 
  "( " << x << ", " << y << " )";
}

class Line{
  Point start;
  Point end;
  public:
  Line(Point s, Point e) : start(s), end(e) {}
  Line(double x1, double y1, double x2, double y2){
    start = Point (x1, y1);
    end = Point (x2, y2);
  }
  void Set(Point s, Point e){
    start = s;
    end = e;
  }
  void SetForReal(double x1, double y1, double x2, double y2){
    start = Point(x1, y1); // Point(x1,y1) create temporary value, and after copy to start object
    end = Point(x2, y2);
  }
  Point getStart() const { return start; } 
  Point getEnd() const { return end; }

  static bool isEqual(Line ob1, Line ob2); 
  static bool isEqualUndirect(Line ob1, Line ob2); 

  void Display() const;
};

bool Line::isEqual(Line ob1, Line ob2){
    return
    Point::isEqual(ob1.start, ob2.start) && // this compare line1 and line 2, ob1 and ob2 are line1 and line2
    Point::isEqual(ob1.end, ob2.end);
}

bool Line::isEqualUndirect(Line ob1, Line ob2){
   return
    (
        Point::isEqual(ob1.start, ob2.start) &&
        Point::isEqual(ob1.end, ob2.end)
    )
    ||
    (
        Point::isEqual(ob1.start, ob2.end) &&
        Point::isEqual(ob1.end, ob2.start)
    );
}
void Line::Display() const {
    start.Display();
    cout << " ";
    end.Display();
    cout << endl;
}

class Square{
  double length;
  public:
  Square(double l){ Set(l); }
  void Set(double l){
    if(l <= 0){
      throw domain_error("Bad input!");
    }
    length = l;
  }
  double GetSideLength() const { return length; }
  double GetCircumference() const { return 4 * length; }
  double GetArea() const { return length * length; }
  void Scale(double factor){ Set(factor*length); }
  void Display() const {
    cout << 
    "Length: " << length << endl <<
    "Circumference: " << GetCircumference() << endl <<
    "Area: " << GetArea() << endl;
  }
};

class Pyramid{
  Square base;
  double height;
  void SetHeight(double h){
    if( h <= 0){
      throw domain_error("Bad input!");
    }
    height = h;
  }
  public:
  Pyramid(double b, double h) : base(b) { SetHeight(h); }
  Pyramid(Square b, double h) : base(b), height(h) {}
  void Set(double b, double h){
    base = Square(b);
    height = h;
  }
  void Set(Square b, double h){
    base = b;
    height = h;
  }
  double GetBaseSideLength() const { return base.GetSideLength(); }
  double GetHeight() const { return height; }
  Square GetBase() const { return base; }
  double GetArea() const;
  double GetVolume() const;
  void Scale(double f1, double f2);
  void Display() const;
};
double Pyramid::GetArea() const {
  double b = base.GetSideLength();
  return b + height * sqrt(b+4*height*height);
}
double Pyramid::GetVolume() const {
  double b = base.GetSideLength();
  return b * height / 3;
}
void Pyramid::Scale(double f1, double f2){
  base.Scale(f1); height *= f2;
}

void Pyramid::Display() const{
  cout <<
  "Height: " << height << endl <<
  "Base: " << base.GetSideLength() << endl <<
  "Area: " << GetArea() << endl <<
  "Volume: " << GetVolume() << endl;
}


class Circle{
  double radius;
  public:
  Circle(double r) { Set(r); }
  void Set(double r){
    if(r <= 0){
      throw domain_error("Bad input!");
    }
    radius = r;
  }
  double GetRadius() const { return radius; }
  double GetArea() const { return radius*radius * PI;  }
  double GetCircumference() const { return 2*radius*PI; }
  void Scale(double scaler){
    if(scaler <= 0){
      throw domain_error("Bad scaler!");
    }
    radius *= scaler;
  }
  void Display() const;
};
void Circle::Display() const {
  cout << 
  "Radius: " << radius << endl <<
  "Area: " << GetArea() << endl <<
  "Circumference: " << GetCircumference() << endl;
}

class Cylinder{
  Circle base;
  double height;
  public:
  Cylinder(double b, double h) : base(b), height(h){
    if(b <= 0 || h <= 0){
      throw domain_error("Bad input!");
    }
  }
  void Set(double b, double h){
    if(b <= 0 || h <= 0){
      throw domain_error("Bad input of parameters!");
    }
    base = Circle(b);
    height = h;
  }
  double getRadiusBase() const { return base.GetRadius(); }
  double getHeight() const { return height; }
  Circle getBase() const { return base; }
  double getArea() const { return 2 * base.GetArea() + base.GetCircumference() * height; }
  double getVolume() const { return base.GetArea() * height; }
  void Scaling(double scForRadiusBase, double scForHeight);
  void Display() const;
};

void Cylinder::Scaling(double scForRadiusBase, double scForHeight){
   if(scForRadiusBase <= 0 || scForHeight <= 0){
      throw domain_error("Bad input of parameters!");
    }
  base.Scale(scForRadiusBase);  
  height *= scForHeight;
}
void Cylinder::Display() const{
  cout << 
  "Radius: " << base.GetRadius() << endl <<
  "Height: " << height << endl <<
  "Area: " << getArea() << endl <<
  "Volume: " << getVolume() << endl;
}



class RegularPolygon{
  int numOfSides;
  double lengthOfOne;
  public:
  RegularPolygon(int n, double l){
    if(n < 3 || l <= 0){
      throw domain_error("Bad input!");
    }
    numOfSides = n;
    lengthOfOne = l;
  }
  void SetSideLength(double l){
    if(l <= 0){
      throw domain_error("Bad input!");
    }
    lengthOfOne = l;
  }
  int GetNumberOfSides() const { return numOfSides; }
  double GetSideLength() const { return lengthOfOne; }
  double GetInnerAngle() const { return 2 * PI / numOfSides; }
  double GetCircumference() const { return numOfSides * lengthOfOne; }
  double GetArea() const;
};
double RegularPolygon::GetArea() const {
  double angle = GetInnerAngle();
  return numOfSides * lengthOfOne * lengthOfOne / ( 4*tan( angle / 2 ) );
}


class Prism{
  RegularPolygon base;
  double height;
  void SetHeightValidation(double h){
    if(h <= 0){
      throw domain_error("Incorect height");
    }
    height = h;
  }
  public:
  Prism(RegularPolygon b, double h) : base(b) { SetHeightValidation(h); }
  Prism(int numOfSides, double sideLengthOfBase, double h) : base(numOfSides, sideLengthOfBase) { SetHeightValidation(h); }
  void SetBaseSideLength(int numOfSides, double b){ base = RegularPolygon(numOfSides, b); }
  void SetHeight(double h) { SetHeightValidation(h); }
  RegularPolygon GetBase() const { return base; }
  double GetBaseSideLength() const { return base.GetSideLength(); }
  double GetHeight() const { return height; }
  double GetNumberOfSides() const { return 3 * base.GetNumberOfSides(); }
  double GetArea() const { return 2 * base.GetArea() + ( base.GetNumberOfSides() * base.GetSideLength() * height); }
  double GetVolume() const { return base.GetArea() * height; }
};


class Vertex{
  double x, y;
  public:
  Vertex(double x, double y){
    this->x = x;
    this->y = y;
  }
  Vertex& Set(double x, double y){
    this->x = x;
    this->y = y;
    return *this;
  }
  double GetX() const { return x; }
  double GetY() const { return y; }
  static double Distance(Vertex ob1, Vertex ob2);
  static bool isEqual(Vertex ob1, Vertex ob2);
};
double Vertex::Distance(Vertex ob1, Vertex ob2){
  return sqrt(pow(ob2.x - ob1.x,2) + pow(ob2.y - ob1.y,2));
}
bool Vertex::isEqual(Vertex ob1, Vertex ob2){
  return ob1.x == ob2.x && ob1.y == ob2.y;
}



class Triangle{
  Vertex v1;
  Vertex v2;
  Vertex v3;

public:
  Triangle(Vertex a, Vertex b, Vertex c) : v1(a), v2(b), v3(c) {
    if (Vertex::isEqual(a,b) ||
        Vertex::isEqual(a,c) ||
        Vertex::isEqual(b,c))
        throw domain_error("Vertices must be different");
  }

  Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
  : Triangle(Vertex(x1,y1), Vertex(x2,y2), Vertex(x3,y3)) {}

  Vertex GetVertex(int input) const;
  Triangle& SetVertex(int index, Vertex ob);
  Triangle& SetVertex(int index, double x, double y);
  double GetSideLength(int index) const;
  double GetCircumference() const;
  double GetArea() const;
};

Vertex Triangle::GetVertex(int input) const {
  if (input < 1 || input > 3)
      throw domain_error("Bad index");

  if (input == 1) return v1;
  if (input == 2) return v2;
  return v3;
}

Triangle& Triangle::SetVertex(int index, Vertex ob){
  if(index <=0 || index > 3){
     throw domain_error("Incorect input! ");
  }
  if (index == 1) v1 = ob;
  else if (index == 2) v2 = ob;
  else v3 = ob;

  return *this;
}

double Triangle::GetSideLength(int index) const {
  if (index < 1 || index > 3)
      throw domain_error("Bad index");

  if (index == 1)
      return Vertex::Distance(v2, v3);
  else if (index == 2)
      return Vertex::Distance(v1, v3);
  else
      return Vertex::Distance(v1, v2);
}

Triangle& Triangle::SetVertex(int index, double x, double y){
  return SetVertex(index, Vertex(x,y));
}

double Triangle::GetCircumference() const {
  return GetSideLength(1) +
         GetSideLength(2) +
         GetSideLength(3);
}

double Triangle::GetArea() const {
  double area =
    v1.GetX() * (v2.GetY() - v3.GetY()) -
    v2.GetX() * (v1.GetY() - v3.GetY()) +
    v3.GetX() * (v1.GetY() - v2.GetY());

  return abs(area) / 2.0;
}


int main(){

  Vertex a(0,0), b(3,0), c(0,4);

  Triangle t(a,b,c);

  cout << "Area: " << t.GetArea() << endl;
  cout << "Circumference: " << t.GetCircumference() << endl;

  t.SetVertex(1, 1, 1);

  cout << "New area: " << t.GetArea() << endl;

  /* Regular Polygon
  RegularPolygon p1(4, 2); 
  cout << "Polygon:" << endl;
  cout << "Sides: " << p1.GetNumberOfSides() << endl;
  cout << "Side length: " << p1.GetSideLength() << endl;
  cout << "Circumference: " << p1.GetCircumference() << endl;
  cout << "Area: " << p1.GetArea() << endl;
  
  cout << " " << endl;
  Prism prism1(p1, 5);
  cout << "Prism1:" << endl;
  cout << "Base sides: " << prism1.GetBaseSideLength() << endl;
  cout << "Height: " << prism1.GetHeight() << endl;
  cout << "Number of sides: " << prism1.GetNumberOfSides() << endl;
  cout << "Area: " << prism1.GetArea() << endl;
  cout << "Volume: " << prism1.GetVolume() << endl;
  */
  
  
  /* Circle and Cylinder
  Circle circle1(3);
  Circle circle2(4);
  
  cout << "Circle(C1): " << endl;
  circle1.Display();
  cout << "Circle(C2): " << endl;
  circle2.Display();
  
  cout << " " << endl;
  cout << "Cylinder: " << endl;
  Cylinder c1(2, 8);
  c1.Display();
  */


  /* Square and Pyramid
  Square s1(2);
  Pyramid p1(2,4);
  
  p1.Display();
  cout << "  " << endl;
  cout << "Pyramid 2: " << endl;
  Pyramid p2(s1,4);
  p2.Display();
  */


  /*  POINT AND LINE
  Point p1(1,2);
  Point p2(3,4);
  
  Line l1(p1,p2);
  Line l2(1,2,3,4);
  
  l1.Display();
  
  cout << Line::isEqual(l1,l2) << endl;
  */

  return 0;
}