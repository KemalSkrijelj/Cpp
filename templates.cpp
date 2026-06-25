#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/*
template <typename SomeType>
SomeType myMax(SomeType a, SomeType b){
  return (a > b) ? a : b;
}
*/


/*
template <typename A, typename S>

A lowestNumber(A arr[], S size){
  A smallest = arr[0];
  for (int i = 0; i < size; i++)
  {
    if(arr[i] < smallest) smallest = arr[i];
  }
  return smallest;
}

template <typename anyType, typename C>

anyType getSameNum(anyType newArr[], C size, anyType enteredNum){
  for (int i = 0; i < size; i++)
  {
    if(newArr[i] == enteredNum) {
      return i+1;
    }
  }
  return -1;
}
*/

template <typename forArr, typename forSize>

forArr& highestNum(forArr arr[], forSize size){
  forArr &highest = arr[0];
  for (forSize i = 0; i < size; i++)
  {
    if(arr[i] > highest) highest = arr[i];
  }
  return highest;
}

template <typename forArr, typename forSize> // moramo pisati opet ovo jer svaki template vazi za tu neku funkciju
forSize howTimes(forArr arr[], forSize size, forArr entered){
  forSize counter = 0;
  for (forSize i = 0; i < size; i++)
  {
    if(arr[i] == entered) counter++;
  }
  return counter;
}


template <typename T1, typename T2>
class OrderedPair{
  T1 x;
  T2 y;
  public:
  OrderedPair(T1 x, T2 y){ this->x = x; this->y = y;}
  T1 getX() { return x; }
  T2 getY() { return y; }
  void setX(T1 valueX) { x = valueX; }
  void setY(T2 valueY) { y = valueY; }
  void Display() const {
    cout << "("<< x << ", " << y << ")" << ", ";
  }
};

int main(){
  OrderedPair<int, double> pair(3,4.3);
  pair.getX();
  pair.Display();
  /*
  int size;
  cin >> size;
  double enteredNum;
  cin >> enteredNum;
  double arr[size];
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  
  cout << "Highest: " << highestNum(arr, size);
  cout << "Times repeted entered num " << enteredNum << " is " << howTimes(arr, size, enteredNum);
  */


  /*
  int size;
  cin >> size;
  double arr[size];
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  
  cout << "Same num with: "<< getSameNum(arr, size, 3.4)  << endl;
  cout << "Lowest num in arr: "<<lowestNumber(arr, size);
  */


  /*
  cout << myMax(1,2) << endl;
  cout << myMax(0.8,0.2) << endl;
  cout << myMax('a','z') << endl;
  */
  return 0;
}