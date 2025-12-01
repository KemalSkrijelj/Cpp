#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main(){
  int n = 0, sum = 0;
  int x;
  
  cout << "Enter the numbers (0 == break): ";
  while (true)
  {
    cin >> x;
    if (x == 0)
    {
      break;
    }
    sum += x;
    n++;
  }

  double mean = sum / n;
  cout << "Arithmetic mean is: "<< double(mean);
  /*

  int a,b;
  cin >> a;
  cin >> b;
  cout << "+---------+---------+---------+"<< endl;
  cout << "| Number  | Square  | Cube    |"<< endl;
  cout << "+---------+---------+---------+"<< endl;
  for (int i =a; i < b; i++)
  {
    cout<<"|"<< setw(9) << i << "|" <<setw(9) << i*i << "|" <<setw(9) << i*i*i << "|"<< endl;
  }
  cout << "+--------+--------+--------+" << endl;

  /*

  double number, sum = 1;
  int n = 0;

  cout << "Enter real numbers (0 for break): \n"  ;

  while (n != 0)
  {
    cin >> number;
    if(number == 0){
      cout<< "Loop stop because you enter 0."
      break;
    }
    sum *= number;
    n++;
  }
  if (n == 0)
  {
    cout << "You didn't enter any numbers."
  }else
  {
    double geomtric = pow(sum, 1.0/n);
    cout << "Geometric middle: " << geomtric;
  }
  
  /*

  int n;
  cout<< "Enter n: ";
  cin >> n;
  double sum = 0, p = 1;
  for (int i = 1; i < n; i++)
  {
    p *= -i;
    sum -= 1/p;
  }
  cout << "Sum: \n" << sum;
  
  /*

  int duration;
  cout << "Enter the duration in seconds: ";
  cin >> duration;
  int days = duration/(24*60*60);
  duration %= 24*60*60;
  int hours = duration /(60*60);
  duration %= 60*60;
  int minutes = duration / 60;
  duration %= 60;
  int seconds = duration % 60;
  cout<< "This is: "<< days<<" days, "<< hours <<" sati, "<<minutes<<" minuta, "<<seconds<<" sekundi";
  /*
  
  int s = 0, t = 100;
  for(int i = 150; i != 0; i /= 2) s += i; //s= 75
  int p = 2, q = 36;
  while(q >= p) {
    t += 5 * p − q; p *= 2; q−−;//110-36, p = 4
  }
  cout << s << " " << t;
  */
  
  /*
  int p = 6, q = 4;   //13-45= 32
  int r = 10 + 27 % 6 - 3 * (++p + 2 * q--);
  int s = 4 * (15 / (p + q) − 12. / q) + 7 * (p < q + r); //15.0
  char u = 'B', v = u + 4, w = char(tolower(v));//B F f
  cout << p << " " << q << " " << r << " " << s << endl;
  cout << u << " " << v << " " << w << endl;
  */

  /*
  int randomNum;
  cout<< "Unesi neki broj: ";
  cin >> randomNum;
  for (int i = 1; i < randomNum; i++)
  {
    if (i % 2 == 0)
    {
      cout<< i << " je paran\n"; 
    }
  }
  */
  
  /*
  cout<< "Unesi neki broj: ";
  int a;
  cin >> a;
  if (a %2 ==1)
  {
  cout << "Broj je neparan \n";
  }else if (a % 2 == 0)
  {
  cout<<"Broj je paran.";
  }
  */

  /*
  int prva, druga, treca;
  cout << "Unesite ocene iz predmeta: \n";
  cin >> prva >> druga >> treca;
  double prosek= (double)(prva+druga+treca) /3;
  cout<<setprecision(3)<< "Prosek je: "<< prosek;
  */

  /*
  int a,b;
  cout << "Unesi a: ";
  cin >> a;
  cout << "Unesi b: ";
  cin >> b;
  int Obim = 2*a+2*b;
  int P = a*b;
  double Dijagonala = sqrt(a*a+b*b);
  cout << "Obim: " << Obim<<endl;
  cout << "Povrsina: " << P<<endl;
  cout <<setprecision(3)<< "Dijagonala: " << Dijagonala<<endl;
  */

  /*
  string ime, prezime;
  int godine;
  cout << "Unesi ime:";
  cin >> ime;
  cout << "Unesi prezime:";
  cin >> prezime;
  cout << "Unesi godine: ";
  cin >> godine;
  cout << "Ime i prezime:" << ime << " "<< prezime << "\ngodine: " << godine;
  */

  /*
  int firstNum, secondNum;
  cout << "Unesite prvi broj: ";
  cin >> firstNum;
  cout << "Unesite drugi broj: ";
  cin >> secondNum;
  int zbir = firstNum + secondNum;
  int razlika = firstNum - secondNum;
  double kolicnik = firstNum % secondNum;
  int proizvod = firstNum * secondNum;
  int celobrojniKolicnik = firstNum / secondNum;
  cout << "Zbir= " << zbir << endl; 
  cout << "Razlika= " << Razlika << endl; 
  cout << "Kolicnik= " << kolicnik << endl; 
  cout << "Proizvod= " << proizvod << endl; 
  cout << "Celobrojni kolicnik= " << celobrojniKolicnik << endl; 
  */
  /*
  string ime, prezime;
  cout << "Unesite ime i prezime:";
  cin >> ime >> prezime;
  cout << "Ime: "<< ime << endl << "Prezime: "<< prezime;
  */

  /*
  int a,b;
  cout <<"Unesite 2 broja: ";
  cin >> a >> b;
  cout << "Broj a: " << a << endl << "Broj b: "<< b;
  */

  /*
  int x = 5;
  double y = 10;
  double z = (x+10) / (3*y); 
  cout << "Prvi broj:"<< x << endl << "Drugi broj:"<< y;
  */

  return 0;
}