#include <iostream>
#include <string>
#include <cctype>
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
/*
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
*/
int longestWordLength(string s){
  int currentLength= 0, maxLength = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if(s.at(i) != ' '){
      currentLength++;
    }else
    {
      if(currentLength > maxLength){
        maxLength = currentLength;
      }
    }
  }
  if(currentLength > maxLength) maxLength = currentLength;
  return maxLength;
}

bool isPalindromic(string s){
  string s1 = "";
  for (int i = 0; i < s.length(); i++)
  {
    if(isalpha(s[i])) s1 += s[i];
  }
  for (int i = 0; i < s.length() / 2; i++)
  {
    if(s1[i] != s1[s.length()-1-i]) return false;
  }
  return true;
}
string toUpperFirstLetter(string s){
  string result;
  bool newWord = true;
  
  for (int i = 0; i < s.length(); i++)
  {
    char c = s[i];

    if(isspace(c)){
      newWord = true;
      result += c;
    }else{
      if(newWord){
        result +='(';
        result += toupper(c);
        result +=')';
        newWord = false;
      }else{
        result += c;
      }
    }
  }
  
  return result;
}
int main(){
  string s;
  getline(cin, s);
  string newString = toUpperFirstLetter(s);
  cout << "Old sentence is " <<  s << endl;
  cout << "New sentence is " <<  newString;
  /*
  string sentence;
  cout << "Enter the sentence: ";
  getline(cin, sentence);
  
  if(isPalindromic){
    cout << "Sentence is palindroic";
  }else{
    cout << "Sentence isn't palindroic";
  }
  */

  /*
  string s;
  cout << "Enter the string: ";
  getline(cin, s);
  cout << "Max word length is " << longestWordLength(s);
  */

  /*
  string s;
  getline(cin, s);
  if(isPalindromic){
    cout << "Sentence is palindromic";
  }else{
    cout << "Sentence isn't palindromic";
  }
  */

  /*
  string s = "aaa bbbbb cc";
  cout << "Lenght of longest word: " << longestWordLength(s);
  */
return 0;
}

