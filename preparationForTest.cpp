#include <iostream>
#include <string>

using namespace std;

bool isPrime(int num){
  if(num < 2) return false;
  for (int i = 2; i < num; i++)
  {
    if(num % i == 0) return false;
  }
  return true;
}
// bool isMonotonically(double arr[], int size){
//   for (int i = 0; i < size-1; i++)
//   {
//     if(arr[i] > arr[i+1]) return false;
//   }
//   return true;
// }
int longestWord(string s){
  int currentLength = 0, maxLength = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if(s.at(i) != ' '){
      currentLength++;
    }else
    {
      if(currentLength > maxLength){
        maxLength = currentLength;
      }
      currentLength = 0;
    }
  }
  if(currentLength > maxLength){
    maxLength = currentLength;
  }
  return maxLength;
}
double sumOfReciprocals(int n){
  double sum = 1.0;
  for (int i = 2; i <= n; i++)
  {
    sum += 1.0 / i;
  }
    return sum;
}

int smallestDigit(int n){
  n = abs(n);
  int small = 9;
  while (n > 0){
    int digit = n % 10;
    if(digit < small){
      small = digit;
    }
    n = n / 10; 
  }
  return small;
}

void minMaxEl(double arr[], int size, double &minEl, double &maxEl){
  minEl = arr[0], maxEl = arr[0];
  for (int i = 1; i < size; i++)
  {
    if(arr[i] < minEl) minEl = arr[i];
    if(arr[i] > maxEl) maxEl = arr[i];
  }
}

bool isMonotonically(double arr[], int sizeOfArr){
  for (int i = 0; i < sizeOfArr-1; i++)
  {
    if(arr[i+1] < arr[i]) return false;
  }
  
  return true;
}

int numOfWords(string s){
  int counter = 0;
  bool inWord = false;
  for (int i = 0; i < s.length(); i++){
    if(s.at(i) != ' '){
      if(!inWord){
        counter++;
        inWord = true;
      }
    }else{
      inWord = false;
    }
  }
  return counter;
}
int main(){
  string sentence;
  cout << "Enter text: " << endl;
  getline(cin, sentence);
  cout << "Sum of text is " << numOfWords(sentence);

  /*
  double array[5];
  cout << "Enter ell of array: ";
  for (int i = 0; i < 5; i++)
  {
    cin >> array[i];
  }
  if(isMonotonically(array, 5)){
    cout << "Arr is monotonically";
  }else{
    cout << "Arr isn't monotonically";
  }
  */

  /*
  double min, max;
  double array[10];
  cout << "Enter ell in arr: ";
  for (int i = 0; i < 10; i++)
  {
    cin >> array[i];
  }
  minMaxEl(array, 10, min, max);
  cout << "Min el: " << min << ", max: " << max;
  */
  
  /*
  int n;
  cout << "Enter the num: ";
  cin >> n;
  cout << "Smallest digit is " << smallestDigit(n);
  */

  /*
  int n;
  cout << "Enter the num: ";
  cin >> n;
  cout << "Sum of reciprocals is: " << sumOfReciprocals(n);
  */
  
  /*
  double array[5];
  
  cout << "Enter ell of arr: ";
  for (int i = 0; i < 5; i++)
  {
    cin >> array[i];
  }
  if(isMonotonically(array, 5)){
    cout << "Arr is monotonically";
  }else {
    cout << "Arr isn't monotonically";
  }
  */
  
  /*
  int n, minEl, maxEl;
  cout << "Enter size of arr: ";
  cin >> n;
  double array[100];
  cout << "Enter ell in arr: ";
  for (int i = 0; i < n; i++)
  {
    cin >> array[i];
  }
  minMaxEl(array, n, minEl, maxEl);
  cout << "Min el: " << minEl << ", max el: " << maxEl;
  */

  /*
  string s = " aaa bbbbb cc";
  cout << "Length of longest word is: " << longestWord(s);
  */
  
  /*
  double arr[100];
  int n;
  cout << "Enter the size: ";
  cin >> n;
  cout << "Enter the elements in arr: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  if(isMonotonically(arr, n)){
    cout << "Arr is monotonically";
  }else{
    cout << "Arr isn't monotonically";
  }
  */

  /*
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    if(isPrime(i) && isPrime(i+2)){
      cout << "(" << i << "," << i+2 << ")";
    }
  }
  */
  return 0;
}