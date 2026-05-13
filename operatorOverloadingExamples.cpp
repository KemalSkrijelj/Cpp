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


class Vectors{
  double x,y,z;
  public:
  Vectors(double x, double y, double z) { Set(x,y,z); }
  void Set(double x, double y, double z) {
    this->x=x;
    this->y=y;
    this->z=z;
  }
  double GetX() const { return x; } 
  double GetY() const { return y; } 
  double GetZ() const { return z; }
  double GetLength() const { return sqrt(x*x+y*y+z*z); }
  friend Vectors operator+(Vectors ob1, Vectors ob2);
  friend Vectors operator-(Vectors ob1, Vectors ob2);
  friend Vectors operator*(Vectors ob, double f);
  friend Vectors operator*(double f, Vectors ob);
  friend double operator*(Vectors ob1, Vectors ob2);
  Vectors& operator+=(const Vectors &ob);
  Vectors& operator-=(const Vectors &ob);
  Vectors& operator*=(double f);
  Vectors& operator++();
  Vectors operator++(int);
  friend bool operator==(const Vectors &ob1, const Vectors &ob2);
  friend bool operator!=(const Vectors &ob1, const Vectors &ob2);
  friend ostream& operator<<(ostream &out, const Vectors &ob);
};
Vectors operator+(Vectors ob1, Vectors ob2){
  return Vectors(ob1.x + ob2.x, ob1.y + ob2.y, ob1.z + ob2.z);
}
Vectors operator-(Vectors ob1, Vectors ob2){
  return Vectors(ob1.x - ob2.x, ob1.y - ob2.y, ob1.z - ob2.z);
}
Vectors operator*(Vectors ob, double f){
  return Vectors(ob.x * f , ob.y * f, ob.z * f);
}
Vectors operator*(double f, Vectors ob){
  return Vectors(f * ob.x , f * ob.y , f * ob.z);
}
double operator*(Vectors ob1, Vectors ob2){
  return ob1.x * ob2.x + ob1.y * ob2.y + ob1.z * ob2.z;
}
Vectors& Vectors::operator+=(const Vectors &ob){
  x += ob.x;
  y += ob.y;
  z += ob.z;
  return *this;
}
Vectors& Vectors::operator-=(const Vectors &ob){
  x -= ob.x;
  y -= ob.y;
  z -= ob.z;
  return *this;
}
Vectors& Vectors::operator*=(double f){
  x *= f;
  y *= f;
  z *= f;
  return *this;
}
Vectors& Vectors::operator++(){
  double len = GetLength();
  double factor = (len+1) / len;
  Set(x * factor, y * factor, z * factor);
  return *this;
}
Vectors Vectors::operator++(int){
  Vectors old = *this;
  ++(*this);
  return old;
}
bool operator==(const Vectors &ob1, const Vectors &ob2){
  return ob1.x == ob2.x && ob1.y == ob2.y && ob1.z == ob2.z;
}
bool operator!=(const Vectors &ob1, const Vectors &ob2){
  return !(ob1.x == ob2.x && ob1.y == ob2.y && ob1.z == ob2.z);
}
ostream& operator<<(ostream &out, const Vectors &ob){
  out << "{" << ob.x << ", " << ob.y << ", " << ob.z << "}" << endl;
  return out;
}


class USALength{
  int yards, feet, inches;
  public:
  USALength(int y, int f, int i) { Set(y,f,i); }
  USALength(double meters) {
    int totalInches = meters / 0.0254 + 0.5;
    yards = totalInches / 36;
    int rest = totalInches % 36;
    feet = rest / 12;
    inches = rest % 12;
  }
  void Set(int y, int f, int i){
    int total = y * 36 + f * 12 + i; // all convert to inches
    yards = total / 36;
    int rest = total % 36;
    feet = rest / 12;
    inches = rest % 12;
  }
  int GetYards() const { return yards; }
  int GetFeet() const { return feet; }
  int GetInches() const { return inches; }
  double GetMeters() const {
    double totalInches = yards * 36 + feet *12 + inches;
    return totalInches * 0.0254; }
  friend USALength operator+(USALength ob1, USALength ob2);
  friend USALength operator*(USALength ob, double f);
  friend double operator/(USALength ob1, USALength ob2);
  USALength& operator+=(const USALength &ob);
  USALength& operator++();
  USALength operator++(int);
  friend bool operator==(USALength ob1, USALength ob2);
  friend bool operator<(USALength ob1, USALength ob2);
  friend ostream& operator<<(ostream &out, const USALength &ob);
  
};
USALength operator+(USALength ob1, USALength ob2){
  return USALength(ob1.yards + ob2.yards, ob1.feet + ob2.feet, ob1.inches + ob2.inches);
}
USALength operator*(USALength ob, double f){
  double totalInches = ob.yards *36 + ob.feet * 12 + ob.inches;
  return USALength(0,0, totalInches); // now it's convert all with Set function in constructor 
}
double operator/(USALength ob1, USALength ob2){
  double t1 = ob1.yards * 36 + ob1.feet * 12 + ob1.inches; // converted to inches
  double t2 = ob2.yards * 36 + ob2.feet * 12 + ob2.inches; // converted to inches
  return t1 / t2; // divisible t1/t2;
}

USALength& USALength:: operator+=(const USALength &ob){
  yards += ob.yards;
  feet += ob.feet;
  inches += ob.inches;
  return *this;
}
USALength& USALength::operator++(){
  Set(yards, feet, inches + 1);
  return *this;
}
USALength USALength::operator++(int){
  USALength old = *this;
  ++(*this);
  return old;
}
bool operator==(USALength ob1, USALength ob2){
  return ob1.yards == ob2.yards && ob1.feet == ob2.feet && ob1.inches == ob2.inches;
}
bool operator<(USALength ob1, USALength ob2){
  double t1 = ob1.yards * 36 + ob1.feet * 12 + ob1.inches; // converted to inches
  double t2 = ob2.yards * 36 + ob2.feet * 12 + ob2.inches; // converted to inches
  return t1 < t2;
}
ostream& operator<<(ostream &out, const USALength &ob){
  out << ob.yards << " yd " << ob.feet << " ft " << ob.inches << " in" << endl;
  return out;
}


class Fraction{
  int numerator, denomirator;
  static int GCD(int n, int d){
    int greatest = 1; // first suppose is 1, because 1 is div always
    for (int i = 1; i <= abs(n) && i <= abs(d); i++){
      if(n % i == 0 && d % i == 0) { greatest = i; }
    }
    return greatest;
  }
  public:
    Fraction(int n, int d = 1) {
      if(d == 0) throw domain_error("Bad denomirator!");
      numerator = n;
      denomirator = d;
      if(d < 0){
        numerator = -numerator;
        denomirator = -denomirator;
      }
      int g = GCD(numerator, denomirator);
      numerator /= g; //skracivanje
      denomirator /= g; //skracivanje
    } 
  int GetNumerator() const { return numerator; }
  int GetDenomirator() const { return denomirator; }
  friend Fraction operator+(Fraction ob1, Fraction ob2);
  friend Fraction operator-(Fraction ob1, Fraction ob2);
  friend Fraction operator*(Fraction ob1, Fraction ob2);
  friend Fraction operator/(Fraction ob1, Fraction ob2);
  Fraction operator-() const;
  Fraction& operator+=(const Fraction &ob);
  Fraction& operator-=(const Fraction &ob);
  Fraction& operator*=(const Fraction &ob);
  Fraction& operator/=(const Fraction &ob);
  Fraction& operator++();
  Fraction operator++(int);
  friend ostream& operator<<(ostream &out, const Fraction &ob);
  friend bool operator==(const Fraction &ob1, const Fraction &ob2);
  friend bool operator<(const Fraction &ob1, const Fraction &ob2);

  operator double() const {
    return (double)numerator/ denomirator;
  };
};

Fraction operator+(Fraction ob1, Fraction ob2){
  return Fraction(ob1.numerator * ob2.denomirator + ob2.numerator * ob1.denomirator, ob1.denomirator * ob2.denomirator);
}
Fraction operator-(Fraction ob1, Fraction ob2){
  return Fraction(ob1.numerator * ob2.denomirator - ob2.numerator*ob1.denomirator, ob1.denomirator * ob2.denomirator);
}
Fraction operator*(Fraction ob1, Fraction ob2){
  return Fraction(ob1.numerator * ob2.numerator, ob1.denomirator * ob2.denomirator);
}
Fraction operator/(Fraction ob1, Fraction ob2){
  if (ob2.numerator == 0) throw domain_error("Divison by zero.");
  return Fraction(ob1.numerator * ob2.denomirator, ob2.numerator * ob1.denomirator);
}
Fraction Fraction::operator-() const {
  return Fraction(-numerator, denomirator);
}
Fraction& Fraction::operator+=(const Fraction &ob){
  numerator = numerator  * ob.denomirator + ob.numerator * denomirator ;
  denomirator *= ob.denomirator;
  return *this;
}
Fraction& Fraction::operator-=(const Fraction &ob){
  numerator = numerator  * ob.denomirator - ob.numerator * denomirator ;
  denomirator *= ob.denomirator;
  return *this;
}
Fraction& Fraction::operator*=(const Fraction &ob){
  numerator *= ob.numerator;
  denomirator *= ob.denomirator;
  return *this;
}
Fraction& Fraction::operator/=(const Fraction &ob){
  numerator *= ob.denomirator;
  denomirator *= ob.numerator;
  
  int g = GCD(numerator, denomirator);
  numerator /= g;
  denomirator /= g;
  return *this;
}
Fraction& Fraction::operator++(){
  numerator += denomirator;  
  return *this;
}
Fraction Fraction::operator++(int){
  Fraction old = *this;
  ++(*this);
  return old;
}
ostream& operator<<(ostream &out, const Fraction &ob){
  if(ob.denomirator == 1){
    out << ob.numerator;
  }
  else{
    out << ob.numerator << "/" << ob.denomirator;
  }
  return out;
}
bool operator==(const Fraction &ob1, const Fraction &ob2){
  return ob1.numerator == ob2.numerator && ob1.denomirator == ob2.denomirator;
}
bool operator<(const Fraction &ob1, const Fraction &ob2){
  return ob1.numerator * ob2.denomirator < ob2.numerator * ob1.denomirator;
}


class Date{
  int year, month, day;
  static bool isLeapYear(int year);
  static int maxDayInMonth(int month, int year);
  public:
  Date(int y, int m, int d){ Set(y,m,d); }
  void Set(int y, int m, int d){
    if (y < 1800) throw domain_error("Bad input year!");
    if (m < 1 || m > 12) throw domain_error("Bad input month!");
    if (d < 1 || d > maxDayInMonth(y,m)) throw domain_error("Bad input month!");
    year = y;
    month = m;
    day = d;
  }
  int getYear() const { return year; }
  int getMonth() const { return month; }
  int getDay() const { return day; }
  Date& operator++();
  Date operator++(int);
  Date& operator--();
  Date operator--(int);
  Date& operator+=(int n);
  Date& operator-=(int n);
  friend Date operator+(Date &ob1, Date &ob2);
  friend Date operator-(Date &ob1, Date &ob2);
  friend bool operator<(const Date &ob1,const Date &ob2);
  friend bool operator==(const Date &ob1,const Date &ob2);
  friend bool operator!=(const Date &ob1,const Date &ob2);
  friend ostream& operator<<(ostream &out, const Date &d);
};

bool Date::isLeapYear(int year){
  return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
int Date::maxDayInMonth(int month, int year){
  if (month == 4 || month == 6 || month == 9 || month == 11)
  {
    return 30;
  }else if (month == 2 && isLeapYear(year))
  {
    return 29;
  }else if (month == 2)
  {
    return 28;
  }else{
    return 31;
  }
}
Date& Date::operator++(){
  day++;
  if(day > maxDayInMonth(year, month)){
    day = 1;
    month++;
    if (month > 12)
    {
      month = 1;
      year++;
    }
  }
  return *this;
}
Date Date::operator++(int){
  Date old = *this;
  ++(*this);
  return old;
}
Date& Date::operator--(){
  day--;
  if(day < 1){
    month--;
    day = maxDayInMonth(year, month);
    if (month < 1)
    {
      month = 12;
      year--;
    }
  }
  return *this;
}
Date Date::operator--(int){
  Date old = *this;
  --(*this);
  return old;
}

Date& Date::operator+=(int n){
  if (n > 0)
  {
    for (int i = 0; i < n; i++) ++(*this);
  }else{
    for (int i = 0; i < abs(n); i++) --(*this);
  }
  return *this;
}
Date& Date::operator-=(int n){
  if (n > 0)
  {
    for (int i = 0; i < n; i++) --(*this);
  }else{
    for (int i = 0; i < abs(n); i++) ++(*this);
  }
  return *this;
}

Date operator+(Date &ob1, Date &ob2){
  return Date(ob1.year + ob2.year, ob1.month + ob2.month, ob1.day + ob2.day);
}
Date operator-(Date &ob1, Date &ob2){
  return Date(ob1.year - ob2.year, ob1.month - ob2.month, ob1.day - ob2.day);
}

bool operator<(const Date &ob1,const Date &ob2) {
  return (ob1.year <  ob2.year) ||
         (ob1.year == ob2.year && ob1.month <  ob2.month) ||
         (ob1.year == ob2.year && ob1.month == ob2.month && ob1.day < ob2.day);
}
bool operator==(const Date &ob1,const Date &ob2) {
  return ob1.year == ob2.year && ob1.month == ob2.month && ob1.day == ob2.day;
};
bool operator!=(const Date &ob1,const Date &ob2) {
  return !(ob1.year == ob2.year && ob1.month == ob2.month && ob1.day == ob2.day);
}
ostream& operator<<(ostream &out, const Date &d){
  out << d.year << "/" << d.month << "/" << d.day;
  return out; 
}


int main(){
  Date d(2024,2,28);
  cout << "Start: " << d << "\n";
  ++d;
  cout << "++d: " << d << "\n";
  d++;
  cout << "d++: " << d << "\n";
  d += 3;
  cout << "d += 3: " << d << "\n";
  --d;
  cout << "--d: " << d << "\n"; 
  cout << boolalpha;
  cout << "d < 1/1/2025: " << (d < Date(2025,1,1)) << "\n";

  /* FRACTION CLASS
  Fraction a(1, 2);
  Fraction b(3, 4);
  
  cout << "a = " << a << "\n";
  cout << "b = " << b << "\n";
  
  cout << "a + b = " << a + b << "\n";
  cout << "a * b = " << a * b << "\n";
  
  Fraction x = a;
  cout << "++x = " << ++x << "\n";
  cout << "x++ = " << x++ << "\n";
  cout << "after x++ = " << x << "\n";
  
  cout << boolalpha;
  cout << "a < b = " << (a < b) << "\n";
  double d = a;
  cout << "a as double = " << d << "\n";
  */
  
  /* USA LENGTH(INCHES)
  USALength a(5, 7, 14);
  USALength b(2, 10, 3);
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  // +
  USALength c = a + b;
 cout << "a + b = " << c << endl;
 // +=
 a += b;
 cout << "a += b -> " << a << endl;
 // ++ prefix
 ++a;
 cout << "++a = " << a << endl;
 // ++ postfix
 a++;
 cout << "a++ = " << a << endl;
 // *
 USALength d = b * 2.5;
 cout << "b * 2.5 = " << d << endl;
 // /
 double ratio = a / b;
 cout << "a / b = " << ratio << endl;
 // ==
 cout << boolalpha;
 cout << "a == b: " << (a == b) << endl;
 // <
 cout << "a < b: " << (a < b) << endl;
 // meters
 cout << "a in meters = " << a.GetMeters() << endl;
 // meters constructor
 USALength m(2.0); // 2 meters
 cout << "2 meters = " << m << endl;
 */
 

  /* Vector second class
  Vectors v1(2,3,6);
  Vectors v2(4,5,8);
  cout << v1;
  cout << v2;
  
  Vectors v3 = v1 + v2;
  cout << "v1 + v2 = " << v3 << endl;
  
  v1 += v2;
  cout << "v1 += v2 -> " << v1 << endl;
  
  // Prefix ++
  ++v1;
  cout << "++v1 = " << v1 << endl;
  
  // Postfix ++
  v1++;
  cout << "v1++ = " << v1 << endl;
  
  cout << boolalpha;
  cout << "v1 == v2: " << (v1 == v2) << endl;
  cout << "v1 != v2: " << (v1 != v2) << endl;
  */
  
  /*Vector
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
  */


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