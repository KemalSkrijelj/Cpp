#include <iostream>
#include <cmath>

using namespace std;

bool isValidTriangle(double a, double b, double c){
  if(a+b <= c || a+c <= b || b+c <= a){
    return false;
  }else{
    return true;
  }
}

bool isPrime(int x){
  for (int i = 2; i < x; i++)
  {
    if(x % i == 0) return false;
  }
  return true;
}
int main (){
  int n;
  cin >> n;
  if(n < 4 || n > 20){
    cout << "Invalid input!!!";
  }else{
    for(int j = 1; j <= (N - 1) / 2; j++) cout << " ";      // top
 cout << "*" << endl;
 for(int i = 1; i <= (N - 1) / 2; i++){ // upper half
     for(int j = 1; j <= (N - 1) / 2 - i; j++) cout << " ";
     cout << "*";
     for(int j = 1; j <= 2 * i - 1; j++) cout << " ";
     cout << "*" << endl;
 }
 for(int i = (N - 2) / 2; i >= 1; i--){         // lower half
     for(int j = 1; j <= (N - 1) / 2 - i; j++) cout << " ";
     cout << "*";
     for(int j = 1; j <= 2 * i - 1; j++) cout << " ";
     cout << "*" << endl;
 }
 for(int j = 1; j <= (N - 1) / 2; j++) cout << " ";         // bottom
 cout << "*" << endl

  }

  /*
  int m, n;
  cin >> m >> n;
  
  for (int i = m; i <= n; i++)
  {
    if(isPrime(i)) cout << i << " ";
  }
  */

  /*
  int n,odd = 0, even = 0, i = 0;
  
  while (i < 10)
  {
    cin >> n;
    if(n % 2 == 0){
      even++;
    }else{
      odd++;
    }
    i++;
  }
  cout << "Available even num is " << even << endl;
  cout << "Available odd num is " << odd;
  */
  
  /*
  double a,b,c, p, s;
  cin >> a >> b >> c;
  if(!isValidTriangle(a,b,c) ){
    cout << "Invalid input";
  }else{
    s =(a+b+c)/2;
    p = sqrt(s*(s-a)*(s-b)*(s-c));
    cout << "Area of triangle is: " << p << endl;
  }
  */
  return 0;
}