#include <iostream>
#include <cmath>

using namespace std;

class Time{
  int hours, minutes, seconds;
  public:
  Time() : hours(0), minutes(0), seconds(0){}
  Time(int h, int m, int s) { Set(h,m,s); }
  void Set(int h, int m, int s){
    while (s >= 60) {
      s -= 60; 
      m++;
    } 
    while (m >= 60){ 
      m -= 60;
      h++;
    }
    while (h >= 24){ 
      h -= 24;
    }
    hours = h;
    minutes = m;
    seconds = s;
  }
  int getHours() const { return hours; }
  int getMinutes() const { return minutes; }
  int getSeconds() const { return seconds; }
  int toSeconds() const { return hours * 60 * 60 + minutes * 60 + seconds; }
  Time& operator++(); //pre-increment
  Time operator++(int); //post-increment
  friend Time operator+(Time ob1, Time ob2); //post-increment
  Time& operator+=(const Time &ob);
  bool operator<(const Time &ob) const;
  bool operator==(const Time &ob) const;
  bool operator!=(const Time &ob) const;
  friend ostream& operator<<(ostream &out, const Time &ob);
};

Time& Time::operator++(){ //Pre-increment
  Set(hours, minutes, seconds +1);
  return *this;
}
Time Time::operator++(int){
  Time old = *this; // we stored last object in object old
  ++(*this);
  return old;
}

Time operator+(Time ob1, Time ob2){
  return Time(ob1.hours + ob2.hours, ob1.minutes + ob2.minutes, ob1.seconds + ob2.seconds);
}
Time& Time::operator+=(const Time &ob){
  hours += ob.hours;
  minutes += ob.minutes;
  seconds += ob.seconds;
  return *this;
}

bool Time::operator<(const Time &ob) const {
  return toSeconds() < ob.toSeconds();
}
bool Time::operator==(const Time &ob) const {
  return hours == ob.hours && minutes == ob.minutes && seconds == ob.seconds; 
}
bool Time::operator!=(const Time &ob) const {
  return !(hours == ob.hours && minutes == ob.minutes && seconds == ob.seconds);
}

ostream& operator<<(ostream &out, const Time &ob){
  out << ob.hours << ":" << ob.minutes << ":" << ob.seconds;
  return out; 
}

class Angle{
  int hours, minutes, seconds;
  public:
  Angle() : hours(0), minutes(0), seconds(0){} 
  Angle(int h, int m, int s) { Set(h,m,s); }
  void Set(int h, int m, int s){
    while (s >= 60 ) { s-= 60; m++; }
    while (s < 0 ) { s+= 60; m--; }
    while (m >= 60 ) { m-= 60;h++; }
    while (m < 0 ) { m+= 60; h--; }
    while (h >= 360 ) h -= 360;
    while (h  < 0 ) h += 360;
    hours = h;
    minutes = m;
    seconds = s; 
  }
  int getDegrees() const { return hours; }
  int getMinutes() const { return minutes; }
  int getSeconds() const { return seconds; }
  double toRadians() const { return hours * M_PI / 180.0; }
  Angle& operator++();
  Angle operator++(int);
  friend Angle operator+(Angle ob1, Angle ob2);
  Angle& operator+=(const Angle &ob);
  bool operator<(const Angle &ob) const;
  bool operator==(const Angle &ob) const;
  bool operator!=(const Angle &ob) const;
  friend ostream& operator<<(ostream& out, const Angle &ob);
};

Angle& Angle::operator++(){
  Set(hours + 1, minutes, seconds);
  return *this;
}
Angle Angle::operator++(int){
  Angle old = *this;
  ++(*this);
  return old;  
}
Angle operator+(Angle ob1, Angle ob2){
  return Angle(ob1.hours + ob2.hours, ob1.minutes + ob2.minutes, ob1.seconds + ob2.seconds);
}
Angle& Angle::operator+=(const Angle &ob){
  hours += ob.hours;
  minutes += ob.minutes;
  seconds += ob.seconds;
  return *this;
}
bool Angle::operator<(const Angle &ob)const{
  return toRadians() < ob.toRadians();
}
bool Angle::operator==(const Angle &ob)const{
  return toRadians() == ob.toRadians();
}
bool Angle::operator!=(const Angle &ob)const{
  return !(toRadians() == ob.toRadians());
}
ostream& operator<<(ostream& out, const Angle &ob){
  out << ob.hours << "deg " << ob.minutes << " min " << ob.seconds << " sec";
  return out;
}


class Vector{
  double x, y;
  public:
  Vector(double x, double y) { Set(x, y); }
  void Set(double x, double y){
    this->x = x;
    this->y = y;
  }
  double GetX() const { return x; }
  double GetY() const { return y; }
  double GetLength() const { return sqrt(x*x+y*y); }
  friend Vector operator+(Vector ob1, Vector ob2);
  friend Vector operator-(Vector ob1, Vector ob2);
  friend Vector operator*(Vector ob, double f);
  friend Vector operator*(double f, Vector ob);
  friend double operator*(Vector ob1, Vector ob2);
  Vector& operator+=(const Vector &ob);
  Vector& operator-=(const Vector &ob);
  Vector& operator*=(double f);
  Vector& operator++();
  Vector operator++(int);
  friend bool operator==(const Vector &ob1, const Vector &ob2);
  friend bool operator!=(const Vector &ob1, const Vector &ob2);
  friend ostream& operator<<(ostream &out, const Vector &ob);
  friend double angleBetween(Vector ob1, Vector ob2);
};

Vector operator+(Vector ob1, Vector ob2){
  return Vector(ob1.x + ob2.x , ob1.y + ob2.y);
}
Vector operator-(Vector ob1, Vector ob2){
  return Vector(ob1.x - ob2.x , ob1.y - ob2.y);
}
Vector operator*(Vector ob, double f){
  return Vector(ob.x * f, ob.y * f);
}
Vector operator*(double f, Vector ob){
  return Vector(f * ob.x, f * ob.y);
}
double operator*(Vector ob1, Vector ob2){
  return ob1.x * ob2.x + ob1.y *ob2.y; 
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
Vector& Vector::operator*=(double f){
  x *= f;
  y *= f;
  return *this;
}
Vector& Vector::operator++(){ //pre-increment
  double len = GetLength();
  double f = (len + 1) / len; //this is formula
  Set(x * f, y * f);// we done validation
  return *this;
}
Vector Vector::operator++(int){ // post-increment
  Vector old = *this;
  ++(*this);
  return old; // return old object and after this it's incremented
}
bool operator==(const Vector &ob1, const Vector &ob2){
  return ob1.x == ob2.x && ob1.y == ob2.y;
}
bool operator!=(const Vector &ob1, const Vector &ob2){
  return !(ob1.x == ob2.x && ob1.y == ob2.y);
}
ostream& operator<<(ostream &out, const Vector &ob){
  out << "( " << ob.x << ", " << ob.y << " )" << endl;
  return out;
}
double angleBetween(Vector ob1, Vector ob2){
  double dot = ob1 * ob2;
  double len = ob1.GetLength() * ob2.GetLength();
  return acos(dot / len);
}


int main(){
  Vector v1(2,3);
  Vector v2(4,5);
  cout << v1;
  cout << v2;

  Vector v3 = v1 + v2;
  cout << "v1 + v2 = " << v3 << endl;
  
  // +=
  v1 += v2;
  cout << "v1 += v2 -> " << v1 << endl;
  
  // Prefix ++
  ++v1;
  cout << "++v1 = " << v1 << endl;
  
  // Postfix ++
  v1++;
  cout << "v1++ = " << v1 << endl;
  
  cout << boolalpha;
  
  cout << "v1 == v2 : " << (v1 == v2) << endl;
  cout << "v1 != v2 : " << (v1 != v2) << endl;

  /*Angle
  Angle a1(49,27,4);
  Angle a2(1, 20, 30);
  
  cout << "a1 = " << a1 << endl;
  cout << "a2 = " << a2 << endl;
  
  // +
  Angle a3 = a1 + a2;
  cout << "a1 + a2 = " << a3 << endl;
  
  // +=
  a1 += a2;
  cout << "a1 += a2 -> " << a1 << endl;
  
  // Prefix ++
  ++a1;
  cout << "++a1 = " << a1 << endl;
  
  // Postfix ++
  a1++;
  cout << "a1++ = " << a1 << endl;
  
  cout << boolalpha;
  
  cout << "a1 < a2 : " << (a1 < a2) << endl;
  cout << "a1 == a2 : " << (a1 == a2) << endl;
  cout << "a1 != a2 : " << (a1 != a2) << endl;
  */


  /* Time class
  Time t1(15,50,45);
  Time t2(1, 20, 30);
  
  cout << "t1 = " << t1 << endl;
  cout << "t2 = " << t2 << endl;
  
  // +
  Time t3 = t1 + t2;
  cout << "t1 + t2 = " << t3 << endl;
  
  // +=
  t1 += t2;
  cout << "t1 += t2 -> " << t1 << endl;
  
  // Prefix ++
  ++t1;
  cout << "++t1 = " << t1 << endl;
  
  // Postfix ++
  t1++;
  cout << "t1++ = " << t1 << endl;
  
  cout << boolalpha;
  
  cout << "t1 < t2 : " << (t1 < t2) << endl;
  cout << "t1 == t2 : " << (t1 == t2) << endl;
  cout << "t1 != t2 : " << (t1 != t2) << endl;
  */

  return 0;
}