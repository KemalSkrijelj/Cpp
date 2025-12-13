#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
  int h;
  cout << "Enter a num of row: ";
  cin >> h;
  if (h < 1 || h > 20)
  {
    cout << "Invalid parameters";
  }else{
    for (int i = 1; i <= h; i++)
    {
      for (int j = 1; j <= h-i; j++) cout << " ";
      for (int j = 1; j < i; j++) cout << char('A' + j+1);
      for (int j = i; j >= 1; j--) cout << char('A' + j-1);
      cout << endl;
    }
  }
  
  

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