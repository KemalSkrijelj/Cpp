#include <iostream>

using namespace std;

int sumOfMat(int n, int m, int mat[][10]){
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(i > j){
        sum += mat[i][j];
      }
    }
  }
  return sum;
}
void outputMat(int n, int mat[][10]){
   for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}
void sortMatRows(int n, int m, int mat[][10]){
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m-1; j++)
    {
      for (int k = j+1; k < m; k++)
      {
        if(mat[i][j] > mat[i][k]){
          int temp = mat[i][j];
          mat[i][j] = mat[i][k];
          mat[i][k] = temp;
        }
      }
    }
  }
}
void inputMat(int n,int mat[][10]){
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> mat[i][j];
    }
  }
}
void sortColums(int n, int mat[][10]){
  for (int j = 0; j < n; j++)
  {
    for (int i = 0; i < n-1; i++)
    {
      for (int k = i+1; k < n; k++)
      {
        if(mat[i][j] > mat[k][j]){
          int temp = mat[i][j];
          mat[i][j] = mat[k][j];
          mat[k][j] = temp;
        }
      }
    }
  }
}
int main(){
  int n, sumElEachColum;
  cin >> n;
  int mat[10][10];
  
  if(n < 1 || n > 10){
    cout << "Invalid input!";
  }else{
    inputMat(n, mat); 
    int bigestEl = mat[0][1];
    outputMat(n, mat);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if(j > i){
          if(mat[i][j] > bigestEl){
            bigestEl = mat[i][j];
          }
        }
      }
    }
    for (int j = 0; j < n; j++)
    {
      sumElEachColum = 0;
      for (int i = 0; i < n; i++)
      {
        sumElEachColum += mat[i][j];
      }
      cout << "Sum of column " << j+1 << " = " << sumElEachColum << endl;
    }
    
    cout << "Biggest el is" << bigestEl << endl;
    sortColums(n, mat);
    outputMat(n, mat);
  }

  /*
  int n, m;
  cin >> n >> m;
  int mat[10][10];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mat[i][j];
    }
  }
  
  outputMat( n, m,mat);
  cout << endl;
  sortMatRows(n,m, mat);
  outputMat( n, m,mat);
  sortMatColums(n, m, mat);
  cout << endl;
  outputMat( n, m,mat);
  
  cout << "Sum elements below the main diagonal is " << sumOfMat(n,m,mat);
  */
  return 0;
}