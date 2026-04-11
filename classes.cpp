#include <iostream>
#include <math.h>
#include <stdexcept>

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

class BankAccount{
  double balance;
  public:
  BankAccount(){
    balance = 0;
  }
  BankAccount(double initialAmount){
    if(initialAmount <= 0){
      throw domain_error("Inital amout mst be greather than 0!");
    }
    balance = initialAmount;
  }
  void Deposit(double amountOfDeposit){
    if(amountOfDeposit <= 0){
      throw domain_error("Bad deposit!!");
    }
    balance += amountOfDeposit;
  }
  void Withdraw(double amountOfWithdraw){
    if(amountOfWithdraw <= 0  || amountOfWithdraw > balance){
      throw domain_error( "Bad withdraw!!");
    }
    balance -= amountOfWithdraw;
  }
  void AddInterest(double interestRate){
    if(interestRate <= 0){
      throw domain_error("Bad interest rate!!");
    }
    balance += balance * interestRate;
  }
  double GetBalance() const {
    return balance;
  }
  void Display(){
    cout << "Balance:" << balance << endl;
  }
};



class Triangle{
  double a,b,c;
  public:
  Triangle(double side1, double side2, double side3){
    if (side1 <= 0 || side2 <= 0 || side3 <= 0 || side1+side2 <= side3 || side2+side3 <= side1 || side1+side3 <= side2)
    {
      throw invalid_argument("Invalid input of sides!");
    }
    a = side1;
    b = side2;
    c = side3;
  }
  void setTriangle(double side1, double side2, double side3){
    if (side1 <= 0 || side2 <= 0 || side3 <= 0 || side1+side2 <= side3 || side2+side3 <= side1 || side1+side3 <= side2)
    {
      throw invalid_argument("Invalid input of sides!");
    }
    a = side1;
    b = side2;
    c = side3;
  }
  double getA() const { return a; };
  double getB() const { return b; };
  double getC() const { return c; };
  double getCircumference() const{
    return a+b+c;
  }
  double getArea() const {
  double s = getCircumference() / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
  }
  bool isRightAngled(){
    if(pow(a, 2) == pow(b, 2) + pow(c, 2) ||
       pow(b, 2) == pow(c, 2) + pow(a, 2) ||
       pow(c, 2) == pow(a, 2) + pow(b, 2)) {
        return true;
    }
    return false;
  }
  void scalingTriangle(double factor){
    if (factor <= 0)
    {
      throw invalid_argument("Invalid factor!");
    }
    a *= factor;
    b *= factor;
    c *= factor;
  }
  void Display(){
    cout << "Triangle: " << endl
    << "A: " << getA() << endl
    << "B: " << getB() << endl
    << "C: " << getC() << endl
    << "Circumference: " << getCircumference() << endl
    << "Area: " << getArea() << endl
    << "Right angled: " << boolalpha << isRightAngled()<< endl;
  }
};
int main(){
  try{
    Triangle triangle1(3,4,5);
    // triangle1.setTriangle(3,5,7);
    cout << "A: "<< triangle1.getA() << endl; // bad way to display all information
    cout << "B: "<< triangle1.getB() << endl;
    cout << "C: "<< triangle1.getC() << endl;
    cout << "Circumference: "<< triangle1.getCircumference() << endl;
    cout << "Area: "<< triangle1.getArea() << endl;
    cout << "Right angled: "<< boolalpha << triangle1.isRightAngled() << endl; // last row for bad way
    cout << " " << endl;
    triangle1.Display(); // better way to display all information for Triangle
    cout << " " << endl;
    triangle1.scalingTriangle(5);
    cout << "After scaling triangle: " << endl;
    triangle1.Display(); // better way to display all information for Triangle
  }catch(exception &error){
    cout << error.what() << endl;
  }

  /* Bank acc users
  try
  {
    BankAccount user1;
  
    user1.Deposit(500);
    user1.GetBalance();
    user1.Display();
    user1.Withdraw(400);
    user1.GetBalance();
    user1.Display();
  }
  catch(exception &error)
  {
    cout << error.what() << endl;
  }
  */

  /*  STUDENT CLASS
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
  */
  
  
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