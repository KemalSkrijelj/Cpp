#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void MinMaxDigit(int n, int &MaxDigit, int &MinDigit){
  MaxDigit = 0;
  MinDigit = 9;
  
  while (n != 0)
  {
    int digit = n % 10;
    if(digit > MaxDigit) MaxDigit = digit;
    if(digit < MinDigit) MinDigit = digit;
    n /= 10;
  }
}

int main() {
  int num;
  cout << "Enter num: ";
  cin >> num;
  int minNum, maxNum;
  MinMaxDigit(num, maxNum, minNum);
  cout << "Max num is: " << maxNum << endl;
  cout << "Min num is: " << minNum << endl;
  /*
  int num;
  cout << "Enter num: ";
  cin >> num;
  int divisors = 0;
  for (int i = 1; i < num; i++)
  {
    if (num % i == 0)
    {
      divisors += i;
    }
  }
  if (divisors == num){
    cout << "Num is perfect";
  }
  else{
    cout << "Num is not perfect";
  }
  */
  
  return 0;
}