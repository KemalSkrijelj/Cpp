#include <iostream>
#include <cmath>

using namespace std;

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

bool isPrime(int n){
  for (int i = 2; i < n; i++)
  {
    if(n % i == 0) return false;
  }
  return true;
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
int main(){
  int p,q,r;
  cin >> p >> q >> r;
  cout << p <<" " << q << " " << r << endl;
  RotateLeft(p,q,r);
  cout << "After rotate: " << p << ", "<< q << ", " << r;

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