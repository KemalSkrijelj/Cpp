#include <iostream>
#include <cmath>

using namespace std;

const int connected = 111;
const int not_connected = 222;
const int unknown = 333;

void connectToInternet(int num){
  try
  {
    if(num == 111){
      cout << "We are connected to internet!!" << endl;
    }else if (num == 222)
    {
      throw 222;
    }else if (num == 333)
    {
      throw 333;
    }
  }
  catch(int error)
  {
    cout << "Error: " << error << endl;
    if(error == 222){
      cout << "Please check your connection" << endl;
    }else if (error == 333)
    {
      cout << "Contact your service provider!!" << endl;
    }
  }  
}

void doSomething(int num){
  try
  {
    if(num > 100){
      cout << "Number is bigger than 100." << endl;
    }else{
      throw 2;
    }
  }
  catch(...)
  {
    cout << "An error has occurred"<< endl;
  }
  
}

void multiple(int num1, int num2){
  try{
    if(num2 == 0){
      throw invalid_argument("Errrroor, because second num is 0");
    }else{
      cout << num1 * num2;
    }
  }
  catch(invalid_argument s){
    cout << s.what();
  }
}
int main(){
  connectToInternet(unknown);
  doSomething(3);
  multiple(2, 0);

  return 0;
}