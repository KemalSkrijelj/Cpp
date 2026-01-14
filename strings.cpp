#include <iostream>
#include <string>

using namespace std;

/*
int longestWordLength(string s){
  int currentLength = 0, max = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (s.at(i) != ' ')
    {
      currentLength++;
    }else{
      if(currentLength > max){
        max = currentLength;
      }
      currentLength = 0;
    }
  }
  if(currentLength > max){
    max = currentLength;
  }
  return max;
}
*/

bool isPalindromic(string s){
  string s1 = "";
  for (int i = 0; i < s.length(); i++){
    if(isalpha(s[i])) s1 += toupper(s[i]);
  }
  for (int i = 0; i < s.length() / 2; i++){
    if(s1[i] != s1[s.length() - 1 - i]) return false;
  }
  return true;  
}

int main(){
  string s;
  getline(cin, s);
  if(isPalindromic){
    cout << "Sentence is palindromic";
  }else{
    cout << "Sentence isn't palindromic";
  }
  /*
  string s = "aaa bbbbb cc";
  cout << "Lenght of longest word: " << longestWordLength(s);
  */
return 0;
}

