#include <iostream>

using namespace std;

void rotateArrToRight(int array[], int n){
  int lastDigit = array[n-1];
  for (int i = n-1; i > 0; i++)
  {
    array[i] = array[i-1];
  }
  array[0] = lastDigit;   
}

void rotateArrToLeft(int array[], int n){
  int firstDigit = array[0];
  for (int i = 0; i < n-1; i++)
  {
    array[i] = array[i+1];
  }
  array[n-1] = firstDigit;
}
void numOfAboveEl(double arr[], int n, int &belowTheAvg, int &aboveTheAvg){
  belowTheAvg = 0, aboveTheAvg = 0;
  double sumOfEl = 0;
  double avg = 0;
  for (int i = 0; i < n; i++)
  {
    sumOfEl += arr[i];
  }
  avg = sumOfEl / n;
  for (int i = 0; i < n; i++)
  {
    if(arr[i] > avg) aboveTheAvg++;
    if(arr[i] < avg) belowTheAvg++;
  }
}
int main(){
  double array[10];
  int below, above;
  for (int i = 0; i < 10; i++)
  {
    cin >> array[i];
  }
  numOfAboveEl(array,10,below,above);
  cout << "El above: " << above << ", el below: " << below;
  
  /*
  int arr[10];
  cout << "Enter el: ";
  for (int i = 0; i < 10; i++)
  {
    cin >> arr[i];
  }
  
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " ";
  }
  
  rotateArrToLeft(arr, 10);
  cout << "\nRotate arr: \n";
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " ";
  }
  */


  /*
  int array[10];
  
  cout << "Enter el: ";
  for (int i = 0; i < 10; i++)  
  {
    cin >> array[i];
  }
  
  for (int i = 0; i < 10; i++)
  {
    cout << array[i] << " ";
  }
  rotateArrToRight(array, 10);
  cout << "\nRotated arr: \n";
  for (int i = 0; i < 10; i++)
  {
    cout << array[i] << " ";
  }
  
  */
  
  return 0;
}