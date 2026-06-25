#include <iostream>
#include <cmath>

using namespace std;
const double PI = 4 * atan(1);


class Student{
  string name, surname;
  int ID, yearOfStudy, gradesOfCourses[10];
  public:
  Student(string n, string s, int index) : name(n), surname(s){
    if(index <= 0){
      throw range_error("ID must be positive!");
    }
    yearOfStudy = 1;
    for (int i = 0; i < 10; i++)
    {
      gradesOfCourses[i] = 1;
    }
    ID = index;
  }
  string getName() const { return name; }
  string getSurname() const { return surname; }
  int getID() const { return ID; }
  int getYearOfStudy() const { return yearOfStudy; }
  void setGrade(int courseNum, int grade){
    if(courseNum < 1 || courseNum > 10 || grade < 1 || grade > 5){
      throw range_error("Error");
    }
    for (int i = 0; i < 10; i++)
    {
      if(courseNum - 1 == i){
        gradesOfCourses[i] = grade;
      }
    }
  }
  int getGrade(int courseNum){
    if(courseNum < 1 || courseNum > 10){
      throw domain_error("ERRORR");
    }
    return gradesOfCourses[courseNum - 1];
  }
  bool canPass(){
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
      if(gradesOfCourses[i] == 1){
        counter++;
      }
    }
    if(counter > 1){
      return false;
    }else{
      return  true;
    }
  }
  double getAvarage(){
    int sumOfGrades = 0;
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
      if(gradesOfCourses[i] == 1){
        sumOfGrades += 0;
      }else{
        counter++;
        sumOfGrades += gradesOfCourses[i];
      }
    }
    return (double)sumOfGrades / counter;
  }
  void toNextYear(){
      yearOfStudy++;
      for (int i = 0; i < 10; i++)
        gradesOfCourses[i] = 1;
  }
  void Display() const {
    cout << "Name:" << name << endl <<
    "surname: " << surname << endl <<
    "id: " << ID << endl <<
    "Year: " << yearOfStudy << endl;
  }
};

class Point{
  double x, y;
  public:
  Point() : x(0), y(0){}
  Point(double x, double y){
    Set(x,y);
  }
  void Set(double x, double y){
    this->x = x;
    this->y = y;
  }
  double getX() const { return x; }
  double getY() const { return y; }
  static bool isEqual(Point x, Point y){
    if(x.getX() == y.getX() && x.getY() == y.getY()){
      return true;
    }
    return false;
  }
  void Display() const {
    cout << "(" << x <<", " << y << ")";
  }
};

class Line{
  Point start;
  Point end;
  public:
  Line(Point ob1, Point ob2) : start(ob1), end(ob2) {}
  void SetLine(Point ob1, Point ob2){
    start = ob1;
    end = ob2;
  }
  Line(double x1, double y1, double x2, double y2){
    start = Point(x1, y1);
    end = Point(x2, y2);
  }
  void SetForReal(double x1, double y1, double x2, double y2){
    start = Point(x1,y1);
    end = Point(x2,y2);
  }
  Point getStart() const { return start; }
  Point getEnd() const { return end; }
  static bool isEqual(Line ob1, Line ob2){
    return Point::isEqual(ob1.getStart(), ob2.getStart()) && 
           Point::isEqual(ob1.getEnd(), ob2.getEnd());
  }
  static bool isEqualUndirect(Line ob1, Line ob2){
    return ( Point::isEqual(ob1.getStart(), ob2.getStart()) && 
             Point::isEqual(ob1.getEnd(), ob2.getEnd()))
      ||   ( Point::isEqual(ob1.getStart(), ob2.getEnd()) &&
             Point::isEqual(ob1.getEnd(), ob2.getStart()) );
  }
  void Display() const {
    cout << "(" << start.getX() << ", " << start.getY() << ")" << "-" << "(" << end.getX() <<", " << end.getY() << ")";
  }
};

class Square{
  double length;
  public:
  Square(double l){
    Set(l);
  }
  void Set(double l){
    if(l <= 0){
      throw domain_error("Invalid length!");
    }
    length = l;
  }
  double GetSideLength() const { return length; }
  double getCircumference() const { return 4*length; }
  double getArea() const { return length*length; }
  void Scale(double factor){
    Set(length * factor);
  }
  void Display() const {
    cout << "Length: " << length << endl <<
    "area: " << getArea() << endl <<
    "circumference: " << getCircumference() << endl;
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

  Pyramid(double lengthOfBase, double h) : base(lengthOfBase) { SetHeight(h); }
  Pyramid(Square b, double h) : base(b), height(h) {}

  void Set(double lengthOfBase, double h){
    base = Square(lengthOfBase);
    height = h;
  }
  void Set(Square b, double h){
    base = b;
    height = h;
  }
  double getBaseSideLength() const { return base.GetSideLength(); }
  double getHeight() const { return height; }
  Square getBase() const { return base; }
  double getArea() const;
  double getVolume() const;
  void Scale(double factor1, double factor2);
  void Display() const {
    cout << "area of pyramid: " << getArea() << endl <<
     "Volume of pyramid: " << getVolume() << endl <<
     "area of pyramid: " << getArea() << endl;
  }
};

double Pyramid::getArea() const {
  double areaOfBase = base.getArea();
  return areaOfBase + height * sqrt( areaOfBase + 4*(height*height) );
}
double Pyramid::getVolume() const {
  double areaOfBase = base.getArea();
  return areaOfBase * height / 3;
}
void Pyramid::Scale(double factor1, double factor2) {
  if(factor1 <= 0 || factor2 <= 0){
    throw domain_error("Invalid scaling factor.");
  }
  base.Scale(factor1);
  height *= factor2;
}

class Circle{
  double radius;
  public:
  Circle(double r) { Set(r); }
  void Set(double r){
    if(r <= 0){
      throw domain_error("error radius!");
    }
    radius = r;
  }
  double getRadius() const { return radius; }
  double getArea() const { return radius*radius * PI; }
  double getCircumference() const { return 2*PI*radius; }
  void Scale(double factor){
    Set(radius*factor);
  }
  void Display() const {
    cout << "radius: " << radius << endl <<
    "area for circle: " << getArea() << endl <<
    "circumference for circle: " << getCircumference() << endl;
  }
};

class Cylinder{
  Circle base;
  double height;
  public:
  Cylinder(double r, double h) : base(r) { Set(h); }
  void Set(double h){
    if(h <= 0){
      throw domain_error("error height!");
    }
    height = h;
  }
  double getRadius() const { return base.getRadius(); }
  double getHeight() const { return height; }
  Circle getBase() const { return base; }
  double getArea() const;
  double getVolume() const;
  void Scale(double fact1, double fact2);
  void Display() const;
};
double Cylinder::getArea() const {
  double areaOfBase = 2 * base.getArea();
  double circumOfBase = base.getCircumference();
  return areaOfBase + (circumOfBase*height);
}
double Cylinder::getVolume() const {
  double areaOfBase = base.getArea();
  return areaOfBase * height;
}
void Cylinder::Scale(double fact1, double fact2){
  if(fact1 <= 0 || fact2 <= 0){
    throw domain_error("Bad input of parameters!");
  }
  base.Scale(fact1);
  height *= fact2;
}
void Cylinder::Display() const {
  cout << "height: " << height << endl <<
  "area of cylinder: " << getArea() << endl << 
  "volume of cylinder: " << getVolume() << endl;
}

class RegularPolygon{
  int numOfSides;
  double length;
  public:
  RegularPolygon(int num, double l){
    if(num < 3 || l <= 0){
      throw domain_error("Invalid!");
    }
    numOfSides = num;
    length = l;
  }
  void SetSideLength(double l){
    if(l <= 0){
      throw domain_error("Bad input!");
    }
    length = l;
  }
  int getNumOfSides() const { return numOfSides; }
  int getLength() const { return length; }
  double getInnerAngle() const;
  double getArea() const;
  double getCircumference() const;
};

double RegularPolygon::getInnerAngle() const {
  return 2*PI /numOfSides;
}
double RegularPolygon::getArea() const {
  return numOfSides * pow(length, 2) / (4* tan( getInnerAngle()/2 ) );
}
double RegularPolygon::getCircumference() const {
  return numOfSides * length;
}

class Prism{
  RegularPolygon base;
  double height;
  public:
  Prism(RegularPolygon b, double h) : base(b) {
    if(h <= 0) throw domain_error("Height must be positive!");
    height = h;
  }
  Prism(int numOfS, double l, double h) : base(numOfS, l) {
    if(h <= 0) throw domain_error("Height must be positive!");
    height = h;
  }
  RegularPolygon getBase() const { return base; }
  double GetBaseSideLength() const { return base.getLength(); }
  double getHeight() const { return height; }
  double getNumOfSide() const { return 3 * base.getNumOfSides(); }
  void SetBaseSideLength(int numOfSides, double b) {  base = RegularPolygon(numOfSides, b); }
  void setHeight(double h) { height = h; }
  double getArea() const { return 2* base.getArea() + ( base.getNumOfSides() * base.getLength() * height); }
  double getVolume() const { return base.getArea() * height; }
  void Display() const;
};
void Prism::Display() const {
  cout << "length of base: " << GetBaseSideLength() << endl <<
  "height: " << height << endl << 
  "area: " << getArea() << endl << 
  "volume: " << getVolume() << endl; 
}

class Vertex{
  double x, y;
  public:
  Vertex(double x, double y) {
    this->x = x;
    this->y = y;
  }
  Vertex& Set(double x, double y){
    this->x = x;
    this->y = y;
    return *this;
  }
  double getX() const { return x; }
  double getY() const { return y; }
  static double Distance(Vertex ob1, Vertex ob2);
  static bool isEqual(Vertex ob1, Vertex ob2);
};
double Vertex::Distance(Vertex ob1, Vertex ob2){
  double d = 0;
  d = sqrt( pow(ob2.x- ob1.x, 2) + pow(ob2.y- ob1.y, 2) );
  return d;
}
bool Vertex::isEqual(Vertex ob1, Vertex ob2){
  if(ob1.x == ob2.x && ob1.y == ob2.y){
    return true;
  }
  return false;
}

class Triangle{
  Vertex v1;
  Vertex v2;
  Vertex v3;
  public:
  Triangle(Vertex ob1, Vertex ob2, Vertex ob3) : v1(ob1), v2(ob2), v3(ob3) {
    if(Vertex::isEqual(ob1, ob2) || Vertex::isEqual(ob1, ob3) || Vertex::isEqual(ob2, ob3)){
      throw domain_error("Vertices must be different");
    }
  }
  Triangle(double x1, double y1, double x2, double y2,double x3, double y3) : v1(x1, y1), v2(x2, y2), v3(x3, y3){}
  Vertex getVertex(int index){
    if (index < 1 || index > 3)
    {
      throw domain_error("Index must be in range 1 and 3!");
    }
    if(index == 1) return v1;
    if(index == 2) return v2;
    return v3;
  }
  Triangle& setVertex(int index, Vertex ob);
  Triangle& setVertex(int index, double x, double y);
  double getSideLength(int index) const;
  double getCircumference() const { return getSideLength(1) + getSideLength(2) + getSideLength(3); }
  double getArea() const;
};
Triangle& Triangle::setVertex(int index, Vertex ob){
  if (index < 1 || index > 3)
  {
    throw domain_error("Index must be in range 1 and 3!");
  }
  if(index == 1) v1 = ob;
  else if(index == 2) v2 = ob;
  else v3 = ob;
  
  return *this;
}
Triangle& Triangle::setVertex(int index, double x, double y){
  if (index < 1 || index > 3)
  {
    throw domain_error("Index must be in range 1 and 3!");
  }
  if(index == 1) v1 = Vertex(x, y);
  else if(index == 2) v2 = Vertex(x, y);
  else v3 = Vertex(x, y);

  return *this;
}
double Triangle::getSideLength(int index) const{
  if (index < 1 || index > 3)
    throw domain_error("Index must be in range 1 and 3!");
  
  if(index == 1) return Vertex::Distance(v2, v3);
  else if(index == 2) return Vertex::Distance(v1, v3);
  else return Vertex::Distance(v1,v2);

}

double Triangle::getArea() const {
  double area =
    v1.getX() * (v2.getY() - v3.getY()) -
    v2.getX() * (v1.getY() - v3.getY()) +
    v3.getX() * (v1.getY() - v2.getY());

  return abs(area) / 2.0;
}
int main(){
  Vertex v1(1.3, 4.3);
  cout <<"V1: "<< v1.getX() << ", " << v1.getY() << endl;
  Vertex v2(1.7, 3.3);
  cout <<"V1: "<< v2.getX() << ", " << v2.getY() << endl;
  Vertex v3(4.3, 2.3);
  cout <<"V1: "<< v3.getX() << ", " << v3.getY() << endl;

  Triangle t(v1,v2,v3);

  cout << "Area: " << t.getArea() << endl;
  cout << "Circumference: " << t.getCircumference() << endl;

  t.setVertex(1, 1, 1);

  cout << "New area: " << t.getArea() << endl;
  /*
  RegularPolygon r(3, 1.5);
  cout << "Length of regular polygon: "  <<  r.getLength() << endl;
  
  cout << "----------------------" << endl;
  
  Prism p(r, 3.5);
  p.Display();
  */

  /*
  Circle c(2.3);
  cout << "Information for circle: " << endl;
  c.Display();
  
  cout << "---------------------" << endl;
  Cylinder cylinderOb(3.2, 4);
  cout << "Information for cylinder: " << endl;
  cylinderOb.Display();
  */


  /*
  Square b(4);
  cout << "Square info: " << endl;
  b.Display();

  Pyramid p1(b, 10);
  cout << "Pyramid info:" << endl;
  p1.Display();
  cout << endl;
  cout << "Scaling pyramid..." << endl;
  p1.Scale(2, 3);
  cout << endl;
  
  cout << "After scaling:" << endl;
  p1.Display();
  */

  /*
  Point p1(3.3, 4.9);
  Point p2(1.3, 3.5);
  
  Line obj(p1, p2);
  obj.Display();
  */


  /*
  Student s("Kemal", "Skrijelj", 1221);
  s.setGrade(2,5);
  s.setGrade(1,2);
  s.setGrade(3,4);
  s.setGrade(5,5);
  s.setGrade(4,3);
  s.Display(); 
  cout << endl;
  cout << "Avarage: " <<s.getAvarage() << endl;
  cout << "Can pass year: " << boolalpha << s.canPass();
  */
  return 0;
}