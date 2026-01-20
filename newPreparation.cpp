#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
  int a, b;
  cout << "Enter limits: ";
  cin >> a >> b;
  cout << "+--------+------------+"<< endl;
  cout << "| Number | Reciprocal |"<< endl;
  cout << "+--------+------------+"<< endl;
  for (int i = a; i <= b; i++)
  {
    cout << "| " << setw(6) << i << " | " << setw(10) <<  1. / i << " |" << endl;
  }
  cout << "+--------+------------+";
  

  /*
  int dur;
  cout << "Enter duration in seconds: "; cin >> dur;
  int days = dur / (24*60*60);
  dur = dur % (24*60*60);
  int h = dur / (60*60);
  dur = dur % (60*60);
  int m = dur / 60;
  int s = m % 60;
  cout << "This is " << days << " day(s), " << h << " hour(s), " << m << " minute(s) and " << s << " second(s)";
  */


  /*
  double angleMeasured;
  double degrees, minutes, seconds;
  cout << "Enter angle in radians: "; cin >> angleMeasured;
  double totalDegrees = angleMeasured * 180 / M_PI;
  
  degrees = (int) totalDegrees;
  double remaining = totalDegrees - degrees;
  
  double totalMinutes = remaining * 60;
  minutes = (int) totalMinutes;
  
  double remainingMinutes = totalMinutes - minutes;
  seconds = (int) remainingMinutes * 60;
  
  cout << degrees << " degrees, "
  << minutes << " minutes and "
  << seconds << " seconds";
  */


  /*
  int randomNum, sumOfDivisors= 0;
  cin >> randomNum;
  for (int i = 1; i < randomNum; i++)
  {
    if(randomNum % i == 0) sumOfDivisors  += i;
  }
  if(sumOfDivisors == randomNum) cout << randomNum << " is perfect num!";
  if(sumOfDivisors != randomNum) cout << randomNum << " isn't perfect num!";
  */

  /*
  int n, sum = 0, sign = 1;
  cout << "Enter n: ";
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    sum += sign*i;
    sign = -sign;
  }
  cout << "Sum: " << sum;
  */

  /*
  double n, min = 9, max = 0;
  for(int i =0;i<10;i++){
    cin >> n;
    if(n < min) min = n;
    if(n > max) max = n;
  }
  cout << "Biggest entered num is " << max << endl;
  cout << "Min entered num is " << min;
  */

  /*
  double num, sum = 0;
  int counter = 0;
  while (num != 0)
  {
    cin >> num;
    if(num != 0){
      sum += num;
      counter++;
    }
  }
  cout << "Artc mean of num is: " << sum / counter;
  */

  /*
  cout << "+--------+--------+--------+"<< endl;
  cout << "| Number | Square |  Cube  +"<<endl;
  cout << "+--------+--------+--------+"<<endl;
  for (int i = 1; i <= 10; i++) {
    cout<<"| "<< setw(6)<< i <<" |" << setw(7) <<i*i<<" |" << setw(7)<< i*i*i<<" |" << endl;
  }
  cout << "+--------+--------+--------+";
  */
  
  return 0;
}