#include <iostream>
#include <cmath>

using namespace std;

int isAmbicale(int x){
  int sum = 0;
  for (int i = 1; i < x; i++)
  {
    if(x % i == 0) sum += i;
  }
   return sum;
}

int sumOfDigits(int n) {
  int sum = 0;
  while(n != 0){
    int digit = n % 10;
    sum += digit;
    n /= 10;
  }
  return sum;
}

double func(int n, double x){
  double sum = 1.0 / x, sign = -1;
  double product = x;
  for (int i = 1; i <= n; i++)
  {
    product *= (x+i);
    sum += sign / product;
    sign = -sign;
  }
  return sum;
}

bool isPrime(int n){
  for (int i = 2; i < n; i++)
  {
    if (n % i == 0) return false;
  }
  return true;
}

void minMaxPrime(int n, int &minPrime, int &maxPrime){
  minPrime = n, maxPrime = 0;
  for (int i = 2; i < n; i++)
  {
    if(n % i == 0 && isPrime(i)){
      if (i > maxPrime) maxPrime = i;
      if (i < minPrime) minPrime = i;
    } 
  }
}

int main(){
  int n, min, max;
  cout << "Enter n: ";
  cin >> n;
  minMaxPrime(n, min, max);
  cout << "Number: " << n << " minPrime: " << min << " maxPrime: " << max;

  /*
  int n;
  double x;
  cout << "Enter n and x: ";
  cin >> n >> x;
  cout << "Sum of func is: " << func(n,x);
  */


  /*
  int x;
  cout << "Enter num: ";
  cin >> x;
  cout << "Number: " << x << ", sum of digits: " << sumOfDigits(x);
  */


  /*
  int h;
  cout << "Enter height: ";
  cin >> h;
  if (h < 3 || h > 20)
  {
    cout << "Invalid parametars";
  }else
  {
    for (int i = 1; i <= h-1; i++) cout << " ";
    cout << "#" << endl;
    
    for (int i = 2; i <= h-1; i++)
    {
      for (int j = 1; j <= h-i; j++) cout << " ";
      cout << "#";
      for (int j = 2; j < i; j++) cout << " ";
      for (int j = 1; j <= i; j++) cout << "#";
      cout << endl;
    }
    for (int i = 1; i <= (h*2)-1; i++) cout << "#";
    cout << endl;
  }
  */


  /*
  int a, b;
  cout << "Enter a and b: ";
  cin >> a >> b;
  if (isAmbicale(a) == b && isAmbicale(b) == a)
  {
    cout << a << " and " << b << " are ambicale numbers";
  }else {
    cout << a << " and " << b << " are not ambicale numbers";
  }
  */
  
  /*
  double x, product = 1;
  int counter = 0;
  while (x != 0)
  {
    cin >> x;
    if(x != 0){
      product *= x;
      counter++;
    }
  }
  cout << "Geometic mean is: " << pow(product, 1. / counter);
  */
  
  return 0;
}