#include <iostream>
#include <cmath>

using namespace std;

class Square{
  double side;
  public:
  Square(double x){ Set(x); }

  void Set(double x){
    if(x <= 0){
      throw domain_error("Bad input! ");
    }
    side = x;
  }

  double getSide() const {return side;}
  double getCircumference() const { return 4*side; }
  double getArea() const { return side*side; }
  void Scale(double factor){
    Set(side*factor);
  }
  void Display() const{
    cout << endl <<
    "Side: " << getSide() << endl <<
    "Circumference: " << getCircumference() << endl <<
    "Area: " << getArea() << endl;
  }
};

class Pyramid{
  double height;
  Square base;
  void setHeight(int h){
    if(h <= 0){
      throw domain_error("Bad input! ");
    }
    height = h;
  }
  public:
  Pyramid(double b, double h): base(b) { setHeight(h); }
  void Set(double a, double h){
    base.Set(a);
    setHeight(h);
  }
  Pyramid(Square base, double h) : base(base) { setHeight(h); }
  void Set(Square a, double h){
    base = a;
    setHeight(h);
  }
  double getSideOfBase() const { return base.getSide(); }
  double getHeight() const { return height; }
  Square getBase() const { return base; }

  double getArea() const {
    double a = base.getSide();
    return a*a + height*sqrt(a*a + 4*height*height); 
  }
  double getVolume() const {
    double a = base.getSide();
    return a*a*height/3;
  }

  void Scale(double factor1, double factor2){
    Set(getSideOfBase() * factor1, getHeight() * factor2);
  }
  void Display() const{
    cout << endl <<
    "Side of base: " << getSideOfBase() << endl <<
    "Height: " << getHeight() << endl <<
    "Area: " << getArea() << endl <<
    "Volume: " << getVolume() << endl;
  }
};

int main(){
  Square b(5);
  b.Display();
  
  Pyramid p(3,2);
  p.Display();
  Pyramid p1(b, 5);
  p1.Display();
  return 0;
}