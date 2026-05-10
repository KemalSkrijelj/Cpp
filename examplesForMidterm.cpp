#include <iostream>
#include <cmath>

using namespace std;

// class Square{
//   double side;
//   public:
//   Square(double x){ Set(x); }

//   void Set(double x){
//     if(x <= 0){
//       throw domain_error("Bad input! ");
//     }
//     side = x;
//   }

//   double getSide() const {return side;}
//   double getCircumference() const { return 4*side; }
//   double getArea() const { return side*side; }
//   void Scale(double factor){
//     Set(side*factor);
//   }
//   void Display() const{
//     cout << endl <<
//     "Side: " << getSide() << endl <<
//     "Circumference: " << getCircumference() << endl <<
//     "Area: " << getArea() << endl;
//   }
// };

// class Pyramid{
//   double height;
//   Square base;
//   void setHeight(int h){
//     if(h <= 0){
//       throw domain_error("Bad input! ");
//     }
//     height = h;
//   }
//   public:
//   Pyramid(double b, double h): base(b) { setHeight(h); }
//   void Set(double a, double h){
//     base.Set(a);
//     setHeight(h);
//   }
//   Pyramid(Square base, double h) : base(base) { setHeight(h); }
//   void Set(Square a, double h){
//     base = a;
//     setHeight(h);
//   }
//   double getSideOfBase() const { return base.getSide(); }
//   double getHeight() const { return height; }
//   Square getBase() const { return base; }

//   double getArea() const {
//     double a = base.getSide();
//     return a*a + height*sqrt(a*a + 4*height*height); 
//   }
//   double getVolume() const {
//     double a = base.getSide();
//     return a*a*height/3;
//   }

//   void Scale(double factor1, double factor2){
//     Set(getSideOfBase() * factor1, getHeight() * factor2);
//   }
//   void Display() const{
//     cout << endl <<
//     "Side of base: " << getSideOfBase() << endl <<
//     "Height: " << getHeight() << endl <<
//     "Area: " << getArea() << endl <<
//     "Volume: " << getVolume() << endl;
//   }
// };

class Student{
  string name, surname;
  int ID, yearOfStudy, grades[10];
  public:
  Student(string n, string s, int id){
    Set(id);
    name = n;
    surname = s;
    yearOfStudy = 1;
    for (int i = 0; i < 10; i++) grades[i] = 1;
  }
  void Set(int x){
    if(x <= 0){
      throw domain_error("Invalid input!");
    }
    ID = x;
  }
  string getName() const { return name; }
  string getSurname() const { return surname; }
  int getId() const { return ID; }
  int getYearOfStudy() const { return yearOfStudy; }
  void setGrade(int courseNum, int grade);
  int getGrade(int courseNum) const;
  bool isPassed();
  int avarage() const;
  void Display();
};

void Student::setGrade(int courseNum, int grade){
  if(courseNum >= 10 || courseNum <= 1 || grade > 5 || grade < 1){
      throw domain_error("Invalid input!");
    }
    grades[courseNum - 1] = grade;
}

int Student::getGrade(int courseNum) const{
  if(courseNum >= 10 || courseNum <= 1){
      throw domain_error("Invalid input!");
    } 
    return grades[courseNum - 1];
}
bool Student::isPassed(){
  int counter = 0;
    for (int i = 0; i < 10; i++){
      if (grades[i] == 1)  counter++;
    }
    if(counter > 1) 
      return false;
    else
      return true;
}
int Student::avarage() const{
 int subjects = 0;
     int sumOfGrades = 0;
    for (int i = 0; i < 10; i++){
      if (grades[i] != 1){
        subjects++;
        sumOfGrades += grades[i];
      }  
    }
    if(subjects == 0) return 0;
    return sumOfGrades / subjects;
}

void Student::Display(){
  cout << "Name: " << name << " Surname: " << surname << endl
    << "Index: " << ID << " Year of study: " << yearOfStudy << endl;
    cout << "Grades: ";
    for(int i = 0; i < 10; i++) cout << grades[i] << " ";
    cout << endl;
    cout << "Average: " << avarage() << endl;
    cout << "Student can ";
    if(!isPassed()) cout << "not ";
    cout << "pass to the next year" << endl;
}


class Square{
  double side;
  public:
  Square(double x){ Set(x); }
  void Set(double x){
    if(x <= 0) throw domain_error("Bad input!");
    side = x;
  }
  double getSide() const { return side; }
  double getCircumference() const { return 4*side; }
  double getArea() const { return side*side; }
  void Scaling(double factor){ Set(factor * side); }
  void Display(){
    cout << "Square" << endl;
    cout << "Side: " << side << endl;
    cout << "Circumference: " << getCircumference() << endl;
    cout << "Area: " << getArea() << endl;
  }
};

class Pyramid{
  Square base;
  double height;
  public:
  Pyramid(double base, double height) : base(base) { Set(base, height); }
  void Set(double x, double y){
    if(y <= 0 ) throw domain_error("Bad input!");
    base.Set(x);
    height = y;
  }
  Pyramid(Square b, double height) : base(b) { Set(b, height); }
   void Set(Square b, double h){
    if(h <= 0 ) throw domain_error("Bad input!");
    base = b;
    height = h;
  }
  double getSideOfBase() const { return base.getSide(); } // vracanje konkretno neke vrijednosti, ovde npr. vracanje stranice od baze
  double getHeight() const { return height; }
  Square getBase() const { return base; } // funkcija pravi bukvalno kopiju od "pravog" objekta base i moze se kreirate koliko hocemo kopija, on vraca ceo objekat a ne vrijednost
  double getArea() const {
    double a = base.getSide();
    return a*a + height*sqrt(a*a+4*height*height);
  }
  double getVolume() const {
    double a = base.getSide();
    return a*a *height/3;
  }
  void Scaling(double factor1, double factor2){
   Set(factor1 * getSideOfBase(), factor2 * height); 
  }
  void Display() const {
    cout << "Pyramid" << endl;
    cout << "Base side: " << getSideOfBase() << endl;
    cout << "Height: " << height << endl;
    cout << "Area: " << getArea() << endl;
    cout << "Volume: " << getVolume() << endl;
 }
};

class Circle{
  double radius;
  public:
  Circle(){ radius = 1; }
  Circle(double x){ Set(x); }
  void Set(double x){
    if(x <= 0){
      throw domain_error("Bad input!");
    }
    radius = x;
  }
  double getRadius() const { return radius; }
  double getArea() const { return M_PI * radius * radius; }
  double getCircumference() const { return 2*M_PI * radius; }
  void scaling(double factor){
    Set(radius*factor);
  }
  void Display() const {
    cout << 
    "Radius: " << getRadius() << endl <<
    "Area: " << getArea() << endl <<
    "Circumference: " << getCircumference() << endl;
  }
};

class Cylinder{
  Circle base;
  double height;
  public:
  Cylinder() : base(1), height(1) {}
  Cylinder(double b, double h) : base(b)  { Set(b,h); }
  void Set(double x, double y){
    if(x <= 0 || y <= 0){
      throw domain_error("Bad input!");
    }
    base.Set(x);  // or base(x), this we call construcotr and construcor have a function Set.
    height = y;
  }
  double getRadiusBase() const { return base.getRadius(); }
  double getHeight() const { return height; }
  Circle getBase() const { return base; } // use all object from private because if we want to use in main, same as a getHeight function, type is Circle, because this is in main
  double getArea() const { return 2* base.getArea() + base.getCircumference() * height; }
  double getVolume() const { return base.getArea() * height; }
  void scaling(double factor1, double factor2){
    Set(base.getRadius() * factor1, height * factor2);
  }
  void Display() const {
    cout << 
    "Radius base: " << getRadiusBase() << endl <<
    "Height : " << getHeight() << endl <<
    "Area: " << getArea() << endl <<
    "Volume: " << getVolume() << endl;
  }
};


int main(){
  Circle c(3);  
  c.Display();
  Cylinder p(3,4);
  p.Display();


  /*
  Square s(6);
  Pyramid p(s,20);
  Square s2 = p.getBase();
  s2.Scaling(2);
  cout << s2.getSide();
  */

  /*CLASS PYRAMID

  Square b(5);
  b.Display();
  
  Pyramid p(3,2);
  p.Display();
  Pyramid p1(b, 5);
  p1.Display();
  */
 /*
 Student s("Kemal", "Skrijelj", 2190);
 s.setGrade(3,4);  s.setGrade(5,2); s.setGrade(8,5);
 s.Display();
 */

  return 0;
}