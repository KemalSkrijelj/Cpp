#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
/*
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
  */
 ////////////////////////////
/*
int func(int arr[], int sizeOfArr){
  int maxAdj = arr[0] - arr[1];
  for (int i = 1; i < sizeOfArr-1; i++)
  {
    int diff = arr[i] - arr[i + 1];
    if (diff > maxAdj){
      maxAdj = diff; 
    }
  }
  return maxAdj;
}
*/

/*
bool isMonotonically(int arr[], int sizeOfArr){
  for (int i = 0; i < sizeOfArr-1; i++)
  {
    if (arr[i] > arr[i+1])
    {
      return false;
      break;
    }
  }
  return true;
}
  Prime num su brojevi koji su deljivi samo sa 1 i sami sobom. Prvi prime num je 2
*/

/*
bool isPrime(int n){
  for (int i = 2; i < n; i++)
  {
    if (n % i == 0) return false;
  }
  return true;
}
*/
/*
void func(double arr[], int n, int &NoOfLocMax, int &NoOfLocMin){
  NoOfLocMax = 0, NoOfLocMin = 0;
  for (int i = 1; i < n-1; i++)
  {
    if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) NoOfLocMax++;
    if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) NoOfLocMin++;
  } 
}
*/
int main() {
  srand(time());
  int number =rand() % 10;
  int guess;
  int isEven = number % 2 == 0;
  cout << "Unesi 0 (paran) ili 1(neparan): ";
  cin >> guess;
  if (guess != 0 && guess != 1)
  {
    cout << "Los je unos \n";
    return 0;
  }
  
  if ((number % 2 == 0 && guess == 0) || (number % 2 != 0 && guess == 1)) {
    cout << "Pogodak!" << endl;
  }   else {
    cout << "Promasaj!" << endl;
  }
  cout <<"Dobijeni broj: "<< number;
  /*
  int max, min;
  double array[10];
   cout << "Enter 10 real numbers in arr: \n";
   for (int i = 0; i < 10; i++)
   {
     cin >> array[i];
    }
    func(array, 10, max,min);
    cout << "Maximum: " << max << ", minimum: " << min;
  */

  /*
  int n;
  cout << "Enter a num: ";
  cin >> n;
  if (isPrime(n))
  {
    cout << "Num is prime";
  }else  
  {
    cout << "Num is not prime";
  }  
  */ 
  
 /*
  
  int n;
  cout << "Enter the size of arr: ";
  cin >> n;
  int array[n];
  for (int i = 0; i < n; i++)
  {
    cin >> array[i];
  }
  
  if (isMonotonically(array, n))
  {
    cout << "Arr is monotonically increasing";
  }else
  {
    cout << "Arr isn't monotonically increasing";
  }
  */
  
  
  /* 1 exercises
  int n;
  cout << "Enter the size of arr: ";
  cin >> n;

  int array[n];
  for (int i = 0; i < n; i++)
  {
    cin >> array[i];
  }
  cout << "Max adj is: "<< func(array, n);
  //////////////////////////////////////
   
  /*
  int h, w;
  cout << "Enter the num of the rows: ";
  cin >> h;
  cout << "Enter the number of asterisks in last row: ";
  cin >> w;
  if (h < 3 || h > 20 || w < 2*h+3 || w > 70)
  {
    cout << "Invalid parametars";
  }else
  {
    for (int i = 1; i <= h-1; i++) cout << " ";  //first line
    for (int i = 1; i < w-2*h+2; i++) cout << "*"; // num of aterisks in first line
    cout << endl; 

    for (int j = 2; j <= h-1; j++) //loop for line from 2 to h-1
    {
      for (int i = 1; i <= h-j; i++) cout << " "; //loop for space to first asterisk
      cout << "*"; //left asterisk
      for (int i = 1; i <= w-2*h+2*j; i++) cout << " "; //loop for space beetween aterisks
      cout << "*" << endl; // right asterisk
    }
    
    for (int i = 1; i <= w; i++) cout << "*"; // loop for last asterisks line
    cout << endl;
  }
  */
  
  
  /*

  int h, w;
  cout << "Enter the total num of rows: ";
  cin >> h;
  cout << "Enter the num of asteriks in the last row: ";
  cin >> w;
  if (h < 3 || h > 20 || 2*h+3 > w || w > 70)
  {
    cout << "Invalid parametars";
  }else
  {
    for (int i=1; i <= h; i++) // 5
    {
      for (int j = 1; j <= h-i; j++) cout << " ";  // 5-1=4
      for (int j = 1; j <= w-2*h+2*i; j++) cout << "*"; // 15-10+2=7
      cout << endl;
    }
  }
  
  
  /*
  int n;
  cout << "Enter the num of digits in arr: ";
  cin >> n;
  int firstArr[n];
  for (int i = 0; i < n-1; i++)
  {
    cout << "Enter the digits on [" << i << "] position in the arr: ";
    cin >> firstArr[i];
  }
  for (int i = 0; i < n-1; i++)
  {
    cout << firstArr[i]<< ", " ;
  }
  */
   
  /*
  int num;
  cout << "Enter num: ";
  cin >> num;
  int minNum, maxNum;
  MinMaxDigit(num, maxNum, minNum);
  cout << "Max num is: " << maxNum << endl;
  cout << "Min num is: " << minNum << endl;
  */

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