#include <iostream>
#include <cmath>

using namespace std;

int subtraction(int *x, int *y){
  *x =  *y- *x;
  return *x;
}
void value(int a){ //not work this func
  a = 15; 
}
void reference(int *p){
  *p = 80;
}

int main(){
  int x = 5;
  int y = 7;
  cout << "x:" << x << endl;
  cout << "y:" << y << endl;
  value(x); // not work this func because this func don't have access for this variable
  reference(&y);
  cout << "Substraction value: " << subtraction(&x, &y) << endl;
  cout << "New x:" << x << endl;
  cout << "New y:" << y << endl;


  /*
  string name = "Kemal";
  int age = 20;
  string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
  int x = 3;
  
  string *pName = &name;
  int *pAge = &age;
  string *pfreePizzas = freePizzas;
  int *pointer = &x;
  
  cout << *pName << endl;
  cout << *pAge << endl;
  cout << *pfreePizzas << endl;
  cout << *pointer;
  */
  return 0;
}