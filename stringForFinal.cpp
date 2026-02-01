#include <iostream>

using namespace std;

int lengthOfWord(string s){
  int currentLength = 0, maxLength = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if(s.at(i) != ' '){
      currentLength++;

    }else{
      if(currentLength > maxLength) maxLength = currentLength;
      currentLength = 0;
    }

  }
  if(currentLength > maxLength) maxLength = currentLength;
  return maxLength;
}

bool isPalindromic(string s){
  string newString = "";
  for (int i = 0; i < s.length(); i++)
  {
    if(isalpha(s[i])) newString += toupper(s[i]);
  }
  for (int i = 0; i < newString.length(); i++)
  {
    if(newString[i] != newString[newString.length() - 1 - i]) return false;
  }
  return true;
}

int main(){
  string s;
  getline(cin, s);
  if(isPalindromic(s)){
    cout << "Sentence is palindromic!";
  }else{
    cout << "Sentence isn't palindromic!";
  }

  /*
  string s;
  getline(cin, s);
  int result = lengthOfWord(s);
  cout << "Longest word in sentence is " << result;
  */
  return 0;
}