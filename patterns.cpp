#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
int h;
cout << "Enter height: ";
cin >> h;
if(h < 4 || h > 20 ){
  cout << "Invalid parametars!";
}else{
  int mid = h/2+1;

  for (int i = 1; i <= h/2; i++) cout << " ";
  cout << "*" << endl;

  for (int i = 2; i <= mid; i++)
  {
    for (int j = 1; j <= mid - i; j++) cout << " ";
    cout << "*";
    for (int j = 1; j <= 2*(i-1)-1; j++) cout << " ";
    cout << "*" << endl;
  }

  for (int i = mid-1; i >= 1; i--)
  {
    for (int j = 1; j <= mid-i; j++) cout << " ";
    cout << "*";
    if(i > 1){
      for (int j = 1; j <= 2*(i-1)-1; j++) cout << " ";
      cout << "*"<< endl;
    }
  }
  
}

/*
int h;
cout << "Enter height: ";
cin >> h;
if(h < 4 || h > 20 ){
  cout << "Invalid parametars!";
}else{
  for (int i = 1; i <= (h*2)-1; i++) cout << "*";
  cout << endl;
  for (int i = 2; i <= h-1; i++)
  {
    for (int j = 1; j <= i-1; j++) cout << " ";
    for (int j = 1; j <= (h*2-1)-2*(i-1); j++) cout << "*";
    cout << endl;
  }
  for (int i = 1; i <= h-1; i++) cout << " ";
  cout << "*" << endl; 
}
*/


/*
int h;
cout << "Enter height: ";
cin >> h;
if(h < 4 || h > 20 ){
cout << "Invalid parametars!";
}else{
  
for (int i = 1; i <= (h-1)/2; i++) cout << " ";
cout << "*" << endl;

for (int i = 2; i <= (h+1)/2; i++)
{
  for (int j = 1; j <= (h+1)/2 - i; j++) cout << " ";
  cout << "*";
  for (int j = 1; j <= 2*i-3; j++) cout << " ";
  cout << "*" << endl;
}

for (int i = (h-1)/2; i >= 2; i--)
{
  for (int j = 1; j <= (h+1)/2 - i; j++) cout << " ";
  cout << "*";
  for (int j = 1; j <= 2*i-3; j++) cout << " ";
  cout << "*" << endl;
}

for (int i = 1; i <= (h-1)/2; i++) cout << " ";
cout << "*";
}
*/


/*
int h;
cout << "Enter height: ";
cin >> h;
if(h < 4 || h > 20 ){
  cout << "Invalid parametars!";
}else{
  int mid = h/2;

  for (int i = 1; i < h; i++){
    for (int j = 1; j < h-i; j++) cout << " ";
    cout << "*";

    if(i != 1){
      for (int j = 1; j < 2*i-2; j++) cout << " ";
      cout << "*";
    }
    cout << endl;
  }
  
  for (int i = h-2; i >= 1; i--)
  {
    for (int j = 1; j < h-i; j++) cout << " ";
    cout << "*";
    if(i != 1){
      for (int j = 1; j < 2*i-2; j++) cout << " ";
      cout << "*";
    }
    cout << endl;
  }
}
*/

/*
  int h;
  cout << "Enter height: ";
  cin >> h;
  if(h < 3 || h > 20 ){
    cout << "Invalid parametars!";
  }else {
    for (int i = 1; i <= h*2-1; i++) cout << "#";
    cout << endl;
    
    for (int i = 2; i <= h-1; i++)
    {
      for (int j = 1; j < i; j++) cout << " ";
      cout << "#";
      
      for (int j = 1; j <= h-i-1; j++) cout << " ";
      for (int j = 0; j <= h-i; j++) cout << "#"; 
      cout << endl;
    }
    for (int i = 1; i <= h-1; i++) cout << " ";
    cout << "#";
  }
*/

/*
int h;
cout << "Enter height: ";
cin >> h;
if(h < 3 || h > 20 ){
  cout << "Invalid parametars!";
}else {
  for (int i = 1; i <= h-1; i++) cout << " ";
  cout << "#" << endl;
  
  for (int i = 2; i <= h-1; i++)
  {
    for (int j = 1; j <= h-i; j++) cout << " ";
    cout << "#";
    for (int j = 2; j < i; j++) cout << " ";
    cout << "#";
    
    //Second half of triangle
    for (int j = 0; j < i-1; j++) cout << "#";
    cout << endl;
  }
  for (int i = 0; i < h*2-1; i++) cout << "#";
  cout << endl;
}
*/


/*
int h;
cout << "Enter height: ";
cin >> h;
if(h < 3 || h > 20 ){
  cout << "Invalid parametars!";
}else{

  for (int i = 1; i <= h-1; i++) cout << " ";
  cout << "#";
  cout << endl;

  for (int i = 2; i < h-1; i++)
  {
   for (int j = 1; j <= h-i; j++) cout << " ";
   cout << "#";
   for (int j = 2; j < i; j++) cout << " ";
   cout << "#" << endl;
  }
  for (int i = 1; i <= h; i++) cout << "#";
}
*/

/*
int h, w;
cout << "Enter height and widht: ";
cin >> h >> w;
if(h < 3 || h > 20 || w < h || w > 79){
  cout << "Invalid parametars!";
}else{                                                        ###############
  for (int i = 1; i <= w; i++) cout << "#";                    #            #
  cout << endl;                                                 #           #
  //                                                             #          #
  for (int i = 2; i < h-1; i++)                                   #         #
  {                                                                #        #
    for (int j = 1; j <= i; j++) cout << " ";                       #       #
    cout << "#";                                                     #      #
    for (int j = 1; j <= w-2-i; j++) cout << " ";                     #     #
    cout << "#"<< endl;                                                ######
  }

  for(int i = 1; i <= h-1; i++) cout << " ";
  for (int i = 1; i < w-h+2; i++) cout << "#";
  cout << endl;
}
*/


/*
int h, w;
char c;
cout << "Enter character: ";
cin >> c;
cout << "Enter height and widht: ";
cin >> h >> w;
if(h < 3 || h > 20 || w < 2*h+3 || w > 70){
  cout << "Invalid parametars!";
}else{
  for(int i = 1;i <= h-1; i++) cout << " ";
  for(int i = 1;i <= w-2*(h-1);i++) cout << c;
  cout << endl;
  
  for(int i = 2; i <= h-1; i++){
    for(int j = 1; j <= h-i;j++) cout << " ";
    cout << c;
    for(int j = 1; j <= w-2*h+2*i-2;j++) cout << " ";
    cout << c << endl;
  }
  
  for(int i=1;i <=w;i++) cout << c;
  cout << endl;
}
*/


/*
int h, w;
cout << "Enter height and widht: ";
cin >> h >> w;
if(h < 3 || h > 20 || w < 3 || w > 60){
    cout << "Invalid parametars!";
}else{
  for(int i = 1; i <= w; i++) cout << "*";
  cout << endl;
  for(int i = 2; i < h-1; i++){
      for(int j = 1; j < i; j++) cout << " ";
      cout << "*";
      for(int j = 1; j <= w-2;j++) cout << " ";
      cout << "*";
      cout << endl;
    }
    for(int i = 1; i < h-1; i++) cout << " ";
    for(int i = 1; i <= w; i++) cout << "*";
}
*/


/*
int h, w;
cout << "Enter height and widht: ";
cin >> h >> w;
if(h < 3 || h > 20 || w < 2*h+3 || w > 70){
    cout << "Invalid parametars!";
}else{
  for(int i = 1;i <= h-1; i++) cout << " ";
  for(int i = 1;i <= w-2*(h-1);i++) cout << "*";
  cout << endl;
  
  for(int i = 2; i <= h-1; i++){
      for(int j = 1; j <= h-i;j++) cout << " ";
      cout << "*";
      for(int j = 1; j <= w-2*h+2*i-2;j++) cout << " ";
      cout << "*" << endl;
    }

    for(int i=1;i <=w;i++)cout << "*";
    cout << endl;
  }
*/


/*
  int h, w;
  cout << "Enter height and widht: ";
  cin >> h >> w;
  if(h < 3 || h > 20 || w < 2*h+3 || w > 70){
    cout << "Invalid parametars!";
  }else{
    for(int i = 1; i <= h-1; i++){
        for(int j = 1; j <= h-i; j++) cout << " ";
        for(int j = 1; j <= w-2*h+2*i; j++) cout << "*";
        cout << endl;
    }
    for(int i = 0; i < w; i++) cout << "*";
}
*/
return 0;
}
