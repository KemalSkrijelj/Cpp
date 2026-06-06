#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

class Temperatures{
  int addedTemps, numOfTemps; // addedTemps je broj ubacenih temperatura, a numOfTemps je capacity
  double minT, maxT;
  double *data; // kreirali smo neki pokazivac
  public:
  Temperatures(int capacity, int minT1, int maxT1) {
    addedTemps = 0; // pocetna vrijednost mi je 0(nemam ni jednu temperaturu trenutno)
    numOfTemps = capacity;
    minT = minT1; maxT = maxT1;
    data = new double[capacity];  // kreira se dinamcki niz u memoriji, a data je adresa prvog el. niza
  }
  ~Temperatures() { delete[] data; }

  Temperatures(const Temperatures &t){ // copy constructor, ex. Temperatures t1(10,-20,50); Temperatures t2 = t1;
    addedTemps = t.addedTemps;
    numOfTemps = t.numOfTemps;
    minT = t.minT; maxT = t.maxT;
    data = new double[t.numOfTemps];
    for (int i = 0; i < addedTemps; i++) data[i] = t.data[i];
  }

  Temperatures &operator=(const Temperatures &t){ //vec postojeci objekat dobija novu vrijednost
    if(&t != this){
      delete[] data; //FIRST STEP, WE MUST DELETE OLD INFORMATIONS
      addedTemps = t.addedTemps;
      numOfTemps = t.numOfTemps;
      minT = t.minT; maxT = t.maxT;
      data = new double[t.numOfTemps];
      for (int i = 0; i < addedTemps; i++) data[i] = t.data[i];
    }
    return *this;
  }

  void Register(double newTemp) {
    if(addedTemps == numOfTemps) throw range_error("FULL!");
    if(newTemp < minT || newTemp > maxT) throw range_error("Bad temperature");
    data[addedTemps++] = newTemp; // ubacuje novu vrijednost na novu poziciju
  }
  double getHighest() const {
    double max = data[0];
    for (int i = 1; i < addedTemps; i++)
    {
      if(data[i] > max) max = data[i];
    }
    return max;
  }
  double getMin() const {
    double min = data[0];
    for (int i = 1; i < addedTemps; i++)
    {
      if(data[i] < min) min = data[i];
    }
    return min;
  }
  double getAvarage() const {
    double s = 0.0;
    for (int i = 0; i < addedTemps; i++)
    {
      s += data[i];
    }
    return s / addedTemps;
  }
  void Sort(){
    for (int i = 0; i < addedTemps - 1; i++)
    {
      for (int j = i+1; j < addedTemps; j++)
      {
        if(data[i] > data[j]){
          double temp = data[i];
          data[i] = data[j];
          data[j] = temp;
        } 
      }
    }
  }

  void Display() const {
    for (int i = 0; i < addedTemps; i++) cout << data[i] << " " ;
  }
};

int main(){
  Temperatures t(5, -30, 40); // inicijalizujemo da niz moze imati max 5 temp, min da je -30, max da je 40
  t.Register(10); t.Register(5); t.Register(-3); t.Register(7); // ubacujemo vrijednosti
  t.Display();
  t.Sort();
  cout << "After sorting: " << endl;
  t.Display();
  Temperatures t2 = t; // ovo je copy constructor, jer kreiramo novi objekat, a da je bio vec postojeci onda mi koristili operator=
  cout << "Avarage:" << t.getAvarage();

  return 0;
}