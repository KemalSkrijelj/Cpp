#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Rectangle{
  double h, v;
  public:
  Rectangle(double sideHoriznotal, double sideVertical){ Set(sideHoriznotal, sideVertical);}

  void Set(double sideHoriznotal, double sideVertical){
    if(sideHoriznotal <= 0 || sideVertical <= 0){
      throw domain_error("One of side is negative or 0!!");
    }
    h = sideHoriznotal ;
    v = sideVertical;
  }
  double getHorizontal() const {return h;}
  double getVertical() const {return v;}
  double getCircumference() const {
    return 2*(h+v);
  }
  double getArea() const {
    return h*v;
  }
  bool isSquare() const {
    if(h == v){return true;}
    return false;
  }
  bool isHorizontalyAligned() const {
    if(h > v){ return true; }
    return false;
  }
  void scale(double scaleHoriznotal, double scaleVertical){
    Set(scaleHoriznotal * h, scaleVertical * v);
  }
  void Rotate(){
    double temp = h;
    h = v;
    v = temp;
  }
  void Display()  {
    cout << "H: " << getHorizontal() << endl 
            << "V: " << getVertical() << endl 
            << "Ciricumference: " << getCircumference() << endl 
            << "Area: " << getArea() << endl 
            << "Is square: " << boolalpha << isSquare() << endl 
            << "Is horiznotal aligned: " << boolalpha << isHorizontalyAligned() << endl;
  }
};



class Square{
  double a;
  public:
  Square(double side){ Set(side);}
  void Set(double side){
    if (side <= 0) throw domain_error("Side must be positive!");
    a = side;
  }
  double getSide() const {return a;}
  double getCircumference() const {return 4 * a;};
  double getArea() const {return a * a;};
  void scale(double factor){
    Set(a*factor);
  }
  void display() const {
    cout << "Square: " << endl 
         << "side:" << getSide() << endl
         << "circumference: " << getCircumference() << endl
         << "area: " << getArea() << endl;
  }
};

class Pyramid{
 Square base;
 double height;
 void setHeight(double h){
  if (h <=0) throw domain_error("Bad input!");
  height = h;
 }
 public:
 Pyramid(double a, double h) : base(a) {setHeight(h);} // za broj
 void Set(double a, double h){
  base.Set(a);
  setHeight(h);
 }
 Pyramid(Square b, double h) : base(b){setHeight(h);} // za vec zavresn objekat u mainu

 double getSideOfBase() const {return base.getSide();}
 double getHeight() const {return height;}
 Square getBase() const {return base;}

 double getArea() const {
  double a = base.getSide();
  return a*a + height * sqrt(a*a + 4* height*height);
 }

 double GetVolume() const {
  double a = base.getSide();
  return a*a*height/3;
 }

 void scale(double factorBase, double factorHeight){
  double a = base.getSide();
  Set(a*factorBase, height * factorHeight);
 }
 void display() const {
  cout << "Pyramid: " << endl
       << "length of the base: " << getSideOfBase() << endl
       << "height: " << getHeight() << endl
       << "area: " << getArea() << endl
       << "volume: " << GetVolume() << endl;
 }
};


int main(){
  Square s1(5);
  s1.display();
  s1.scale(2);
  cout << " " << endl;
  cout << "After scaling: " << endl;
  cout << " " << endl;
  s1.display();

  Pyramid p(10,20);
  p.display();
  p.scale(2,2);
  cout << " " << endl;
  cout << "After scaling: " << endl;
  cout << " " << endl;
  p.display();

  /*
  Rectangle r1(5,3);
  r1.Display();
  r1.Rotate();
  cout << "After Rotate: " << endl;
  r1.Display();   
  */

  return 0;
}