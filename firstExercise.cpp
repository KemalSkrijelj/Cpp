#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main(){
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