#include <iostream>

using namespace std;

int numberOfElBiger(double arr[], int n){
  int countOfBiger = 0;
  double arrMean, sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  arrMean = sum / n;

  for (int i = 0; i < n; i++)
  {
    if(arr[i] > arrMean) countOfBiger++;
  }

  return countOfBiger;
}
string chosedWord(string s, int n){
  int wordCount = 0;
  string word = "";

  if(n < 1 || n > s.length()){
    return "";
  }else{
    for (int i = 0; i < s.length(); i++)
    {
      if(s[i] != ' '){
        if(i == 0 || s[i-1] == ' '){
          wordCount++;
        }
      }
      if(wordCount == n){
        word += s[i];
      }
    }
  }
  return word;
}
string newString(string s){
  bool newWord = true;

  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] != ' '){
      if(newWord && isalpha(s[i])){
        s[i] = toupper(s[i]);
      }
      newWord = false;
    }else{
      newWord = true;
    }
  }
  return s;
}
int sumElBelowTheMain(double mat[5][5]){
  int sum = 0;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if(i == j && i > j){
        sum += mat[i][j];
      }
    }
  }
  return sum;  
}
void sortedMat(double mat[5][5]){
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      for (int k = j+1; k < 5; k++)
      {
        if(mat[i][j] > mat[i][k]){
          double temp = mat[i][j];
          mat[i][j] = mat[i][k];
          mat[i][k] = temp;
        }
      }
    }
  }
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
  cout << endl;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << mat[i][j];
    }
    cout << endl;
  }
  sortedMat(mat);
  cout << endl;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << mat[i][j];
    }
    cout << endl;
  }
  /*
  string s;
  getline(cin, s);
  cout << newString(s) << endl;
  */

  /*
  string s;
  getline(cin, s);
  int n;
  cin >> n;
  string word = chosedWord(s, n);
  cout << word;
  */

  /*
  double array[10];
  for (int i = 0; i < 10; i++)
  {
    cin >> array[i];
  }
  int res = numberOfElBiger(array, 10);
  cout << "Number of biger then mean is " << res;
  */

  /*
  int n, orginal, reversed = 0;
  cin >> n;
  
  orginal = n;
  
  while (n > 0)
  {
    int digit = n % 10;
    reversed = reversed * 10 + digit;
    n /= 10;
  }
  
  
  if(orginal == reversed){
    cout << orginal << " is palindromic";
  }else{
    cout << orginal << " isn't palindromic";
  }
  */
  


  /*
  int h;
  cin >> h;
  
  if(h < 1 || h > 20){
    cout << "Invalid input!!";
  }else {
    for (int i = 0; i < h; i++) cout << " ";
    cout << 'A' << endl;
    
    for (int i = 1; i < h; i++)
    {
      for (int j = 0; j < h-i; j++) cout << " ";
      for (char c = 'A'; c < 'A'+i; c++) cout << c; 
      for (char c = 'A'+i; c >= 'A'; c--) cout << c;
      cout << endl; 
    }
  }
  */

  return 0;
}