#include <iostream>
#include <cmath>

const double PI = 4 * atan(1);
using namespace std;

/*
class GeometricShape{
  string type;
  public:
  GeometricShape(string t){ type = t; }
  virtual ~GeometricShape() {}
  virtual double getCircumference() const = 0;
  virtual double getArea() const = 0;
  virtual string getType() { return type; }
  void DisplayBasicInfo() const {
    cout << "type: " << type << endl <<
    "area: " << getArea() << endl <<
    "circumference: " << getCircumference() << endl;
  }
  virtual void Display() const {
    DisplayBasicInfo();
  }
};

class Circle : public GeometricShape{
  double radius;
  public:
  Circle(double r, string type) : GeometricShape(type) { Set(r); }
  double Set(double r){
    if(r <= 0){
      throw domain_error("Radius must be positive!");
    }
    radius = r;
  }
  double getRadius() const { return radius; }
  double getCircumference() const { return 2*radius*PI; }
  double getArea() const { return radius*radius*PI; }
  void Display() const {
    DisplayBasicInfo();
    cout << "radius: " << radius << endl;
  }
};
*/



class Shape{
  string color;
  public:
  Shape(string c){ color = c; }
  virtual ~Shape() {}
  string getColor() const { return color; }
  virtual string getType() const { return "Some geometric shape"; }
  virtual double getArea() const = 0;
  virtual double getCircumference() const = 0;
  void DisplayBasicInfo() const {
    cout << "color: " << color << endl <<
    "type: " << getType() << endl <<
    "area: " << getArea() << endl <<
    "circumference: " << getCircumference() << endl;
  }
  virtual void Display() const {
    DisplayBasicInfo();
  }
};

class Circle : public Shape{
  double radius;
  public: 
  Circle(double r, string color) : Shape(color) { Set(r); }
  void Set(double r){
    if(r <= 0){
      throw domain_error("Radius must be positive!");
    }
    radius = r;
  }
  double getRadius() const { return radius; }
  virtual string getType() const { return "Circle"; }
  virtual double getArea() const { return radius*radius*PI; };
  virtual double getCircumference() const { return 2*radius*PI; };
  void Display() const {
    cout << "type: " << getType() << endl;
    DisplayBasicInfo();
  }
};

class Rectangle : public Shape{
  double a, b;
  public:
  Rectangle(double a1, double b1, string color) : Shape(color) { Set(a1,b1); }
  void Set(double a1, double b1){
    if(a1 <= 0 || b1 <= 0) throw domain_error("Sides must be positive!");
    a = a1;
    b = b1;
  }
  double getA() const { return a; }
  double getB() const { return b; }
  virtual string getType() const { return "Rectangle"; }
  virtual double getArea() const { return a*b; };
  virtual double getCircumference() const { return 2*a+2*b; };
  void Display() const {
    cout << "a: " << getA() << endl;
    cout << "b: " << getB() << endl;
    DisplayBasicInfo();
  }
};


class GeometricBody{
  string type;
  public:
  GeometricBody(string t) { type = t; }
  virtual ~GeometricBody() {}
  virtual double getArea() const = 0;
  virtual double getVolume() const = 0;
  void DisplayBasicInfo() const {
    cout << "type: " << type << endl <<
    "area: " << getArea() << endl <<
    "volume: " << getVolume() << endl;
  }
  virtual void Display() const {
    DisplayBasicInfo();
  }
};

class Sphere : public GeometricBody{
  double radius;
  public:
  Sphere(double r, string type) : GeometricBody(type) { Set(r); }
  void Set(double r){
    if(r <= 0) throw domain_error("Radius must be positive!");
    radius = r;
  }
  double getRadius() const { return radius; }
  double getArea() const { return 4*(radius*radius)*PI/3; }
  double getVolume() const { return 4*(radius*radius*radius)*PI; }
  void Display() const {
    DisplayBasicInfo();
    cout << "radius: " << radius << endl;
  }
};

class Cuboid : public GeometricBody{
  double a,b,c;
  public:
  Cuboid(double a, double b, double c, string type) : GeometricBody(type) { Set(a,b,c); }
  void Set(double a, double b, double c){
    if(a <= 0 || b <= 0 || c <= 0 ) throw domain_error("Radius must be positive!");
    this->a = a;
    this->b = b;
    this->c = c;
  }
  double getA() const { return a; }
  double getB() const { return b; }
  double getC() const { return c; }
  double getArea() const { return 2*(a*b + a*c + b*c); }
  double getVolume() const { return a*b*c; }
  void Display() const {
    DisplayBasicInfo();
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
  }
};

class Body{
  string type;
  double denisity;
  public:
  Body(string t, double d) : type(t) { Set(d); }
  virtual ~Body() {}
  void Set(double d){
    if(d <= 0) throw domain_error("Denisity must be positive");
    denisity = d;
  }
  string getType() const { return type; }
  virtual double getVolume() const = 0;
  virtual double getMass() const { return denisity * getVolume(); }  
  void DisplayBasicInfo() const {
    cout << "type: " << type << endl <<
    "denisity: " << denisity << endl <<
    "volume: " << getVolume() << endl <<
    "mass: " << getMass() << endl;
  }
  virtual void Display() const {
    DisplayBasicInfo();
    cout << " " << endl;
  }
};

class Ball : public Body{
  double radius;
  public:
  Ball(double r, double denisity) : Body("Ball", denisity) { Set(r); }
  void Set(double r){
    if(r <= 0) throw domain_error("Radius must be positive");
    radius = r;
  }
  double getRadius() const { return radius; }
  double getVolume() const { return 4*pow(radius,3)*PI/3; }
  void Display() const {
    DisplayBasicInfo();
    cout << "radius: " << radius << endl;
  }
};

class Brick : public Body{
  double a,b,c;
  public:
  Brick(double a, double b, double c, double denisity) : Body("Brick", denisity) { Set(a,b,c); }
  void Set(double a, double b, double c){
    if(a <= 0 || b <= 0 || c <= 0) throw domain_error("Sides must be positive");
    this->a = a;
    this->b = b;
    this->c = c;
  }
  double getA() const { return a; }
  double getB() const { return b; }
  double getC() const { return c; }
  double getVolume() const { return a*b*c; }
  void Display() const {
    DisplayBasicInfo();
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
  }
};


class Vehicle{
  string type;
  double mass;
  public:
  Vehicle(string t, double m) : type(t) { Set(m); }
  void Set(double m){
    if(m <= 0) throw domain_error("Mass must be positive!");
    mass = m;
  }
  virtual ~Vehicle() {}
  string getType() const { return type; }
  double getMass() const { return mass; }
  virtual double totalMass() const = 0;
  void DisplayBasicInfo() const {
    cout << "type: " << type << endl <<
    "mass: " << mass << endl <<
    "total mass: " << totalMass() << endl;
  }
  virtual void Display() const {
    DisplayBasicInfo();
  }
};
class Car : public Vehicle{
  int numOfPassangers;
  double massOfPass[5];
  public:
  Car(double mass, int numOfP, double arr[5]) : Vehicle("Car",mass) { Set(numOfP, arr); }
  void Set(int numOfP, double arr[]){
    if(numOfP <= 0 || numOfP > 5) throw domain_error("Num of passangers must be positive and not grather than 5!!");
    for (int i = 0; i < numOfP; i++){
      if(arr[i] <= 0) throw domain_error("Mass of passanger must be positive!!");
    }
    numOfPassangers = numOfP;
    for (int i = 0; i < numOfP; i++) massOfPass[i] = arr[i];
  }
  double totalMass() const {
    double sum = 0.0;
    for (int i = 0; i < numOfPassangers; i++)
    {
      sum += massOfPass[i];
    }
    return sum + getMass();
  }
  void Display() const override {
    DisplayBasicInfo();
    cout << "numOfPassangers: " << numOfPassangers << endl;
    cout << "mass per passanger: ";
    for (int i = 0; i < numOfPassangers; i++) cout << massOfPass[i] << ", ";
    cout << " " << endl;
  }
};

class Truck : public Vehicle{
  double massOfCargo;
  public:
  Truck(double mass, double massOfC) : Vehicle("Truck",mass) { Set(massOfC); }
  void Set(double massOfC){
    if(massOfC < 0) throw domain_error("Mass of cargo must be positive!");
    massOfCargo = massOfC;
  }
  double totalMass() const {
    return massOfCargo + getMass();
  }
  void Display() const override {
    DisplayBasicInfo();
    cout << "mass of cargo: " << massOfCargo << endl;
    cout << " " << endl;
  }
};

int main(){
  Vehicle *vehicle[5];
  double arr[5] = {1.3, 2.5, 4.1, 3.3, 5.1}; 
  vehicle[0] = new Car(2.1, 5, arr);
  vehicle[1] = new Truck(4.3, 1.1);
  vehicle[2] = new Car(2.1, 5, arr);
  vehicle[3] = new Truck(2.3, 3.1);
  vehicle[4] = new Car(2.1, 5, arr);

  for (int i = 0; i < 5; i++)
  {
    vehicle[i]->Display();
    cout << " " << endl;
  }
  for (int i = 0; i < 5; i++)
  {
    delete vehicle[i];
  }
  
  


  /*
  Body *bodies[5];
  bodies[0] = new Ball(2.3, 1.0);
  bodies[1] = new Brick(1.3, 3.4, 5.1, 6.1);
  bodies[2] = new Ball(2.3, 2.0);
  bodies[3] = new Brick(1.6, 5.4, 7.1, 4.1);
  bodies[4] = new Ball(2.3, 3.0);
  
  for (int i = 0; i < 5; i++)
  {
    bodies[i]->Display();
    cout << " " << endl;
  }
  for (int i = 0; i < 5; i++)
  {
    delete bodies[i];
  }
  */

  /*
  GeometricBody *bodies[5];
  bodies[0] = new Sphere(2.3, "Sphere");
  bodies[1] = new Cuboid(2.4, 9.1, 7.1, "Cuboid");
  bodies[2] = new Sphere(1.7, "Sphere");
  bodies[3] = new Cuboid(4.1, 2.3, 1.9, "Cuboid");
  bodies[4] = new Sphere(5.8, "Sphere");
  
  for (int i = 0; i < 5; i++)
  {
    bodies[i]->Display();
    cout << " " << endl;
  }
  for (int i = 0; i < 5; i++)
  {
    delete bodies[i];
  }
  */
  

  /*
  Shape *shapes[5];
  shapes[0] = new Circle(3.1, "red");
  shapes[1] = new Rectangle(3.1,2.1, "blue");
  shapes[2] = new Circle(3.1, "orange");
  shapes[3] = new Rectangle(1.5,5.2, "pink");
  shapes[4] = new Circle(8.1, "yellow");
  
  for (int i = 0; i < 5; i++)
  {
    shapes[i]->Display();
    cout << "  " << endl;
  }
  for (int i = 0; i < 5; i++)
  {
    delete shapes[i];
  }
  */
  

  /*
  GeometricShape *shapes[5];
  shapes[0] = new Circle(3.2, "circle");
  shapes[1] = new Circle(8.1, "ajkula");
  shapes[2] = new Circle(5.5, "circle");
  shapes[3] = new Circle(1.7, "circle");
  shapes[4] = new Circle(2.9, "circle");

  for (int i = 0; i < 5; i++)
  {
    shapes[i]->Display();
    cout << " " << endl;
  }
  for (int i = 0; i < 5; i++)
  {
    delete shapes[i];
  }
  */
  
  
  return 0;
}