#include <iostream>
#include <cmath>

using namespace std;

int main(){
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
  return 0;
}