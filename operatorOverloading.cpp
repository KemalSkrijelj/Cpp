#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Auto{
  double a;
  public:
  Auto(){ a = 0; }
  Auto(double a){ Set(a); }
  void Set(double x){
    if(x <= 0){
      throw domain_error("Bad input!");
    }
    a = x;
  }

  Auto operator+(Auto objekat); //
  friend ostream& operator<<(ostream& out, Auto& obj);

};

Auto Auto::operator+(Auto objekat){
  return Auto( a + objekat.a);
}
ostream& operator<<(ostream& cout, Auto& obj){
  cout << obj.a;
  return cout;
}

int main(){
  Auto a1(5);
  Auto a2(3);
  Auto a3;
  a3 = a1 +a2;
  cout << a3;
  return 0;
}