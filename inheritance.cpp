#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

using namespace std;

const double PI = 3.14;
const double PI_NEW = 4 * atan(1);

class Shape{
  string color;
  public:
  virtual ~Shape() {}
  Shape(string c) { color = c; }
  string getColor() const { return color; }
  virtual string getType() const { return  "Some geometric shape"; }
  virtual double getCircumference() const = 0;
  virtual double getArea() const = 0;
  void DisplayBasicInfo() const {
    cout << "type: " << getType() << endl <<
    "color: " << getColor() << endl <<
    "circumference: " << getCircumference() << endl <<
    "area: " << getArea() << endl;
  }
  virtual void DisplayShape() const {
    DisplayBasicInfo();
  }
};

class Circle : public Shape{
  double radius;
  public:
  Circle(double r, string color) : Shape(color) { Set(r); }
  void Set(double r){
    if (r <= 0) throw domain_error("Radius must be positive!");
    radius = r;
  }
  double getRadius() const { return radius; }
  string getType() const { return "Circle"; }
  double getCircumference() const { return 2*radius*PI; }
  double getArea() const { return radius*radius*PI; }
  void DisplayShape() const {
    DisplayBasicInfo();
    cout << "radius: " << radius << endl;
  }
};

class Rectangle : public Shape{
  double a, b;
  public:
  Rectangle(double a, double b, string color) : Shape(color) { Set(a, b); }
  void Set(double a, double b){
    if(a <= 0 || b <= 0) throw domain_error("A or B is negative, it must be positive!");
    this->a = a;
    this->b = b;
  }
  string getType() const { return "Rectangle"; }
  double getArea() const { return a * b; }
  double getCircumference() const { return 2*a + 2*b; }
  void DisplayShape() const {
    DisplayBasicInfo();
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
  }
};

class GeometricBody{ // klasa apstracna, ona postaje abstract kada minimum 1 funkcija postane virtual, a kad je abstracna znaci da ne mozemo od nje nap. objekat
  string type;
  public:
  virtual ~GeometricBody() {} // desctructor we must have!!!
  GeometricBody(string t) { type = t; }
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
  void Set(double r) {
    if(r <= 0) throw domain_error("Radius must be postive!");
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
  double a;
  double b;
  double c;
  public:
  Cuboid(double a, double b, double c, string type) : GeometricBody(type) { Set(a, b, c); }
  void Set(double a, double b, double c) {
    if(a <= 0 || b <= 0 || c <= 0) throw domain_error("Radius must be postive!");
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
  double density;
  public:
  virtual ~Body() {}
  Body(string t, double d) : type(t) { Set(d); }
  void Set(double d){
    if(d <= 0) throw domain_error("Density must be positive");
    density = d;
  }
  string getType() const { return type; }
  virtual double getVolume() const = 0; // ovo nam omogucava da u child klasi uzmemo tacnu Volume te neke child klase, i kad stavimo = 0 onda MORAMO da je definisemo u child
  virtual double getMass() const { return density * getVolume(); } // ovdje ne moramo je definisati u child klasi jer vraca neku vrijednost
  void DisplayBasicInfo() const {
    cout << "type: " << type << endl <<
    "volume: " << getVolume() << endl <<
    "mass: " << getMass() << endl;
  }
  virtual void Display() const {
    DisplayBasicInfo();
  }
};

class Ball : public Body{
  double radius;
  public:
  Ball(double density, double r) : Body("Ball", density) { Set(r); }
  void Set(double r){
    if(r <= 0) throw domain_error("Radius must be positive!");
    radius = r;
  }
  double getRadius() const { return radius; }
  double getVolume() const { return 4*(radius*radius*radius)*PI_NEW / 3; }
  void Display() const override {
    DisplayBasicInfo();
    cout << "radius: " << radius;
  }
};

class Brick : public Body{
  double a;
  double b;
  double c;
  public:
  Brick(double density, double a, double b, double c) : Body("Brick", density) { Set(a, b, c); }

  void Set(double a, double b, double c) {
    if(a <= 0 || b <= 0 || c <= 0) throw domain_error("Each side must be postive!");
    this->a = a;
    this->b = b;
    this->c = c;
  }
  double getA() const { return a; }
  double getB() const { return b; }
  double getC() const { return c; }
  double getVolume() const { return a*b*c; }
  void Display() const override { // ovo OVERRIDE nam pomaze da nam javi error ako nisu dobro copy display func iz parent klase
    DisplayBasicInfo();
    cout << "a: " << a << endl <<
    "b: " << b << endl << 
    "c: " << c << endl;
  }
};


class Vehicles{
  string type;
  double mass;
  public:
  virtual ~Vehicles() {}
  Vehicles(string t, double m):type(t) { Set(m); }
  void Set(double m){
    if(m <= 0) throw domain_error("Mass must be positive!");
    mass = m;
  }
  string getType() const { return type; }
  double getMass() const { return mass; }
  virtual double getTotalMass() const = 0;
  void DisplayBasicInfo() const {
    cout << "type: " << type << endl <<
    "mass: " << mass << endl <<
    "totalMass: " << getTotalMass() << endl; 
  }
  virtual void Display() const {
    DisplayBasicInfo();
    cout << endl;
  }
};

class Car : public Vehicles{
  int numOfPassangers;
  double massesOfPassangers[5];
  public:
  Car(double mass, int numOfPass, double arr[5]) : Vehicles("Car", mass) { Set(numOfPass, arr); }
  
  void Set(int num, double arr[]){
    if(num < 0 || num > 5) throw domain_error("Num of passangers must be from 0 to 5");
    numOfPassangers = num;

    for (int i = 0; i < num; i++)
    {
      if(arr[i] <= 0) throw domain_error("Number in arr must be positive!");
      massesOfPassangers[i] = arr[i];
    }
  }
  double getTotalMass() const {
    double sum = getMass();
    for (int i = 0; i < numOfPassangers; i++)
    {
      sum += massesOfPassangers[i];
    }
    return sum;
  }
  void Display() const override {
    DisplayBasicInfo();
    cout << "num of pass: " << numOfPassangers << endl;
    cout << endl;
  }
};

class Truck : public Vehicles{
  double massOfCargo;
  public:
  Truck(double mass, double massOfC) : Vehicles("Truck", mass) { Set(massOfC); }
  void Set(double massOfC){
    if(massOfC <= 0) throw domain_error("Mass of cargo must be positive!");
    massOfCargo = massOfC;
  }
  double getTotalMass() const {
    double sum = getMass() + massOfCargo;
    return sum;
  }
  void Display() const override{
    DisplayBasicInfo();
    cout << "mass of cargo: " << massOfCargo;
    cout << endl;
  }
};

int main(){
  Vehicles *vehicle[5];
  double arr[5] = {1.2, 2.3, 3.1, 4.3, 2.1};
  vehicle[0] = new Car(2.3, 4, arr);
  vehicle[1] = new Truck(2.3, 2.3);
  vehicle[2] = new Car(2.3, 4, arr);
  vehicle[3] = new Truck(2.3, 1.7);
  vehicle[4] = new Car(2.3, 4, arr);

  for (int i = 0; i < 5; i++)
  {
    vehicle[i]->Display();
    cout << " " << endl;
  }
  for (int i = 0; i < 5; i++)
  {
    delete vehicle[i];
  }
 

  /*BODY, BRICK AND BALL
  Body *bodies[5];
  bodies[0] = new Ball(3.2, 5.0); // we represent polymorphic because it can represent other types of objects, ex. (Ball, Brick...)
  bodies[1] = new Brick(1.1, 3.2, 1.6, 1.2); // brick je objekat, a pokazivac je Body
  bodies[2] = new Ball(5.3, 3.2);
  bodies[3] = new Brick(0.3, 4.2, 1.1, 2.4);
  bodies[4] = new Ball(6.6, 3.2);

  for(int i = 0; i < 5; i++)
  {
    bodies[i]->Display();
    cout << " " << endl;
  }

  for(int i = 0; i < 5; i++)
  {
    delete bodies[i];
  }
  */

  /* GEOMETRIC BODY, SPHERE, CUBOID
  GeometricBody *body[5];
  
  body[0] = new Sphere(1.8, "red");
  body[1] = new Cuboid(1, 2, 3, "black");
  body[2] = new Sphere(3.8, "yellow");
  body[3] = new Cuboid(4, 5, 6, "green");
  body[4] = new Sphere(0.8, "gray");
  
  for (int i = 0; i < 5; i++)
  {
    body[i]->Display();
    cout << " " << endl;
  }
  
  for (int i = 0; i < 5; i++)
  {
    delete body[i];
  }
  */
  

  //SHAPES, CIRCLE, RECTANGLE
  /*
  Shape *shapes[5]; // this is array of 3 pointers on object which type Shape
  shapes[0] = new Circle(2.5, "red"); // first pointer
  shapes[1] = new Circle(3.5, "pink"); // second pointer
  shapes[2] = new Circle(4.5, "blue"); // third pointer
  shapes[3] = new Rectangle(4, 3, "yellow"); 
  shapes[4] = new Rectangle(4, 5, "green"); 
  
  for (int i = 0; i < 5; i++)
  {
    shapes[i]->DisplayShape();
    cout << " " << endl;
  }
  
  for (int i = 0; i < 5; i++) // we must to delete a pointers from memory, because if we don't do it we cause a memory leak
  {
    delete shapes[i];
  }
  */
  
  return 0;
}