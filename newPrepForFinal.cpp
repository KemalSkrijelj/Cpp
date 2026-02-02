#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n){
  for (int i = 2; i < n; i++)
  {
    if(n % i == 0) return false;
  }
  return true;
}
double f(int n, int k){
  double sum = 0, p = 1;
  if(k < 0) return -1;
  for (int i = 0; i < k; i++)
  {
    sum += 1 / p;
    p *= n;
  }
  return sum;
}

int PrimePi(int n){
  int count = 0;
  for (int i = 2; i <= n; i++)
  {
    if(isPrime(i)) count++;
  }
  return count;
}
void RotateLeft(int &p, int &q, int &r){
  int temp = p;
  p = q; q = r; r = temp;
}

void minMaxPrime(int n, int &minPrime, int &maxPrime){
  minPrime = 9, maxPrime = 0;
  for (int i = 2; i < n; i++)
  {
    if (n % i == 0 && isPrime(i))
    {
      if(i < minPrime) minPrime = i;
      if(i > maxPrime) maxPrime = i;
    }
  }
  
}
bool isComposite(int n){
  if(n > 1 && !isPrime(n)) return true;
  else return false;
}
int main(){
  int a, b;
  cin >> a >> b;

  bool isAvaible = false;
  for (int i = a; i < b; i++)
  {
    if(isComposite(i)){
      cout << i << " ";
      isAvaible = true;
    }
  }

  if(!isAvaible) cout << "Composite nums not availble!";
  
  /*
  int h;
  cin >> h;
  if(h < 1 || h > 20){
    cout << "Invalid input!!";
  }else{
    for (int i = 0; i <= h-1; i++) cout << char('H' - i);
    for (int i = 0; i < h-1; i++) cout << char('B' + i);
    cout << endl;
    
    for (int i = 1; i < h-1; i++)
    {
      for (int j = 0; j < i; j++) cout << " ";
      for (char c = 'H' - i; c >= 'A'; c--) cout << c;
      for (char c = 'B'; c <= 'H'- i; c++) cout << c;
      
      cout << endl;
    }
    
    for (int i = 0; i < h-1; i++) cout << " ";
    cout << 'A';
    
  }
  */
  

  /*
  int n, min, max;
  cin >> n;
  minMaxPrime(n, min, max);
  cout << "Num " << n << ", minPrime: " << min << ", maxPrime: " << max;
  */

  /*
  int p,q,r;
  cin >> p >> q >> r;
  cout << p <<" " << q << " " << r << endl;
  RotateLeft(p,q,r);
  cout << "After rotate: " << p << ", "<< q << ", " << r;
  */

  /*
  int n;
  cin >> n;
  int res = PrimePi(n);
  cout << "Num of PrimePi is " << res;
  */

  /*
  int n, k;
  cin >> n >> k;
  double result = f(n,k);
  if(result == -1) cout << "Ivalid values!!" << endl;
  else cout << "Result: " << result << endl;
  */

  /*
  double n, sum = 0;
  int counter = 0;
  while (n != 0)
  {
    cin >> n;
    if(n != 0){
      sum += 1/n;
      counter++;
    }
  }
  cout << "Haromic mean is " << counter / sum << endl;
  */
  

  /*
  int h, w;
  cin >> h >> w;
  
  if(h < 3 || h > 20 || w < h || h > 79){
    cout << "Invalid input!!";
  }else{
    cout << "+";
    for (int i = 0; i < h; i++) cout << "-";
    cout << "+";
    for (int i = 0; i < h-2; i++) cout << "-";
    cout << "+" << endl;
    
    for (int i = 1; i < h-1; i++)
    {
      cout << "|";
      for (int j = 1; j <= h; j++) cout << " ";
      cout << "|";
      for (int j = 1; j < h-i-1; j++) cout << " ";
      cout << "/" << endl;
    }
    
    cout << "+";
    for (int i = 0; i < h; i++) cout << "-";
    cout << "+";
  }
  */

  return 0;
}