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

void minMaxEl(double arr[], int size, int &min, int &max){
  min = 9, max = 0;
  for (int i = 0; i < size; i++)
  {
    if(arr[i] < min) min = arr[i];
    if(arr[i] > max) max = arr[i];
  }

}
bool isMonotonically(double arr[], int size){
  for (int i = 0; i < size-1; i++)
  {
    if(arr[i] > arr[i+1]) return false;
  }
  return true;
}

int main(){
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