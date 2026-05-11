#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Auto{
  double a, b;
  public:
  Auto() : a(0), b(0){}
  Auto(double a, double b){ Set(a,b); }

  void Set(double x, double y){
    if(x < 0 || y < 0){
      throw domain_error("Bad input!");
    }
    a = x;
    b = y;
  }
 
  friend Auto operator+(Auto objekatA, Auto objekatB);
  friend Auto operator-(Auto objekatA, Auto objekatB);
  friend Auto operator*(Auto objekatA, Auto objekatB);
  friend ostream& operator<<(ostream& out, const Auto& obj);

};

Auto operator+(Auto objekatA, Auto objekatB){
  return Auto(objekatA.a + objekatB.a, objekatA.b+ objekatB.b);
}
Auto operator-(Auto objekatA, Auto objekatB){
  return Auto(objekatA.a - objekatB.a, objekatA.b - objekatB.b); 
}
Auto operator*(Auto objekatA, Auto objekatB){
  Auto temp(objekatA.a * objekatB.a, objekatA.b * objekatB.b);  // this is same as a older operator functions...
  return temp;
}

ostream& operator<<(ostream &out, const Auto &obj){
  cout << "a: " << obj.a << " b: " << obj.b;
  return out; // this is a object which I write
}

//Vector
class Vector{
  double x, y, z;
  public:
  Vector() : x(0), y(0), z(0) {}
  Vector(double x, double y, double z) : x(x), y(y), z(z) {}
  double getX() const { return x; } 
  double getY() const { return y; } 
  double getZ() const { return z; }
  Vector &setX(double x1) { x = x1; return *this;} // We can do chaining
  Vector &setY(double y1) { y = y1; return *this;} // We can do chaining
  Vector &setZ(double z1) { z = z1; return *this;} // We can do chaining
  friend Vector operator+(const Vector& obj1, const Vector& obj2); // const and & are not strict, but it's okey to work with orginal not with objects
  Vector& operator+=(const Vector& v);   // must have & because we add on this element not on object
  friend Vector operator*(double p, const Vector& v); 
  Vector& operator*=(double p); 
  friend ostream& operator<<(ostream& out, const Vector& obj); // const and & must have

};

Vector operator+(const Vector& obj1, const Vector& obj2){
  return Vector(obj1.x + obj2.x , obj1.y + obj2.y, obj1.z + obj2.z);
}
Vector& Vector::operator+=(const Vector& v){
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}
Vector operator*(double p, const Vector& v){
  return Vector(p * v.x, p * v.y, p * v.z);
} 
Vector& Vector::operator*=(double p){
  x *= p;
  y *= p;
  z *= p;
  return *this;
}
ostream& operator<<(ostream& out, const Vector& obj){
  out << "( " << obj.x << ", " << obj.y << ", " << obj.z << " )";
  return out;  
}

//Complex Number
class ComplexNumber{
  double realNum, imagiNum;
  public:
  ComplexNumber() : realNum(0), imagiNum(0) {}
  ComplexNumber(double r, double i) : realNum(r), imagiNum(i) {}
  double getReal() const { return realNum; }
  double getImag() const { return imagiNum; }
  friend ComplexNumber operator+(ComplexNumber ob1, ComplexNumber ob2);
  ComplexNumber& operator+=(const ComplexNumber& ob);
  friend ComplexNumber operator*(double p, ComplexNumber ob);
  bool operator==(const ComplexNumber& ob) const;
  friend ostream& operator<<(ostream& out, const ComplexNumber& ob);
};

ComplexNumber operator+(ComplexNumber ob1, ComplexNumber ob2){
  return ComplexNumber(ob1.realNum + ob2.realNum, ob1.imagiNum + ob2.imagiNum);
}
ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& ob){
  realNum += ob.realNum;
  imagiNum += ob.imagiNum;
  return *this;
}
ComplexNumber operator*(double p, ComplexNumber ob){
  return ComplexNumber(p * ob.realNum, p * ob.imagiNum);
}
bool ComplexNumber::operator==(const ComplexNumber& ob) const {
  return realNum == ob.realNum && imagiNum == ob.imagiNum;
}
ostream& operator<<(ostream& out, const ComplexNumber& ob){
  out << "Real num: " << ob.realNum << ", imag: " << ob.imagiNum << endl;
  return out;
}

//Matrix
class Matrix2x2{
  double a,b,c,d;
  public:
  Matrix2x2() : a(0), b(0), c(0), d(0){}
  Matrix2x2(double a1, double b1, double c1,double d1) : a(a1), b(b1), c(c1), d(d1){}
  double getA() const { return a; }
  double getB() const { return b; }
  double getC() const { return c; }
  double getD() const { return d; }
  friend Matrix2x2 operator+(Matrix2x2 ob1, Matrix2x2 ob2);
  Matrix2x2& operator+=(const Matrix2x2& ob);
  friend Matrix2x2 operator*(double p, Matrix2x2 ob);
  Matrix2x2& operator*=(double p);
  friend ostream& operator<<(ostream& out, const Matrix2x2& obj);
};

Matrix2x2 operator+(Matrix2x2 ob1, Matrix2x2 ob2){
  return Matrix2x2(ob1.a + ob2.a,
                   ob1.b + ob2.b,
                   ob1.c + ob2.c,
                   ob1.d + ob2.d);
}

Matrix2x2& Matrix2x2::operator+=(const Matrix2x2& ob){
  a += ob.a;
  b += ob.b;
  c += ob.c;
  d += ob.d;
  return *this;
}

Matrix2x2 operator*(double p, Matrix2x2 ob){
  return Matrix2x2( p * ob.a,
                    p * ob.b,
                    p * ob.c,
                    p * ob.d);
}

Matrix2x2& Matrix2x2::operator*=(double p){
  a *= p;
  b *= p;
  c *= p;
  d *= p;
  return *this;
}

ostream& operator<<(ostream& out, const Matrix2x2& obj){
  out << "[ " << obj.a << ", " << obj.b << ", " << obj.c << ", " << obj.d << "]";
  return out;
}

class Rational{
  int num, den;
  public:
  Rational() : num(1), den(1) {}
  Rational(int n, int d) : num(n) {
    Set(d);
  }
  void Set(int d){
    if(d == 0){
     cout << "Error: Den can't be 0!";
     den = 1;
    }else{
      den = d;
    }
  }
  int getNum() const { return num; }
  int getDen() const { return den; }
  friend Rational operator+(Rational ob1, Rational ob2);
  Rational& operator+=(const Rational& ob);
  friend Rational operator*(Rational ob1, Rational ob2);
  Rational& operator*=(const Rational& ob);
  bool operator==(const Rational& ob) const;
  friend ostream& operator<<(ostream& out, const Rational& obj);
};

Rational operator+(Rational ob1, Rational ob2){
  return Rational(ob1.num * ob2.den + ob1.den * ob2.num, ob1.den * ob2.den);
}
Rational& Rational::operator+=(const Rational& ob){
  // num = num * ob.den + den * ob.num;
  // den = den * ob.den;  // same funcitional but this is longer way
  *this = *this + ob; //this is better way, because i was done operator+ before and when it see + it call operator+ func
  return *this;
}
Rational operator*(Rational ob1, Rational ob2){
  return Rational(ob1.num * ob2.num, ob1.den * ob2.den);
}

Rational& Rational::operator*=(const Rational& ob){
  num *= ob.num;
  den *= ob.den;
  return *this;
}

bool Rational::operator==(const Rational& ob) const {
  return num * ob.den == den * ob.num;
}

ostream& operator<<(ostream& out, const Rational& obj){
  out << obj.num << "/" << obj.den;
  return out;
}

class Time{
  int hours, minutes, seconds;
  public:
  Time(int h, int m, int s){ Set(h,m,s); }
  void Set(int h, int m, int s);
  friend Time operator+(Time ob1, Time ob2);
  Time &operator+=(const Time &ob);
  bool operator==(const Time &ob);
  bool operator>(const Time &ob);
  friend Time operator*(int p, Time ob);
  friend ostream& operator<<(ostream &out, const Time &ob);
};

void Time::Set(int h, int m, int s){
   while(s >= 60) { s -= 60; m++; }           
   while(s < 0) { s += 60; m--; }
   while(m >= 60) { m -= 60; h++; }
   while(m < 0) { m += 60; h--; }
   while(h >= 24) h -= 24;
   while(h < 0) h += 24;
   hours = h; minutes = m; seconds = s;
}

Time operator+(Time ob1, Time ob2){
  return Time(ob1.hours + ob2.hours, ob1.minutes + ob2.minutes, ob1.seconds + ob2.seconds);
}
Time& Time::operator+=(const Time &ob){
  Set(
    hours += ob.hours,
    minutes += ob.minutes,
    seconds += ob.seconds
  );
  return *this;
}

bool Time::operator==(const Time &ob){
  return hours == ob.hours && minutes == ob.minutes && seconds == ob.seconds;  
}
bool Time::operator>(const Time &ob){
  if(hours > ob.hours) return true;
  if(hours < ob.hours) return false;

  if(minutes > ob.minutes) return true;
  if(minutes < ob.minutes) return false;

  if(seconds > ob.seconds) return true;
  if(seconds < ob.seconds) return false;

  return false; // we must have last return
}

Time operator*(int p, Time ob){
  return Time(p * ob.hours, p * ob.minutes, p * ob.seconds);
}

ostream& operator<<(ostream &out, const Time &ob){
  out << ob.hours << ":" << ob.minutes << ":" << ob.seconds;
  return out;
}



int main(){
  Time t1(12,12,12);
  Time t2(13,45,55);
  
  cout << "t1: " << t1 << endl;
  cout << "t2: " << t2 << endl;

  Time t3 = t1 + t2;

  cout << "t3: " << t3 << endl;

  if(t1 == t2) cout << "T1 and T2 are same!!" << endl;
  else cout << "T1 and T2 are not same!" << endl;

  if(t2>t1){
    cout << "T2 is bigger than t1." << endl;
  }else{
    cout << "T2 is not bigger than t1." << endl;
  }

  t1 += Time(0, 50, 0); // increment for 50minutes
  cout << "Test +=: t1 after +50 min is " << t1 << endl;
  Time t4(0, 0, 5000);  
  cout << "Test normalization: 5000 seconds is: " << t4 << endl;

  /*Rational class
  Rational r1(1,2);
  Rational r2(3,4);
  
  cout << "r1: " << r1 << endl;
  cout << "r2: " << r2 << endl;
  
  Rational r3 = r1 + r2;
  
  cout << "r3: " << r3 << endl;
  
  if (r1 == r2) cout << "r1 and r2 are same, example: (1/2 == 2/4)" << endl;
  if (!(r1 == r3)) cout << "r1 and r3 are different" << endl;
  
  r1 += r2;
  cout << "After r1 +=r2, r1: " << r1 << endl;
  
  Rational r4;
  r4*= r2;
  cout << "After r4 *= r2, r4: " << r4 << endl;
  */

  /* MATRIX 2X2
  Matrix2x2 m1(1,2,3,4);
  Matrix2x2 m2(5,6,7,8);
  
  
  cout << "m1: " << m1 << endl;
  cout << "m2: " << m2 << endl;
  
  Matrix2x2 m3 = m1 + m2;
  cout << "m3(m1 + m2): " << m3 << endl;
  
  m1 += m2;
  cout << "After m1 += m2, m1: " << m1 << endl;
  
  Matrix2x2 m4 = 2.5 * m2;
  cout << "2.5 * m2: " << m4 << endl;
  
  m2 *= 2.0;
  cout << "After m2 *= 2.0, m2: " << m2 << endl;
  */


  /* COMPLEX NUMBER
  ComplexNumber c1(12.2, 2);
  ComplexNumber c2(10.2, 3);
  
  
  cout << "c1: " << c1 << endl;
  cout << "c2: " << c2 << endl;
  
  ComplexNumber c3 = c1 + c2;
  cout << "c3(c1 + c2): " << c3 << endl;
  
  c1 += c2;
  cout << "After c1 += c2, c1: " << c1 << endl;
  
  ComplexNumber c4 = 2.5 * c2;
  cout << "2.5 * v2: " << c4 << endl;
  */
  

  /* VECTOR CLASS AND OPERATORS
  Vector v1(1,2,3);
  Vector v2(4,5,6);
  
  cout << "v1: " << v1 << endl;
  cout << "v2: " << v2 << endl;
  
  Vector v3 = v1 + v2;
  cout << "v3(v1 + v2): " << v3 << endl;
  
  v1 += v2;
  cout << "After v1 += v2, v1: " << v1 << endl;
  
  Vector v4 = 2.5 * v2;
  cout << "2.5 * v2: " << v4 << endl;
  
  v2 *= 2.0;
  cout << "After v2 *= 2.0, v2: " << v2 << endl;
  */


  /*
  Auto a1(5,3);
  Auto a2(3,3);
  Auto a3; //ovo je moj this objekat
  a3 = a1 + a2; // this is operator+(a1,a2) because this is friend but if it's not friend this is a1.operator+(a2)
  cout << a3 << endl;
  a3 = a1 - a2;
  cout << a3 << endl;
  a3 = a1 * a2;
  cout << a3;
  */
  
  return 0;
}