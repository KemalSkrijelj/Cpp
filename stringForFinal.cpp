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

int coutWords(string s){
  int counter = 0;
  bool inWord = false;

  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] != ' ' && !inWord){
      counter++;
      inWord = true;
    }else{
      if(s[i] == ' '){
        inWord = false;
      }
    }
  }
  return counter;
}

string newString(string s){
  string newStr = "";
  bool inWord = false;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] != ' '){
      newStr += s[i];
      inWord = true;
    }else{
      if(inWord){
        newStr += ' ';
        inWord = false;
      }
    }
  }
  return newStr;
}
int main(){
  string s;
  getline(cin, s);
  string updatedString = newString(s);
  cout << updatedString;

  /*
  string s;
  getline(cin, s);
  int result = coutWords(s);
  
  cout << "Num of words in sentence is " << result;
  */

  /*
  string s;
  getline(cin, s);
  if(isPalindromic(s)){
    cout << "Sentence is palindromic!";
  }else{
    cout << "Sentence isn't palindromic!";
  }
  */

  /*
  string s;
  getline(cin, s);
  int result = lengthOfWord(s);
  cout << "Longest word in sentence is " << result;
  */
  return 0;
}