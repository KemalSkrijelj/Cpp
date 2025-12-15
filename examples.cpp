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

/*
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
*/
bool isPrime(int x){
  for (int i = 2; i < x; i++)
  {
    if(x % i == 0) return false;
  }
  return true;
}

int SumDIv(int x){
  int sum = 0;
  for (int i = 1; i < x; i++)
  {
    if(x % i == 0) sum += i;
  }
  return sum;
}

int sumOfDigit(int x){
  int sum = 0;
  while (x != 0)
  {
    int digit = x % 10;
    sum += digit;
    x /= 10;
  }
  return sum;
}


double Sum(int n, double x){
  double sum = 0, sign = 1;  //sign je ovde brojilac
  for (int i = 0; i <= n; i++)
  {
    double product = x;
    for (int j = 1; j < i; j++) product *= (x+j);
    sum += sign / product;
    sign = -sign;
  }
  return sum;
}
int main(){
  int n;
  double x;
  cout << "Enter n and x: ";
  cin >> n >> x;
  cout << "Sum is: " << Sum(n, x);

  /*
  int n;
  cout << "Enter the num: ";
  cin >> n;
  cout << "Sum of digits is: " << sumOfDigit(n);
  */

  
  /*
  int h;
  cout << "Enter the height: ";
  cin >> h;
  if (h < 3 || h > 20)
  {
    cout << "Invalid parametar";
  }else{
    for (int i = 1; i < h; i++)
    {
      for (int j = 1; j <= h-i; j++) cout << " ";
      if(i != 1) cout << "#";
      for (int j = 1; j < i-1; j++) cout << " ";
      for (int j = 1; j <= i; j++) cout << "#";
      cout << endl;
    }
    for (int i = 1; i < 2*h; i++) cout << "#";
  }
  */
  

  /*
  int a, b;
  cout << "Enter a and b: \n";
  cin >> a >> b;
  cout << "Numbers " << a << " and " << b;
  if (SumDIv(a) == b && SumDIv(b) == a)
  { 
    cout << " are amicable!";
  }else {
    cout << "are not amicable!";
  }
  */
  

  /*
  double num, product = 1;
  int counter = 0;
  cout << "Enter the nums(0 is break): ";
  do
  {
    cin >> num;
    if(num == 0) break;
    product *= num;

  } while (num != 0);
  
  cout << "Geometric mean is: " << pow(product, 1./counter);
  */
  

  /*
  int n;
  cout << "Enter num: ";
  cin >> n;
  for (int i = 2; i < n-2; i++)
  {
    if (isPrime(i) && isPrime(i+2))
    {
      cout << "Twin prime: " << i << ", " << i+2<< endl;
    }
  }
  */

  
  /*
  int n;
  cout << "Enter num: ";
  cin >> n;
  
  for (int i = 2; i < n; i++)
  {
    if(n % i == 0 && isPrime(i)) cout << "Prime factor: " << i << endl;
  }
  */
  

  /*
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
  */
    
  
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