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

class Air{
  int maxNumOfPressures, actualNum;
  double maxValue;
  double *data;
  public:
  Air(int capacity, double value) {
    actualNum = 0;  maxNumOfPressures = capacity;
    maxValue = value; 
    data = new double[capacity]; 
  }
  ~Air() { delete[] data; } 
  Air(const Air &a){
    actualNum = a.actualNum; maxNumOfPressures = a.maxNumOfPressures;
    maxValue = a.maxValue;
    data = new double[a.maxNumOfPressures];
    for (int i = 0; i < actualNum; i++) data[i] = a.data[i];
  }
  Air& operator=(const Air &a){
    if (&a != this){
      delete[] data;
      actualNum = a.actualNum;
      maxNumOfPressures = a.maxNumOfPressures;
      maxValue = a.maxValue;
      data = new double[a.maxNumOfPressures];
      for (int i = 0; i < actualNum; i++) data[i] = a.data[i];
    }
    return *this;
  }
  void Register(double newPressure){
    if(actualNum == maxNumOfPressures) throw range_error("FULL");
    if(newPressure < 0 || newPressure > maxValue) throw range_error("New pressure must be positive and not be greather then max value.");
    data[actualNum++] = newPressure;
  }
  double getHighest() const {
    double biggest = data[0];
    for (int i = 1; i < actualNum; i++)
    {
      if(data[i] > biggest) biggest = data[i];
    }
    return biggest;
  }
  double getAvarage() const {
    double sum = 0.0;
    for (int i = 0; i < actualNum; i++)
    {
      sum += data[i];
    }
    return sum / actualNum;
  }
  double operator[](int index) const {
    if(index < 1 || index > actualNum) throw domain_error("Index must be in range!");
    return data[index -  1];
  }
  void Display() const {
    for (int i = 0; i < actualNum; i++) cout << data[i] << " ";
  }
};


struct Pair { double x, y; };

class Pairs{
  int maxNumOfPairs, actualNumOfPairs;
  Pair *data; // data je tipa PAIR odnosno Struct , a Pair sadrzi x i y
  public:
  Pairs(int capacity) {
    actualNumOfPairs = 0;
    maxNumOfPairs = capacity;
    data = new Pair[capacity];
  }
  ~Pairs() { delete[] data; }
  Pairs(const Pairs &p){ 
    maxNumOfPairs = p.maxNumOfPairs;
    actualNumOfPairs = p.actualNumOfPairs;
    data = new Pair[p.maxNumOfPairs];
    for (int i = 0; i < actualNumOfPairs; i++) data[i] = p.data[i]; 
  }
  Pairs& operator=(const Pairs &p){ 
    if(&p != this){
      delete[] data;
      maxNumOfPairs = p.maxNumOfPairs;
      actualNumOfPairs = p.actualNumOfPairs;
      data = new Pair[p.maxNumOfPairs];
      for (int i = 0; i < actualNumOfPairs; i++) data[i] = p.data[i]; 
    }
    return *this;
  }
  void Register(double x, double y){
    if(actualNumOfPairs == maxNumOfPairs) throw range_error("FULL");
    for (int i = 0; i < actualNumOfPairs; i++)
    {
      if(data[i].x == x && data[i].y == y) throw domain_error("Pair already exist");
    }
    data[actualNumOfPairs++] = {x,y};
  }
  void Delete(double enteredX){
    for (int i = 0; i < actualNumOfPairs; i++){
      if(data[i].x == enteredX){
        for (int j = i; j < actualNumOfPairs - 1; j++) // ova for petlja sluzi za popunjavanje RUPE koja je nastala prilikom brisanja podatka s vrednoscu koju smo uneli
        {
          data[j] = data[j+1];
        }
        actualNumOfPairs--;
        return;
      }
    }
    throw domain_error("This X not exist!");
  }
  void Sort(){
    for (int i = 0; i < actualNumOfPairs-1; i++){
      for (int j = i+1; j < actualNumOfPairs; j++){
        if(data[i].x > data[j].x){
          Pair temp = data[i];
          data[i] = data[j];
          data[j] = temp; 
        }
      }
    }
  }
  double& operator[](double x) const {
    for (int i = 0; i < actualNumOfPairs; i++){
      if(data[i].x == x) return data[i].y;
    }
    throw domain_error("X not found!");
  }
  void Display() const {
    for (int i = 0; i < actualNumOfPairs; i++) cout << "(" << data[i].x << ", " << data[i].y << ")" ;
    cout << endl;
  }
};

struct PairDictionary{ string English, Bosnian; };

class Dictionary{
  int maxNumOfPairs, actualNumOfPairs;
  PairDictionary *data;
  public:
  Dictionary(int capacity){
    actualNumOfPairs = 0;
    maxNumOfPairs = capacity;
    data = new PairDictionary[capacity];
  }
  ~Dictionary() { delete[] data; }

  Dictionary(const Dictionary &d){
    actualNumOfPairs = d.actualNumOfPairs;
    maxNumOfPairs = d.maxNumOfPairs;
    data = new PairDictionary[d.maxNumOfPairs];
    for (int i = 0; i < actualNumOfPairs; i++) data[i] = d.data[i];
  }
  Dictionary& operator=(const Dictionary &d){
    if(&d != this){
      delete[] data;
      actualNumOfPairs = d.actualNumOfPairs;
      maxNumOfPairs = d.maxNumOfPairs;
      data = new PairDictionary[d.maxNumOfPairs];
      for (int i = 0; i < actualNumOfPairs; i++) data[i] = d.data[i];
    }
    return *this;
  }
  void Register(string str1, string str2){
    if(actualNumOfPairs == maxNumOfPairs) throw range_error("FULL!");
    for (int i = 0; i < actualNumOfPairs; i++)
    {
      if(data[i].English == str1 ) throw domain_error("This string already exist.");
    }
    data[actualNumOfPairs++] = {str1, str2};
  }

  void Delete(string str){
    for (int i = 0; i < actualNumOfPairs; i++){
      if(data[i].English == str){
        for (int j = i; j < actualNumOfPairs - 1; j++)
        {
          data[j] = data[j+1];
        }
        actualNumOfPairs--;
        return;
      }
    }
  }
  string operator[](string engWord) const { // kopija stringa
    for (int i = 0; i < actualNumOfPairs; i++){
      if (data[i].English == engWord){
        return data[i].Bosnian;
      }
    }
    throw domain_error("Word not found");
  }
  string &operator[](string engWord){ // koristimo & jer moramo promijeniti tacnu vrijednost, ako ne stavimo & nece promijeniti tacnu
    for (int i = 0; i < actualNumOfPairs; i++){
      if (data[i].English == engWord){
        return data[i].Bosnian;
      }
    }
    throw domain_error("This word not exist!");
  }
  void Display() const {
    for (int i = 0; i < actualNumOfPairs; i++) cout << "(" << data[i].English << ", " << data[i].Bosnian << "), ";
    cout << endl;
  }
};

int main(){
  Dictionary d(5);
  d.Register("Apple", "Jabuka"); d.Register("Orange", "Pomorandza"); d.Register("Strawberries", "Jagode"); d.Register("Pineapple", "Ananas");
  d.Display(); cout << endl;

  d.Delete("Orange");
  cout << "After deleting: "; d.Display(); cout << endl;

  Dictionary d2 = d;
  cout << "New object d2: ";
  d2.Display(); cout << endl;

  Dictionary d3(3);
  d3.Register("Apple", "Jabuka"); d3.Register("Grapes", "Grozdje"); d3.Register("Strawberries", "Jagode");
  cout << "Object d3: "; d3.Display();

  cout << "Object d3 catch the values from object d: "; d3 = d; d3.Display(); cout << endl;

  cout << d2["Apple"] << endl; //citanje prijevoda na bosanski 

  d["Apple"] = "Crvena Jabuka";
  cout << "After changing Apple on bosnian: "; d.Display(); cout << endl;

  /* PAIRS FOR X AND Y
  Pairs p(5);
  p.Register(2,3); p.Register(2.8,3.6); p.Register(1.1,3.2); p.Register(2.1,3.2);  p.Register(2.9,3.4);
  p.Display();
  p.Sort();
  cout << "After sorting: " << endl;
  p.Display(); cout << endl;

  Pairs p2 = p; // ovo je copy constructor
  cout << "new object P2: ";
  p2.Display(); 
  int index;
  cout << "Enter index, if you want to see y from this positon: " << endl; cin >> index;
  cout << "Chosed y from p2: " << p2[index] << endl;
  cout << endl;
  
  Pairs p3(4);
  p3.Register(2,3); p3.Register(10.8,3.6); p3.Register(6.1,3.2); p3.Register(9.1,1.2);
  cout << "new object P3: "; 
  p3.Display();
  
  p3 = p; //operator=
  cout << "P3 use the values from p(sorted):  ";
  p3.Display();
  */


  /* AIR PRESURESS
  Air a(5, 32);
  a.Register(12.5); a.Register(9.5);  a.Register(11.1);  a.Register(31.1);
  a.Display();
  int index;
  cout << "Enter index which you want to see: " << endl; cin >> index;
  cout << "Chosed pressure: "<< a[index];
  */
   
  /*TEMPERATURES
  Temperatures t(5, -30, 40); // inicijalizujemo da niz moze imati max 5 temp, min da je -30, max da je 40
  t.Register(10); t.Register(5); t.Register(-3); t.Register(7); // ubacujemo vrijednosti
  t.Display();
  t.Sort();
  cout << "After sorting: " << endl;
  t.Display();
  Temperatures t2 = t; // ovo je copy constructor, jer kreiramo novi objekat, a da je bio vec postojeci onda mi koristili operator=
  cout << "Avarage:" << t.getAvarage();
  */

  return 0;
}