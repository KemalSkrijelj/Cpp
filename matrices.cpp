#include <iostream>

using namespace std;

int sumOfEl(double matric[5][5]){
  int sum = 0;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      sum += matric[i][j];
    }
  }
  return sum;
}

int main(){
  double mat[5][5];
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> mat[i][j];
    }
  }
  cout << "Display: " << endl;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Sum of el is " << sumOfEl(mat);
  
  for (int j = 0; j < 5; j++)
  {
    for (int i = 0; i < 4; i++)
    {
      for (int k = i+1; k < 5; k++)
      {
        if(mat[k][j] > mat[i][j]){
          int temp = mat[i][j];
          mat[i][j] = mat[k][j];
          mat[k][j] = temp;  
        }
      }
    }
  }
  
  /*
  double mat[5][5];
  
  cout << "Enter el in matrics: ";
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> mat[i][j];
    }
  }
  cout << "Matric: " << endl;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Sum of el in matrcis is " << sumOfEl(mat);
  */
  
  /*
  int n, m;
  int sumOfDiagonalEl = 0, sumSecondDiagonal = 0;
  cout << "Enter the num of rows and columns: ";
  cin >> n >> m;
  int matric[n][m];
  cout << "Enter the elements: ";
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> matric[i][j];
    }
  }
  cout << "Matric: " << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << matric[i][j] << " ";
    }
    cout << endl;
  }
  
  for (int i = 0; i < n; i++)
  {
    sumOfDiagonalEl += matric[i][i];
  }
  cout << "Sum: " << sumOfDiagonalEl << endl;
  
  for (int i = 0; i < n; i++)
  {
    sumSecondDiagonal += matric[i][n-1-i];
  }
  cout << "Sum of second diagonal: " << sumSecondDiagonal; 
  */
 return 0;
}