#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
bool isPerfect(int x){
  double sum = 0;
  for(int i = 1; i < x; i++)
  {
    if(x % i == 0){
      sum += i;
    }
  }
  if (sum == x) return true;
  else return false;
}
*/
void func(int n, int &MaxDigit, int &MinDigit){
  MaxDigit = 0;
  MinDigit = 9;
  int digit;
  while (n != 0)
  {
    digit = n % 10;
    if(digit < MinDigit ) MinDigit = digit;
    if(digit > MaxDigit ) MaxDigit = digit;
    n /= 10;
  }
  
}

int main(){
  int h, w;
  cout << "Enter height: ";
  cin >> h;
  cout << "Enter width: ";
  cin >> w;
  if (h < 3 || h > 20 || w < 2*h+3 || w > 70)
  {
    cout << "Incorrect parametars";
  }else
  {
      //Up
      for (int i = 1; i <= h-1; i++) cout << " ";
      for (int i = 1; i <= w-2*h+2; i++) cout << "+"; 
      cout << endl;

      //Mid
      for (int j = 2; j < h-1; j++){
        for (int i = 1; i <= h-j; i++) cout << " ";
        cout << "+";
        for (int i = 1; i <= w-2*h-2+2*j; i++) cout << " ";
        cout << "+" << endl;
      }

      //Down
      for (int i = 1; i <= w; i++) cout << "+";
      cout << endl;
  }
  
  
  /*
  int minimum, maximum, number;
  cout << "Enter num: ";
  cin >> number;
  func(number,maximum, minimum);
  cout << "Number: " << number << ",max digit: "<< maximum << ", min digit: " << minimum;
  */
  
  /*
  for (int i = 1; i < 100; i++)
  {
    if (isPerfect(i))
    {
      cout << "Perfect num: " << i << endl;
    }
  }
  */

  
  /*
  int n;
  cin >> n;
  if (n < 4 || n > 20)
  {
    cout << "Invalid parametars";
  }else{
    //TOP
    for (int i = 1; i <= (n-1) / 2; i++) cout << " ";
    cout << "*" << endl;
    
    //UPPER-MID
    for (int i = 1; i <= (n-1) / 2; i++){                     
      for (int j = 1; j <= (n-1)/2-i; j++) cout << " ";
      cout << "*";
      for (int j = 1; j <= 2*i-1; j++) cout << " ";
      cout << "*" << endl;
    }
    
    //LOWER-MID
    for (int i = (n-1)/2; i >= 1 ; i--){
      for (int j = 1; j <= (n-1)/2-i; j++) cout << " ";
      cout << "*" ;
      for (int j = 1; j <= 2*i-1; j++) cout << " ";
      cout << "*" << endl;
    }
    
    //BOTTOM
    for (int j = 1; j <= (n-1)/2; j++) cout << " ";
    cout << "*" << endl;
  }
  */

  return 0;
}