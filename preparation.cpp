#include <iostream>
#include <cmath>

using namespace std;

bool isTriangle(double a, double b, double c){
  if (a + b <= c || b + c <= a || a + c <= b) return false;
  return true;
}


bool isPerfect(int n){
  int sum = 0;
  for (int i = 1; i < n; i++)
  {
    if (n % i == 0) sum += i;
  }
  if (sum == n) return true; 
  else return false;
}

void minMaxDigit(int n, int &minDigit, int &maxDigit){
  minDigit = 9, maxDigit = 0;
  while(n > 0){
    int digit = n % 10;
    if(digit > maxDigit) maxDigit = digit;
    if(digit < minDigit) minDigit = digit;
    n /= 10;
  }
}

bool isPrime(int x){
  for (int i = 2; i < x; i++)
  {
    if(x % i == 0) return false;
  }
  return true;
}

bool isPrimeFactor(int x, int i){
  if(x % i == 0 && isPrime(i)){
    return true;
  }
  return false;
}


double Sum(int N, double x){
  double sum = 0, sign = 1;
  for (int i = 0; i < N; i++)
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
  cout << "Enter n and x: "<< endl;
  cin >> n >> x;
  cout << "Sum is " << Sum(n,x);

  /*
  int a, b, sumOfAllDivOfA = 0, sumOfAllDivOfB = 0;
  cout << "Enter a and b: ";
  cin >> a >> b;
  for (int i = 1; i < a; i++)
  {
    if(a % i == 0) sumOfAllDivOfA  += i;
  }
  for (int i = 1; i < b; i++)
  {
    if(b % i == 0) sumOfAllDivOfB  += i;
  }
  if (sumOfAllDivOfA == b && sumOfAllDivOfB == a)
  {
    cout << a << " and " << b << " are amicable numbers";
  }
  */


  /*
  double n, product = 1;
  int counter = 0;
  while (n != 0)
  {
    cin >> n;
    if(n != 0){
      product *= n;
      counter++;
    }
  }
  cout << "Geomteric mean is: " << pow(product, 1. / counter);
  */


  /*
  int n;
  cin >> n;

  for (int i = 2; i < n; i++)
  {
    if (isPrime(i) && isPrime(i+2))
    {
      cout << "(" << i << ", " << i+2 << ")";
    }
  }
  */
  

  /*
  int n;
  cin >> n;
  for (int i = 2; i < n; i++)
  {
    if(isPrimeFactor(n,i)){
      cout << i << " ";
    }
  }
  */
  
  /*
  int n;
  int posNums = 0, negNums = 0;
  cout << "Enter 10 numbers: ";
  for (int i = 0; i < 10; i++)
  {
    cin >> n;
    if (n == 0) continue;
    else if(n > 0) posNums++;
    else negNums++;
  }
  cout << "Positive numbers: " << posNums << ", negative numbers: " << negNums;
  */
  

  /*
  int n, max, min;
  cout << "Enter the num: ";
  cin >> n;
  minMaxDigit(n,min,max);
  cout << "Num: " << n << ", min digit is " << min << ", max digit is " << max;
  */

  
  /*
  int n;
  for (int i = 1; i < 100; i++)
  {
    if(isPerfect(i)){
      cout << i << " ";
    }
  }
  */
  
  
  /*
  int m, n;
  cout << "Enter m and n: \n";
  cin >> m >> n;
  for (int i = m; i <= n; i++)
  {
    if(isPrime(i)){
      cout << i << " ";
    }
  }
  */
    

  /*
  double a,b,c,p,s;
  cout << "Enter a side of triangles: ";
  cin >> a >> b >> c;
  if (!isTriangle)
  {
    cout << "Invalid triangle!!";
  }else
  {
    s = (a+b+c)/2;
    p= sqrt(s*(s-a)*(s-b)*(s-c));
    cout << "Area of triangle is: " << p;
  }
  */
  
  return 0;
}