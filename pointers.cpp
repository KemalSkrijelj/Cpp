#include <iostream>
#include <cmath>

using namespace std;

int subtraction(int *x, int *y){
  *x =  *y- *x;
  return *x;
}
void value(int a){ //not work this func
  a = 15; 
}
void reference(int *p){
  *p = 80;
}

int largestNum(int *p){
  int max = *p;

  for (int i = 1; i < 8; i++)
  {
    if(*(p+i) > max){
      max = *(p+i);
    }
  }
  return max;
}

void readConsonants(char *pointerOnArr, int size){
  cout << "Consonants are: " << endl;
  for (char *i = pointerOnArr; i < pointerOnArr + size; i++) // pointer i look at first char in arr
  {
    char c = *i; // char c will use  value of pointer i

    if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U'){
      cout << c << ", ";
    }
  }
}

int main(){
  int n;
  cin >> n;   

  char arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  readConsonants(arr, n);
  
  /*
  int arr[8] = {6,7,9,10,15,3,99, -21};
  
  int maxNum = largestNum(arr);
  cout << "Max num in arr is " << maxNum;
  */

  /*
  int n, evenNums = 0, oddNums = 0;
  cin >> n;
  int arr[100];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int *p = arr;
  
  for (int i = 0; i < n; i++)
  {
    if (*(p+i) % 2 == 0)
    {
      evenNums++;
    }else{
      oddNums++;
    }
  }
  
  cout << "Parni brojevi: " << evenNums << endl;
  cout << "Neparni brojevi: " << oddNums;
  */
  


  /*
  int x = 5;
  int y = 7;
  cout << "x:" << x << endl;
  cout << "y:" << y << endl;
  value(x); // not work this func because this func don't have access for this variable
  reference(&y);
  cout << "Substraction value: " << subtraction(&x, &y) << endl;
  cout << "New x:" << x << endl;
  cout << "New y:" << y << endl;
  */


  /*
  string name = "Kemal";
  int age = 20;
  string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
  int x = 3;
  
  string *pName = &name;
  int *pAge = &age;
  string *pfreePizzas = freePizzas;
  int *pointer = &x;
  
  cout << *pName << endl;
  cout << *pAge << endl;
  cout << *pfreePizzas << endl;
  cout << *pointer;
  */
  return 0;
}