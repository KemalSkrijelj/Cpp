#include <iostream>
#include <cmath>

using namespace std;

int numOfInv(double arr[], int n){
  int numOfInversion = 0;
  for (int i = 0; i < n-1; i++)
  {
    for (int j = i+1; j < n; j++)
    {
      if(arr[i] > arr[j]) numOfInversion++;
    }
  }
  return numOfInversion;
}
void sortArrAsceding(double arr[], int n){
  for (int i = 0; i < n-1; i++)
  {
    for (int j = 0; j < n-i-1; j++)
    {
      if(arr[j] > arr[j+1]){
        double temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  
}
int numOfDiffElements(double arr[], int n){
  int numOfDiff = 0;
  for (int i = 0; i < n; i++)
  {
    bool exist = false;
    for (int j = 0; j < i; j++)
    {
      if (arr[i] == arr[j]){
        exist = true;
        break;
      }
    }
    if(!exist) numOfDiff++;
  }
  
  return numOfDiff;
}
int main(){
  double arr[10];
  for (int i = 0; i < 10; i++)
  {
    cin >> arr[i];
  }
  int result = numOfDiffElements(arr, 10);
  cout << "Num of nums " << result;
  
  /*
  double arr[10];
  for (int i = 0; i < 10; i++)
  {
    cin >> arr[i];
  }
  sortArrAsceding(arr, 10);
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << ", ";
  }
  */

  /*
  double array[10];
  for (int i = 0; i < 10; i++)
  {
    cin >> array[i];
  }
  
  int result = numOfInv(array, 10);
  
  cout << "Num of inversion is " << result;
  */
  
  return 0;
}