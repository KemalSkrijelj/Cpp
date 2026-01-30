#include <iostream>
#include <cmath>
#include <string>
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

bool isPerfect(int x){
  int sumOfDiv = 0;
  for (int i = 1; i < x; i++)
  {
    if(x % i == 0) sumOfDiv += i;
  }
  
  if(sumOfDiv == x){
    return true;
  }else{
    return false;
  }
}

void minMaxDigit(int x, int &minDigit, int &maxDigit){
  minDigit = 9, maxDigit = 0;

  while(x != 0){
  int digit = x % 10;
    if(digit > maxDigit) maxDigit = digit;
    if(digit < minDigit) minDigit = digit;
    x /= 10;
  }
}
bool isMonoIncreasing(int arr[], int size){
  for (int i = 1; i < size; i++)
  {
    if(arr[i] < arr[i-1]) return false;
  }
  return true;
}
int longestWordLength(string s){
  int currentLength = 0, maxLength = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if(s.at(i) != ' '){
      currentLength++;
    }else{
      if(currentLength > maxLength){
        maxLength = currentLength;
      }
      currentLength = 0;
    } 
  }
  if(currentLength > maxLength) maxLength = currentLength;
  return maxLength;
}
int sumOfDigits(int x){
  int sum = 0;
  while (x != 0)
  {
    int digit = x % 10;
    sum += digit;
    x /= 10;
  }
  return sum;
}

double valueOfSum(int n, double x){
  double sum = 0, sign = 1;
  for (int i = 0; i <= n; i++)
  {
    double product = x;
    for (int j = 1; j <= i; j++) product *= (x+j);
    sum += sign / product;
    sign = -sign; 
  }
  return sum; 
} 
void minMaxLocal(double arr[], int n, int &NoOfLocMax, int &NoOfLocMin){
  NoOfLocMax = 0, NoOfLocMin = 0;
  for (int i = 1; i < n-1; i++)
  {
    if(arr[i] > arr[i+1] && arr[i] > arr[i-1]) NoOfLocMax++;
    if(arr[i] < arr[i+1] && arr[i] < arr[i-1]) NoOfLocMin++;
  }
  
}
double maxDifference(double arr[], int n){
  double maxDiff = 0;
  for (int i = 1; i < n; i++)
  {
    if(arr[i] - arr[i-1] > maxDiff) maxDiff = arr[i] - arr[i-1];
  }
  return maxDiff;
}

bool isPalindromic(string s){
  string s1 = "";
  for (int i = 0; i < s.length(); i++)
  {
    if(isalpha(s[i])) s1 += toupper(s[i]);
  }
  for (int i = 0; i < s.length()/2; i++)
  {
    if(s1[i] != s1[s.length() - 1 - i]) return false;
  }
  return true;
}

int main (){
  double mat[5][5];
  int numOfNonZero = 0;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> mat[i][j];
    }
  }

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (i > j)
      {
        if(mat[i][j] != 0) numOfNonZero++;
      }
    }
  }
  
  cout << "Number of non zero elements below main diagonal is " << numOfNonZero << endl;
  
  for (int j = 0; j < 5; j++)
  {
    for (int i = 0; i < 4; i++)
    {
      for (int k = i+1; k < 5; k++)
      {
        if(mat[k][j] > mat[i][j]){ // donji veci od gornjeg
          double temp = mat[i][j];
          mat[i][j] = mat[k][j];
          mat[k][j] = temp;
        }
      }
    }
  }
  
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  

  /*
  string sentence;
  getline(cin, sentence);
  if(isPalindromic){
    cout << "Sentence is palindromic";
  }else{
    cout << "Sentence isn't palindromic";
  }
  */
  
  /*
  double arr[10];
  for (int i = 0; i < 10; i++)
  {
    cin >> arr[i];
  }
  cout << "Max diff in arr is " << maxDifference(arr, 10);
  */
  
  /*
  double array[10];
  int localMin, localMax;
  for (int i = 0; i < 10; i++)
  {
    cin >> array[i];
  }
  minMaxLocal(array, 10, localMax, localMin);
  cout << "There are " << localMax << " local maximums and " << localMin << " local minimums in the array." << endl;
  */

  /*
  int n; 
  double x;
  cin >> n >> x;
  cout << "Sum is " << valueOfSum(n, x);
  */

  /*
  int n;
  cin >> n;
  cout << "Sum of digits of number " << n << " is " << sumOfDigits(n);
  */

  /*
  int h;
  cin >> h;
  if(h < 3 || h > 20){
    cout << "Invalid input";
  }else{
    for (int i = 0; i < h-1; i++) cout << " ";
    cout << "#" << endl;
    
    for (int i = 1; i < h-1; i++)
    {
      for (int j = 0; j < h-i-1; j++) cout << " ";
      cout << "#";
      for (int j = 0; j < i-1; j++) cout << " ";
      for (int j = 0; j < i+1; j++) cout << "#";
      cout << endl;
    }
    
    for (int i = 0; i < 2*h-1; i++) cout << "#";
  }
  */


  /*
  int a, b, sumOfDivA = 0, sumOfDivB = 0;
  cin >> a >> b;
  for (int i = 1; i < a; i++)
  {
    if(a % i == 0) sumOfDivA += i;
  }
  for (int i = 1; i < b; i++)
  {
    if(b % i == 0) sumOfDivB += i;
  }
  if(sumOfDivA == b && sumOfDivB == a){
    cout << "Amicable numbers";
  }else{
    cout << "Non-Amicable numbers";
  }
  */
  

  /*
  double n, sumOfProduct = 1;
  int counter = 0;
  while (n != 0)
  {
    cin >> n;
    if(n != 0){
      sumOfProduct *= n;
      counter++;
    }
  }
  cout << "Geometric mean is " << pow(sumOfProduct, 1. /counter);
  */
  

  /*
  string s;
  getline(cin, s);
  cout << "Length of the longest word: " << longestWordLength(s) << endl;
  */

  /*
  int arr[5];
  for (int i = 0; i < 5; i++)
  {
    cin >> arr[i];
  }
  if(isMonoIncreasing(arr,5)){
    cout << "Arr is monotonically increasing!";
  }else{
    cout << "Arr isn't monotonically increasing!";
  }
  */
  

  /*
  int n;
  cin >> n;
  
  for (int i = 2; i+2 < n; i++)
  {
    if(isPrime(i) && isPrime(i+2)){
      cout << "(" << i << ", " << i+2 << ")";
    }
  }
  */
  

  /*
  int n;
  cin >> n;
  for (int i = 2; i < n; i++)
  {
    if(isPrime(i) && n % i == 0){
      cout << i << " ";
    }
  }
  */

  /*
  int h, w;
  cout << "Enter the height: ";
  cin >> h;
  cout << "Enter the width: ";
  cin >> w;
  
  if(h < 3 || h > 20 || w < 2*h+3 || w > 70){
    cout << "Invalid input!!!";
  }else{

    for (int i = 0; i < h-1; i++) cout << " ";
    for (int i = 0; i < 2*h+2; i++) cout << "+";
    cout << endl;
    
    for (int i = 1; i < h-1; i++)
    {
      for (int j = 1; j < h-i; j++) cout << " ";
      cout << "+";    
      for (int j = 1; j <= 2*h+2*i; j++) cout << " ";
      cout << "+"<< endl;   
    }
    for (int i = 0; i < w; i++) cout << "+";
  }
  */

  /*
  int n, positive = 0, negative = 0; 
  for (int i = 0; i < 10; i++)            
  {                              
    cin >> n;
    if(n > 0) positive++;
    if(n < 0) negative++;
  }                            
  cout << "There are " << positive << " positive nums and " << negative << "negatives num."; 
  */

  /*
  int n, min, max;
  cin >> n;
  minMaxDigit(n, min, max);
  cout << "Num: " << n << ", minDigit " << min << ", maxDigit " << max;
  */

  /*
  for (int i = 1; i < 100; i++)
  {
    if(isPerfect(i)) cout << i << " ";
  }
  */

  /*
  int n;
  cin >> n;
  
  if(n < 4 || n > 20){
    cout << "Invalid input!!!";
  }else{
    int mid = n/2;
    
    for(int i = 0; i < mid; i++) cout << " ";
    cout << "*" << endl;
    
    for (int i = 1; i <= mid; i++){
      for (int j = 1; j <= mid-i; j++) cout << " ";
      cout << "*";
      if (i >= 1) {
        for (int j = 1; j <= 2*(i-1)+1; j++) cout << " ";
        cout << "*";
      }
      cout << endl;
    }
    
    for (int i = mid-1; i >= 1; i--) {
      for (int j = 1; j <= mid-i; j++) cout << " ";
      cout << "*";
      if (i >= 1) {
        for (int j = 1; j <= 2*(i-1)+1; j++) cout << " ";
        cout << "*";
      }
      cout << endl;
    }
    
    for (int i = 0; i < mid; i++) cout << " ";
    cout << "*" << endl;
  }
  */

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