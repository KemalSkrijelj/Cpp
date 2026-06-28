#include <iostream>
#include <cmath>

using namespace std;
const double PI = 4 * atan(1);


class RegularPolygon{
  int numOfSides;
  double length;
  public:
  RegularPolygon(int num, double l){ Set(num, l); }
  void Set(int num, double l){
    if(num < 3) throw range_error("Num of sides must be grather than 3!");
    if(l <= 0) throw range_error("Length must be positive");
    length = l;
    numOfSides = num;
  }
  int getNumOfSides() const { return numOfSides; }
  double getLength() const { return length; }
  double getInnerAngle() const { return 2*PI / numOfSides; }
  double getCircumference() const { return numOfSides*length; }
  double getArea() const { return numOfSides*length*length/ (4*tan(getInnerAngle()/2) ) ; }
  void Display() const {
    cout << "num of sides: " << numOfSides << endl <<
    "length of one side: " << length << endl <<
    "area: " << getArea() << endl <<
    "circumference: " << getCircumference() << endl;
  }
};

class Prism{
  RegularPolygon base;
  double height;
  public:
  Prism(RegularPolygon b, double h) : base(b) { Set(h);}
  void Set(double h){
    if(h < 3) throw range_error("Height must be positive");
    height = h;
  }
  Prism(int numOfSides, double sideLengthOfBase, double h) : base(numOfSides, sideLengthOfBase) {
    height = h;
  }
  void setBaseSideLength(double num, double l){
    if(num < 3) throw range_error("Num of sides must be grather than 3!");
    if(l <= 0) throw range_error("Length must be positive");
    base = RegularPolygon(num, l);
  }
  RegularPolygon getBase() const { return base; }
  double getSideLengthOfBase() const { return base.getLength(); }
  double getHeight() const { return height; }
  double getNumOfSides() const { return 2*base.getArea() + base.getNumOfSides(); }
  double getArea() const { return 2 * base.getArea() + ( base.getNumOfSides() * base.getLength() * height); }
  double getVolume() const { return base.getArea() * height; }
  void Display() const {
    cout << "height: " << height << endl <<
    "area of prism: " << getArea() << endl <<
    "volume of prism: " << getVolume() << endl <<
    "num of sides: " << getNumOfSides() << endl;
  }
};


class Vector{
  double x, y;
  public:
  Vector(double x, double y) { this->x = x; this->y = y; }
  void Set( double x, double y){ this->x = x; this->y = y; }
  double getX() const { return x; }
  double getY() const { return y; }
  double getLengthOfVector() const { return sqrt(pow(x,2)+ pow(y,2)); }
  friend Vector operator+(Vector ob1, Vector ob2);
  friend Vector operator-(Vector ob1, Vector ob2);
  friend Vector operator*(Vector ob1, double fact);
  friend Vector operator*(double fact, Vector ob2);
  friend double operator*(Vector ob1, Vector ob2);
  Vector& operator+=(const Vector &ob);
  Vector& operator-=(const Vector &ob);
  Vector& operator*=(const Vector &ob);
  Vector& operator++();
  Vector operator++(int);
  bool operator==(const Vector &ob);
  bool operator!=(const Vector &ob);
  friend ostream& operator<<(ostream &out, const Vector &ob);
};
Vector operator+(Vector ob1, Vector ob2){
  return Vector(ob1.x + ob2.x, ob1.y + ob2.y);
}
Vector operator-(Vector ob1, Vector ob2){
  return Vector(ob1.x - ob2.x, ob1.y - ob2.y);
}
Vector operator*(Vector ob1, double fact){
  return Vector(ob1.x * fact, ob1.y * fact);
}
Vector operator*(double fact, Vector ob2){
  return Vector(fact * ob2.x, fact * ob2.y);
}
double operator*(Vector ob1, Vector ob2){
  return ob1.x * ob2.x + ob1.y * ob2.y;
}
Vector& Vector::operator+=(const Vector &ob){
  x += ob.x;
  y += ob.y;
  return *this;
}
Vector& Vector::operator-=(const Vector &ob){
  x -= ob.x;
  y -= ob.y;
  return *this;
}
Vector& Vector::operator*=(const Vector &ob){
  x *= ob.x;
  y *= ob.y;
  return *this;
}
Vector& Vector::operator++(){
  double l = (getLengthOfVector()+1) / getLengthOfVector();
  x *= l;
  y *= l;
  return *this;
}
Vector Vector::operator++(int){
  Vector old = *this;
  ++(*this);
  return old;
}
bool Vector::operator==(const Vector &ob){
  return x == ob.x && y == ob.y;
}
bool Vector::operator!=(const Vector &ob){
  return !(x == ob.x && y == ob.y);
}
ostream& operator<<(ostream &out, const Vector &ob){
  out << "{" << ob.x << ", " << ob.y << "}";
  return out;
}

struct Pair { double x, y; };

class Pairs{
  int actualNum, maxNumOfPairs;
  Pair *data;
  public:
  Pairs(int capacity){
    actualNum = 0; maxNumOfPairs = capacity;
    data = new Pair[capacity];
  }
  ~Pairs() { delete[] data; }
  Pairs(const Pairs &p){
    actualNum = p.actualNum; maxNumOfPairs = p.maxNumOfPairs;
    data = new Pair[p.maxNumOfPairs];
    for (int i = 0; i < actualNum; i++) data[i] = p.data[i];
  }
  Pairs& operator=(const Pairs &p){
    if(&p != this){
      delete[] data;
      actualNum = p.actualNum; maxNumOfPairs = p.maxNumOfPairs;
      data = new Pair[p.maxNumOfPairs];
      for (int i = 0; i < actualNum; i++) data[i] = p.data[i];
    }
    return *this;
  }
  void Register(double x, double y){
    if(actualNum == maxNumOfPairs) throw range_error("FULL");
    for (int i = 0; i < actualNum; i++)
    {
      if(data[i].x == x) throw domain_error("Already exist!");
    }
    data[actualNum++] = {x,y};
  }
  void Delete(double x){
    for (int i = 0; i < actualNum; i++)
    {
      if(data[i].x == x){
        for (int j = i; j < actualNum-1; j++)
        {
          data[j] = data[j+1];
        }
        actualNum--;
        i--;
      }
    }
  }
  void Sort(){
    for (int i = 0; i < actualNum-1; i++)
    {
      for (int j = i+1; j < actualNum; j++)
      {
        if(data[i].x > data[j].x){
          Pair temp = data[i];
          data[i] = data[j];
          data[j] = temp;
        }
      }
    }
  }
  double& operator[](double x){
    for (int i = 0; i < actualNum; i++)
    {
      if(data[i].x == x) return data[i].y;
    }
    throw domain_error("Not exist!");
  }
  double operator[](double x) const {
    for (int i = 0; i < actualNum; i++)
    {
      if(data[i].x == x) return data[i].y;
    }
    throw domain_error("Not exist!");
  }
  void Display() const {
    for (int i = 0; i < actualNum; i++) cout << "{" << data[i].x << ", " << data[i].y << "}, ";
    cout << endl;
  }
};

int main(){
  Pairs p(4); 
  p.Register(2.3, 3.1);  p.Register(7.1, 4.4); p.Register(3.3, 2.1);  p.Register(5.6, 7.1);  

  p.Display();
  cout << endl;
  cout << "After sorting: " << endl;
  p.Sort();
  p.Display();
  
  cout << "p[7.1] return coresponding y: " << p[7.1] << endl;
  p.Delete(2.3);
  cout << "After deleting: " << endl;
  p.Display();
  
  Pairs p5 = p; // copy const

  
  /*Operator overloading..
  Vector v1(2.1, 3.5);
  cout << "v1: " << v1 << endl;
  Vector v2(3.5, 1.3);
  cout << "v2: " << v2 << endl;
  
  
  cout << boolalpha;
  cout << "v1 == v2" << (v1==v2) << endl;
  cout << "v1 != v2" << (v1!=v2) << endl;
  
  v1++;
  cout << "v1: " << v1 << endl;
  
  ++v2;
  cout << "v2: " << v2 << endl;
  */

  /* AGGREGATION
  RegularPolygon r(4, 3.5);
  cout << "Regular polygon: " << endl;
  r.Display();
  
  cout << endl;
  cout << "Prism: " << endl;
  Prism p(r, 3.1);
  p.Display();
  */
  return 0;
}