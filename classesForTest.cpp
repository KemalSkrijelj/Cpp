#include <iostream>
#include <string>

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
int main(){
  Rectangle r1(5,3);
  r1.Display();
  r1.Rotate();
  cout << "After Rotate: " << endl;
  r1.Display();

  return 0;
}