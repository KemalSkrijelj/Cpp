#include <iostream>
#include <cmath>

using namespace std;

class Time{
  int hours, minutes, seconds;
  public:
  Time(int h, int m, int s){ Set(h, m ,s); }
  Time() : hours(0), minutes(0), seconds(0) {}
  void Set(int h, int m, int s);
  int getHours() const { return hours; }
  int getMinutes() const { return minutes; }
  int getSeconds() const { return seconds; }
  int getTotalInSeconds() const { return hours * 60  * 60 + minutes * 60 + seconds; }
  Time& operator++(); //pre-increment
  Time operator++(int); //post-incr
  friend Time operator+(Time ob1, Time ob2);
  Time& operator+=(const Time &ob);
  bool operator<(const Time &ob) const;
  bool operator==(const Time &ob) const;
  bool operator!=(const Time &ob) const;
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
Time& Time::operator++(){
  Set(hours, minutes, seconds + 1);
  return *this;
}
Time Time::operator++(int){
  Time old = *this;
  ++(*this);
  return old;
}
Time operator+(Time ob1, Time ob2){
  return Time(ob1.hours + ob2.hours, ob1.minutes + ob2.minutes, ob1.seconds + ob2.seconds);
}
Time& Time::operator+=(const Time &ob){
  hours = ob.hours;
  minutes = ob.minutes;
  seconds = ob.seconds;
  return *this;
}
bool Time::operator<(const Time &ob) const {
  return getTotalInSeconds() < ob.getTotalInSeconds();
}
bool Time::operator==(const Time &ob) const {
  return hours == ob.hours && minutes == ob.minutes && seconds == ob.seconds;
}
bool Time::operator!=(const Time &ob) const {
  return !(hours == ob.hours && minutes == ob.minutes && seconds == ob.seconds);
}
ostream& operator<<(ostream &out, const Time &ob){
  out << ob.hours << ":"<< ob.minutes << ":" << ob.seconds;
  return out;
}

class Angle{
  int hours, minutes, seconds;
  public:
  Angle(int d, int m, int s) { Set(d, m, s); }
  Angle() : hours(0), minutes(0), seconds(0) {}
  void Set(int d, int m, int s);
  int getDegres() const { return hours; }
  int getMinutes() const { return minutes; }
  int getSeconds() const { return seconds; }
  int toRadians() const { return hours * M_PI / 180.0; }
  Angle& operator++(); //pre
  Angle operator++(int); //post
  friend Angle operator+(Angle ob1, Angle ob2);
  Angle& operator+=(const Angle &ob);
  bool operator<(const Angle &ob) const;
  bool operator==(const Angle &ob) const;
  bool operator!=(const Angle &ob) const;
  friend ostream& operator<<(ostream &out, const Angle &ob);
};
void Angle::Set(int d, int m, int s){
  while (s >= 60) { s-= 60; m++; }
  while (s < 0) { s+= 60; m--; }
  while (m >= 60) { m-= 60; d++; }
  while (m < 0) { m+= 60; d--; }
  while (d >= 360) { d-= 360; }
  while (d < 0) { d+= 360; }
  hours = d;
  minutes = m;
  seconds = s;
}
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
bool Angle::operator<(const Angle &ob) const {
  return toRadians() < ob.toRadians(); 
}
bool Angle::operator==(const Angle &ob) const {
  return hours == ob.hours && minutes == ob.minutes && seconds == ob.seconds; 
}
bool Angle::operator!=(const Angle &ob) const {
  return !(hours == ob.hours && minutes == ob.minutes && seconds == ob.seconds); 
  
}
ostream& operator<<(ostream &out, const Angle &ob){
  out << ob.hours << ":" << ob.minutes << ":" << ob.seconds;
  return out;
}

class Vector{
  double x, y;
  public:
  Vector(double x, double y) { Set(x,y); }
  void Set(double x, double y){
    this->x = x;
    this->y = y;
  }
  double getX() const { return x; }
  double getY() const { return y; }
  double getLengthOfVector() const { return sqrt(x*x + y*y); }
  friend Vector operator+(Vector ob1, Vector ob2);
  friend Vector operator-(Vector ob1, Vector ob2);
  friend double operator*(Vector ob1, Vector ob2);
  friend Vector operator*(double f, Vector ob);
  friend Vector operator*(Vector ob, double f);
  Vector& operator+=(const Vector &ob);
  Vector& operator-=(const Vector &ob);
  Vector& operator*=(const Vector &ob);
  Vector& operator++(); //pre
  Vector operator++(int); //post
  friend bool operator==(const Vector &ob1, const Vector &ob2);
  friend bool operator!=(const Vector &ob1, const Vector &ob2);
  friend ostream& operator<<(ostream &out, const Vector &ob);
  friend double angleBetween(Vector ob1, Vector ob2);
};
Vector operator+(Vector ob1, Vector ob2){
  return Vector(ob1.x + ob2.x, ob1.y + ob2.y);
}
Vector operator-(Vector ob1, Vector ob2){
  return Vector(ob1.x - ob2.x, ob1.y - ob2.y);
}
Vector operator*(double f, Vector ob){
  return Vector(f * ob.x, f * ob.y);
}
Vector operator*(Vector ob, double f){
  return Vector(ob.x * f, ob.y * f);
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
  double l = getLengthOfVector();
  double f = (l+1) / l;
  Set(x * f, y * f); 
  return *this;
}
Vector Vector::operator++(int){
  Vector old = *this;
  ++(*this);
  return old;
}
bool operator==(const Vector &ob1, const Vector &ob2) {
  return ob1.x == ob2.x && ob1.y == ob2.y;
}
bool operator!=(const Vector &ob1, const Vector &ob2) {
  return !(ob1.x == ob2.x && ob1.y == ob2.y);
}
ostream& operator<<(ostream &out, const Vector &ob){
  out << "{ " << ob.x << ", " << ob.y << " }" << endl;
  return out;
}
double angleBetween(Vector ob1, Vector ob2){
  double dot = ob1 * ob2; // ovde smo iskoristi operator overloading
  double len = ob1.getLengthOfVector() * ob2.getLengthOfVector();
  return acos(dot / len);
}

class USAlength{
  int yards, feet, inches;
  public:
  USAlength(int y, int f, int i) { Set(y,f,i); }
  USAlength(double meters) {
    int totalInches = meters / 0.0254 + 0.5;
    yards = totalInches / 36;
    int rest = totalInches % 36;
    feet = rest / 12;
    inches = rest % 12;
  }
  void Set(int y, int f, int i){
    int total = y *36 + f * 12 + i;
    yards = total / 36;
    int rest = yards % 36;
    feet = rest / 12;
    inches = rest % 12;
  }
  int getYards() const { return yards; }
  int getFeet() const { return feet; }
  int getInches() const { return inches; }
  double getMeters() const {
    double totalInches = yards * 36 + feet *12 + inches;
    return totalInches * 0.0254;
  }
  friend USAlength operator+(USAlength &ob1, USAlength &ob2);
  USAlength& operator+=(const USAlength &ob);
  USAlength& operator++();
  USAlength operator++(int);
  friend USAlength operator*(USAlength &ob1, USAlength &ob2);
  friend double operator/(USAlength &ob1, USAlength &ob2);
  friend bool operator==(const USAlength &ob1, const USAlength &ob2);
  friend bool operator<(const USAlength &ob1, const USAlength &ob2);
  friend ostream& operator<<(ostream &out, const USAlength &ob);
};
USAlength operator+(USAlength &ob1, USAlength &ob2){
  return USAlength(ob1.yards + ob2.yards, ob1.feet + ob2.feet, ob1.inches + ob2.inches);
}
USAlength& USAlength::operator+=(const USAlength &ob){
  yards = ob.yards;
  feet = ob.feet;
  inches = ob.inches;
  return *this;
}
USAlength& USAlength::operator++(){
  Set(yards, feet, inches + 1);
  return *this;
}
USAlength USAlength::operator++(int){
  USAlength old = *this;
  ++(*this);
  return old;
}
USAlength operator*(USAlength &ob1, USAlength &ob2){
  return USAlength(ob1.yards * ob2.yards, ob1.feet * ob2.feet, ob1.inches * ob2.inches);
}
double operator/(USAlength &ob1, USAlength &ob2){
  double t1 = ob1.yards * 36 + ob1.feet * 12 + ob1.inches; // converted to inches
  double t2 = ob2.yards * 36 + ob2.feet * 12 + ob2.inches;
  return t1 / t2; 
}
bool operator==(const USAlength &ob1, const USAlength &ob2){
  return ob1.yards == ob2.yards && ob1.feet == ob2.feet && ob1.inches == ob2.inches;
}
bool operator<(const USAlength &ob1, const USAlength &ob2){
  double t1 = ob1.yards * 36 + ob1.feet * 12 + ob1.inches;
  double t2 = ob2.yards * 36 + ob2.feet * 12 + ob2.inches;
  return t1 < t2;
}
ostream& operator<<(ostream &out, const USAlength &ob){
  out << ob.yards << " yards, " << ob.feet << " feets, " << ob.inches << " inches";
  return out;
}

class Fraction{
  int numerator, denominator;
  static int GCD(int n, int d){
    int greatest = 1;
    for (int i = 1; i <= abs(n) && i <= abs(d); i++)
    {
    if(n % i == 0  && d % i == 0) { greatest = i; }
    }
    return greatest;
  }
  public:
  Fraction(int n, int d = 1) {
    if (d == 0) throw domain_error("Deminator must be postive!");
    numerator = n;
    denominator = d;
    if(d < 0){
      numerator = -numerator;
      denominator = - denominator;
    }
    int g = GCD(n, d);
    numerator /= g;
    denominator /= g;
  }
  int getNumerator() const { return numerator; }
  int getDenominator() const { return denominator; }
  friend Fraction operator+(Fraction &ob1, Fraction &ob2);
  friend Fraction operator-(Fraction &ob1, Fraction &ob2);
  friend Fraction operator*(Fraction &ob1, Fraction &ob2);
  friend Fraction operator/(Fraction &ob1, Fraction &ob2);
  Fraction operator-() const;
  Fraction& operator+=(const Fraction &ob);
  Fraction& operator-=(const Fraction &ob);
  Fraction& operator*=(const Fraction &ob);
  Fraction& operator/=(const Fraction &ob);
  Fraction& operator++();
  Fraction operator++(int);
  friend ostream& operator<<(ostream &out, const Fraction &ob);
  bool operator==(const Fraction &ob);
  bool operator<(const Fraction &ob);

  operator double() const {
    return (double)numerator/denominator;
  }
};
Fraction operator+(Fraction &ob1, Fraction &ob2){
  return Fraction( ob1.numerator*ob2.denominator + ob2.numerator*ob1.denominator, ob1.denominator * ob2.denominator );
}
Fraction operator-(Fraction &ob1, Fraction &ob2){
  return Fraction( ob1.numerator*ob2.denominator - ob2.numerator*ob1.denominator, ob1.denominator * ob2.denominator );
}
Fraction operator*(Fraction &ob1, Fraction &ob2){
  return Fraction( ob1.numerator*ob2.numerator, ob1.denominator * ob2.denominator );
}
Fraction operator/(Fraction &ob1, Fraction &ob2){
  return Fraction( ob1.numerator*ob2.denominator, ob2.numerator * ob1.denominator );
}
Fraction Fraction::operator-() const{
  return Fraction(-numerator, denominator);
}
Fraction& Fraction::operator+=(const Fraction &ob){
  numerator *= ob.denominator + ob.numerator * denominator;
  denominator *= denominator;
  return *this; 
}
Fraction& Fraction::operator-=(const Fraction &ob){
  numerator *= ob.denominator - ob.numerator * denominator;
  denominator *= denominator;
  return *this; 
}
Fraction& Fraction::operator*=(const Fraction &ob){
  numerator *= ob.numerator;
  denominator *= denominator;
  return *this; 
}
Fraction& Fraction::operator/=(const Fraction &ob){
  numerator *= ob.numerator;
  denominator *= denominator;

  int g = GCD(numerator, denominator);
  numerator /= g;
  denominator /= g;
  return *this; 
}
Fraction& Fraction::operator++(){
  numerator += denominator;
  return *this;
}
Fraction Fraction::operator++(int){
  Fraction old = *this;
  ++(*this);
  return old;
}
ostream& operator<<(ostream &out, const Fraction &ob){
  out << ob.numerator << "/" << ob.denominator;
  return out;
}
bool Fraction::operator==(const Fraction &ob){
  return numerator == ob.numerator && denominator == ob.denominator;
}
bool Fraction::operator<(const Fraction &ob){
  return numerator * ob.denominator << denominator * ob.numerator;
}

class Date{
  int day, month, year;
  static bool isLeapYear(int year){
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  }
  static int maxDayInMonth(int month, int year){
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
  public:
  Date(int d, int m, int y) { Set(d, m, y); }

  void Set(int d, int m, int y){
    if(y < 1800) throw domain_error("Invalid year!");
    if(m < 0 || m > 12) throw domain_error("Invalid month!");
    if(d < 0 || d > maxDayInMonth(m,y)) throw domain_error("Invalid day!");
    day = d;
    month = m;
    year = y;
  }
  int getDay() const { return day; }
  int getMonth() const { return month; }
  int getYear() const { return year; }
  Date& operator++();
  Date operator++(int);
  Date& operator--();
  Date operator--(int);
  Date& operator-=(int n);
  Date& operator+=(int n);
  friend Date operator+(Date &ob1, Date &ob2);
  friend Date operator-(Date &ob1, Date &ob2);
  bool operator<(const Date &ob);
  bool operator==(const Date &ob);
  bool operator!=(const Date &ob);
  friend ostream& operator<<(ostream &out, const Date &ob);
};
Date& Date::operator++(){
  Set(day+1, month, year);
  return *this;
}
Date Date::operator++(int){
  Date old = *this;
  ++(*this);
  return old;
}
Date& Date::operator--(){
  Set(day-1, month, year);
  return *this;
}
Date Date::operator--(int){
  Date old = *this;
  --(*this);
  return old;
}
Date& Date::operator+=(int n){
  if(n > 0){
    for (int i = 0; i < n; i++) ++(*this);
  }else{
    for (int i = 0; i < abs(n); i++) --(*this);
  }
}
Date& Date::operator-=(int n){
  if(n > 0){
    for (int i = 0; i < n; i++) --(*this);
  }else{
    for (int i = 0; i < abs(n); i++) ++(*this);
  }
}
Date operator+(Date &ob1, Date &ob2){
  return Date(ob1.day + ob2.day, ob1.month + ob2.month, ob1.year + ob2.year);
}
Date operator-(Date &ob1, Date &ob2){
  return Date(ob1.day - ob2.day, ob1.month - ob2.month, ob1.year - ob2.year);
}
bool Date::operator<(const Date &ob){
  return (year <  ob.year) ||
         (year == ob.year && month <  ob.month) ||
         (year == ob.year && month == ob.month && day < ob.day);
}
bool Date::operator==(const Date &ob){
  return year == ob.year && month == ob.month && day == ob.day;
}
bool Date::operator!=(const Date &ob){
  return !(year == ob.year && month == ob.month && day == ob.day);
}
ostream& operator<<(ostream &out, const Date &ob){
  out << ob.day << "/" << ob.month << "/" << ob.year; 
  return out;
}
int main(){
  Date d(3,11, 1999);
  cout << "d: " << d << endl;

  /*
  Fraction f1(2, 3);
  cout << "f1: " << f1 << endl;
  
  Fraction f2(1, 5);
  cout << "f1: " << f1 << endl;
  */

  /*
  USAlength u1(1.95);
  cout << "u1: " << u1 << endl;
  USAlength u2(6,31,56);
  cout << "u2: " << u2 << endl;
  */
  
  /*
  Vector v1(3.1, 2.1);
  cout << "v1: " << v1 << endl;
  Vector v2(1.1, 4.3);
  cout << "v2: " << v2 << endl;
  
  cout << boolalpha;
  
  cout << "v1 == v2: " << (v1 == v2) << endl;
  cout << "v1 != v2: " << (v1 != v2) << endl;
  */

  /*
  Angle a1(70,54, 57);
  cout << "a1: " << a1 << endl;
  a1++;
  cout << "a1++: " << a1 << endl;
  
  
  Angle a2(89,34, 27);
  cout << "a2: " << a2 << endl;
  ++a2;
  cout << "++a2: " << a2 << endl;
  
  Angle a3;
  a3 = a1 + a2;
  cout << "a1 + a2: " << a3 << endl;  
  
  
  cout << boolalpha;
  
  cout << "a1==a2: " << (a1==a2) << endl;
  cout << "a1<a2: " << (a1<a2) << endl;
  cout << "a1!=a2: " << (a1!=a2) << endl;
  */

  /*
  Time t1(15,50,45);
  Time t2(1, 20, 30);
  
  cout << "t1 = " << t1 << endl;
  cout << "t2 = " << t2 << endl;
  
  Time t3 = t1 + t2;
  cout << "t1 + t2: " << t3 << endl;
  
  t1 += t2;
  cout << "t1 += t2 -> " << t1 << endl;
  
  ++t1;
  cout << "++t1 = " << t1 << endl;
  
  t1++;
  cout << "t1++ = " << t1 << endl;
  
  cout << boolalpha;
  
  cout << "t1 < t2 : " << (t1 < t2) << endl;
  cout << "t1 == t2 : " << (t1 == t2) << endl;
  cout << "t1 != t2 : " << (t1 != t2) << endl;
  */
  return 0;
}