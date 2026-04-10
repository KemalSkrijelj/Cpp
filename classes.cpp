#include <iostream>
#include <math.h>

using namespace std;

class Rectangle{
  double width, height;
  public:

  Rectangle(){
    width = 1;
    height = 1;
  };

  Rectangle(double h, double w){
    width = w;
    height = h;
  };
  
  double getWidth() const {
    return width;
  }

  double getHeight() const {
    return height;
  }

  void setHeight(double h){
    height = h;
  }

  void setWidth(double w){
    width = w;
  }

  double getArea(){
    return width*height;
  }

  double getPerimeter(){
    return 2*(width+height);
  }
  void output(){
    cout << "Area: " << getArea() << endl;
  }
};

class Student{
  string name, surname;
  int id, yearOfStudy, grades[10];
  public:

  Student(string newName, string newSurname, int newID){
    if(newID <= 0){
      throw string("Invalid ID!");
    }
    name = newName;
    surname = newSurname;
    id = newID;
    yearOfStudy = 1;
    for (int i = 0; i < 10; i++)
    {
      grades[i] = 1;
    }
  }

  string getName() const {return name;}
  string getSurname() const {return surname;}
  int getID() const {return id;}
  int getYearOfStudy() const {return yearOfStudy;}

  void setGrade(int course, int grade){
    if(course < 1 || course > 10) throw string("Bad course!");
    if(grade < 1 || grade > 5) throw string("Bad grade!");
    grades[course-1] = grade;
  }
  int getGrade(int course) const {
    if(course < 1 || course > 10) throw string("Bad course");
    return grades[course-1];
  }
  bool isPassed(){
    int counter = 0;
    for (int i = 0; i < 10; i++)
    { 
      if (grades[i] == 1) counter++;
    }
    return counter <= 1;
  }
  double getAvarage() const {
    double sum = 0;
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
      if(grades[i] > 1){
        sum += grades[i];
        counter++;
      }
    }
    if (counter == 0) return 1;
    return sum/counter;
  }
  void transferToNextYear(){
    for (int i = 0; i < 10; i++) grades[i] = 1;
    yearOfStudy++;
  }
  void Display(){
    cout << "Name:" << name << endl
         << "Surname:" << surname << endl
         << "YearOfStudy:" << yearOfStudy << endl 
         << "Avarage of grades:" << getAvarage() ;
  }
};

int main(){
  try
  {
    Student s1("Kemal", "Skrijelj", 1010); // 3 parameters, because my constructor have 3 parameters
    s1.setGrade(1,5);
    s1.setGrade(2,3);
    s1.setGrade(3,4);
    s1.setGrade(4,1);
  
    cout << "Grade from course 1: " << s1.getGrade(1) << endl;
  
    cout << "Avarage: " << s1.getAvarage();
  
    if(s1.isPassed()){
      cout << "Student passed a year!!" << endl;
    }else{
      cout << "Student don't passed a year!!" << endl;
    }
  
    s1.Display();
  
    s1.transferToNextYear();
  
    cout << "After transfer to next year: " << endl;
  
    s1.Display();
    cout << endl;
  }
  catch(string error)
  {
    cout << "Error: " << error;
  }
  
  
  /*
  Rectangle r1;
  
  r1.setWidth(4);
  r1.setHeight(40);
  
  Rectangle r2;
  
  r2.setWidth(3.5);
  r2.setHeight(35.9);
  
  cout << "R1 aria: " << r1.getArea() << endl;
  cout << "R1 perimeter: " << r1.getPerimeter() << endl;
  
  cout << "R2 perimeter: " << r2.getArea() << endl;
  cout << "R2 perimeter: " << r2.getPerimeter() << endl;
  */
  
  return 0;
}