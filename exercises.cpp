#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
/*
bool isPrime(int n){
  for (int i = 2; i < n; i++)
  {
    if(n % i == 0) return false;
  }
  return true;
}
*/

/*
bool isTriangle(double a, double b, double c){
  if (a+b <= c || b+c <= a || c+a <= b )
  { 
    return false;
  }
  return true;
}
*/
void MaxMinLocal(double arr[], int size, int &NoOfLocMax, int &NoOfLocMin){
  NoOfLocMax = 0, NoOfLocMin = 0;
  for (int i = 1; i < size; i++)
  {
    if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) NoOfLocMax++;
    if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) NoOfLocMin++;
  }
}

int maxDifference(double arr[], int size){
  int maxDiff = 0;
  for (int i = 1; i < size; i++)
  {
    if(arr[i] - arr[i-1] > maxDiff ) maxDiff = arr[i] - arr[i+1];
  }
  return maxDiff;
}

bool isMonotonically(double arr[], int size){
  for (int i = 1; i < size; i++)
  {
    if (arr[i] < arr[i-1]) return false;
  }
  return true;
}

int main(){
  int n;
  cout << "Enter size of arr: ";
  cin >> n;
  double array[n];
  cout << "Enter ell of arr: ";
  for (int i = 0; i < n; i++)
  {
    cin >> array[i];
  }
  if (isMonotonically(array, n))
  {
    cout << "Array is monotonically increasing.";
  }else
  {
    cout << "Array is not monotonically increasing.";
  }
  
  /*
  int n, maximalDifference;
  cout << "Enter the size of arr: ";
  cin >> n;
  double arr[n];
  cout << "Enter elements in arr: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  maximalDifference = maxDifference(arr, n);
  cout << "Maximal difference in this arr is: " << maximalDifference;
  */

  
  /*
  double array[10];
  int localMax, localMin;
  cout << "Enter 10 numbers in arr: ";
  for (int i = 0; i < 10; i++)
  {
    cin >> array[i];
  }
  MaxMinLocal(array, 10, localMax, localMin);
  cout << "Numbers of localMax: " << localMax << ", numbers of localMin: " << localMin;
  */


  /*
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++) cout << " ";
    for (int j = i; j < n; j++) cout << "*";
    for (int j = i; j <= n; j++) cout << "*";
    cout << endl;
  }
  */


  // int m, n;
  // cin >> m >> n;
  // for (int i = m; i <= n; i++)
  // {
  //   int count = 0;
  //   for (int j = 2; j < i; j++)
  //   {
  //     if (i % j == 0){
  //       count++;
  //     }
  //   }
  //   if (count == 0){
  //     cout << i << " ";
  //   }
  // }

  /*
  int n;
  int oddNum = 0, evenNum = 0;
  
  for (int i = 0; i < 10; i++)
  {
    cin >> n;
    if (n % 2 == 0)
    {
      evenNum++;
    }else
    {
      oddNum++;
    }
  }
  if (oddNum > 0 )
  {
    cout << "Odd nums: " << oddNum << endl;
  }else{
    cout << "No \n";
  }
  if (evenNum > 0)
  {
    cout << "Even nums: " << evenNum << endl;
  }else{
    cout << "No \n";
  }
  */

  
  /*
  int n, oddNum = 0, evenNum = 0; 
  for (int i = 0; i < 10; i++)
  {
    cin >> n;
    if (n % 2 == 0)
    {
      evenNum++;
    }else{
      oddNum++;
    }
  }
  cout << "Odd num: " << oddNum << ", Even num: " << evenNum;
  */
  
  /*
  double A, B, C, p,s;
  cout << "Enter A,B,C: ";
  cin >> A >> B >> C;
  if (A <= 0 && B <= 0 && C <= 0 && !isTriangle(A,B,C))
  {
    cout << "Triangle does not exist.";
  }else{
    s = (A+B+C)/2;
    p = sqrt(s*(s-A)*(s-B)*(s-C));
    cout << "Area of triangle is: "<< p<< endl;
  }
  */
  
  /*
  int h;
  cout << "Enter the num of rows: ";
  cin >> h;
  if (h < 1 || h > 20)
  {
    cout << "Invalid parametars!!";
  }else
  {
    for (int i = 1; i <= h; i++)
    {
      for (int j = 1; j <= h-i; j++) cout << " ";
      for (int j = 1; j < i; j++) cout << char('A' + j - 1);
      for (int j = i; j >= 1; j--) cout << char('A' + j - 1);
      cout << endl;
    }
  }
  */

  /*
  int h;
  cout << "Enter h: ";
  cin >> h;
  if (h < 1 || h > 20)
  {
    cout << "Invalid parametars.";
  }else
  {
    for (int i = 1; i <= h; i++)
    {
      for (int j = 1; j < i; j++) cout << " ";
      for (int j = h+1-i; j > 1; j--) cout << char('a' + j-1);
      for (int j = 1; j <= h+1-i; j++) cout << char('a' + j-1);
      cout << endl;
    }
  }
  */

  /*
  int h, w;
  cout << "Enter num of rows: ";
  cin >> h;
  cout << "Enter num of last row asterisks: ";
  cin >> w;
  if (h < 3 || h > 20 || w < 3 || w > 60)
  {
    cout << "Incorrect values";
  }else
  {
    for (int i = 1; i <= w; i++) cout <<"*";
    cout << endl;
    for (int j = 2; j <= h-1; j++)
    {
      for (int i = 1; i <= j-1; i++) cout << " ";
      cout << "*";
      for (int i = 1; i <= w-2; i++) cout << " ";
      cout << "*" << endl;
    }
    for (int i = 1; i <= h-1; i++) cout << " ";
    for (int i = 1; i <= w; i++) cout << "*";
    cout << endl;
  }
  */
  
  /*
  int h, w;
  cout << "Enter num of rows: ";
  cin >> h;
  cout << "Enter num of last row asterisks: ";
  cin >> w;
  if (h < 3 || h > 20 || w < 2*h+3 || w > 70)
  {
    cout << "Invalid parametars";
  }else
  {
    for (int i = 1; i <= h-1; i++) cout << " ";
    for (int i = 1; i < w-2*h+2; i++) cout << "*";
    cout << endl;
    for (int j = 2; j <= h-1; j++)
    {
      for (int i = 1; i <= h-j; i++) cout << " ";
      cout << "*";
      for (int i = 1; i <= w-2*h-2+2*j; i++) cout << " "; //Mnozimo ovde s' j jer nam se broj " " povecava kao i petlja.
      cout << "*" << endl;
    }
    for (int i = 1; i <= w; i++) cout << "*";
    cout << endl;
  }
  */
  
  /*

  int h, w;
  cout << "Enter num of rows: ";
  cin >> h;
  cout << "Enter num of last row asterisks: ";
  cin >> w;
  if (h < 3 || h > 20 || w < 2*h+3 || w > 70)
  {
    cout << "Invalid parametars";
  }else
  {
    for (int i = 1; i <= h; i++)
    {
      for (int j = 1; j <= h-i; j++) cout << " ";
      for (int j = 1; j <= w-2*h+2*i; j++) cout << "*";
      cout << endl;
    }
  }
  
  
  /*
  int h, w;
  cout << "Enter num of rows: ";
  cin >> h;
  cout << "Enter num of asterisks in the last row: ";
  cin >> w;
  if (h < 3 || h > 20 || w < 3 || w > 60)
  {
    cout << "Invalid parametars";
  }else
  {
    for (int i = 1; i <= w; i++) cout << "*";
    cout << endl;
    for (int j = 2; j <= h-1; j++)
    {
      for (int i = 1; i <= j-1; i++) cout << " ";
      cout << "*";
      for (int i = 1; i <= w-2; i++) cout << " ";
      cout << "*" << endl;
    }
    for (int i = 1; i <= h-1; i++) cout << " ";
    for (int i = 1; i <= w; i++) cout << "*";
    cout << endl;
  }
  */
  
  
  /*
  int h, w;
  cout << "Enter num of rows: ";
  cin >> h;
  cout << "Enter num of asterisks in the last row: ";
  cin >> w;
  if (h < 3 || h > 20 || 2*h+3 > w || w > 70)
  {
    cout << "Invalid parameters";
  }else
  {
    for (int i = 1; i <= h-1; i++) cout << " ";
    for (int i = 1; i <= w-2*h+2; i++) cout << "*";
    cout << endl;
    for (int j = 2; j <= h-1; j++)
    {
      for (int i = 1; i <= h-j; i++) cout << " ";
      cout << "*";
      for (int i = 1; i <=  w-2*h-2+2*j; i++) cout << " ";
      cout << "*" << endl;
    }
    for (int i = 1; i <= w; i++) cout <<"*";
    cout << endl;
  }
  */
  
  /*
  int h, w;
  cout << "Enter num of rows: ";
  cin >> h;
  cout << "Enter num of asterisks in the last row: ";
  cin >> w;
  
  if (h < 3 || h > 20 || w < 2*h+3 || w > 70)
  {
    cout << "Invalid parametars.";
  }else
  {
    for (int i = 1; i < h; i++)
    {
      for (int j = 1; j < h-i; j++) cout << " ";
      for (int j = 1; j < w-2*h+2*i; j++) cout << "*";
      cout << endl;
    }
  }
  */
  
  return 0;
}