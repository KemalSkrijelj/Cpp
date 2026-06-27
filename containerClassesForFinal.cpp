#include <iostream>
#include <cmath>

using namespace std;

class Temperatures{
  int actualTemp, numOfTemps;
  double *data;
  public:
  Temperatures(int capacity) {
    actualTemp = 0;
    numOfTemps = capacity;
    data = new double[capacity];
  }
  ~Temperatures() { delete[] data; }
  Temperatures(const Temperatures &t){
    actualTemp = t.actualTemp;
    numOfTemps = t.numOfTemps;
    data = new double[t.numOfTemps];
    for (int i = 0; i < t.numOfTemps; i++) data[i] = t.data[i];
  }
  Temperatures &operator=(const Temperatures &t){
    if(&t != this){
      delete[] data;
      actualTemp = t.actualTemp;
      numOfTemps = t.numOfTemps;
      data = new double[t.numOfTemps];
      for (int i = 0; i < t.numOfTemps; i++) data[i] = t.data[i];
    }
    return *this;
  }
  void Register(double newTemp){
    if(actualTemp == numOfTemps) throw range_error("Storage is full!");
    data[actualTemp++] = newTemp;
  }
  int getActualNumOfTemps() const { return actualTemp; }
  double& operator[](int index){
    if(index < 1 || index > actualTemp) throw range_error("Index must be in range!");
    return data[index-1];
  }
  void Display() const {
    for (int i = 0; i < actualTemp; i++) cout << data[i] << " ";
    cout << endl;
  }
};

class MeasuredTemperatures{
  int actualNum, maxNum;
  double maxTemp, minTemp;
  double *data;
  public:
  MeasuredTemperatures(int capacity, double min, double max) {
    actualNum = 0;
    maxNum = capacity;
    maxTemp = max; minTemp = min;
    data = new double[capacity];
  }
  ~MeasuredTemperatures() { delete[] data; }
  MeasuredTemperatures(const MeasuredTemperatures &t){
    actualNum = t.actualNum;
    maxNum = t.maxNum;
    minTemp = t.minTemp; maxTemp = t.maxTemp;
    data = new double[t.maxNum];
    for (int i = 0; i < t.actualNum; i++) data[i] = t.data[i];
  }
  MeasuredTemperatures& operator=(const MeasuredTemperatures &t){
    if(&t != this){
      delete[] data;
      actualNum = t.actualNum;
      maxNum = t.maxNum;
      minTemp = t.minTemp; maxTemp = t.maxTemp;
      data = new double[t.maxNum];
      for (int i = 0; i < t.actualNum; i++) data[i] = t.data[i];
    } 
    return *this;
  }
  void Registar(double temp){
    if(actualNum == maxNum) throw range_error("FULL!");
    if(temp < minTemp || temp > maxTemp) throw range_error("Temp must be in range!");
    data[actualNum++] = temp;
  }
  double getHighest() const {
    double highest = data[0];
    for (int i = 1; i < actualNum; i++)
    {
      if(data[i] > highest) highest = data[i];
    }
    return highest;
  }
  double getMinimum() const {
    double min = data[0];
    for (int i = 1; i < actualNum; i++)
    {
      if(data[i] < min) min = data[i];
    }
    return min;
  }
  double getAvarage() const {
    double sum = 0.0;
    for (int i = 0; i < actualNum; i++)
    {
      sum += data[i];
    }
    return sum / actualNum;
  }
  void Sort(){
    for (int i = 0; i < actualNum - 1; i++)
    {
      for (int j = i+1; j < actualNum; j++)
      {
        if(data[i] > data[j]){
          double temp = data[i];
          data[i] = data[j];
          data[j] = temp;
        }
      }
    }
  }
  double &operator[](int index){
    if(index < 1 || index > actualNum) throw range_error("ERROR");
    return data[index-1];
  }
  void Display() const {
    for (int i = 0; i < actualNum; i++) cout << data[i] << " ";
    cout << endl;
  }
};

class Air{
  int actualNum ,maxNumOfAir;
  double maxValue;
  double *data;
  public:
  Air(int capacity, int max){
    actualNum = 0; maxNumOfAir = capacity;
    maxValue = max;
    data = new double[capacity];
  }
  ~Air() { delete[] data; }
  Air(const Air &a){
    actualNum = a.actualNum; maxNumOfAir = a.maxNumOfAir;
    maxValue = a.maxValue;
    data = new double[a.maxNumOfAir];
    for (int i = 0; i < actualNum; i++) data[i] = a.data[i];
  }
  Air& operator=(const Air &a){
    if(&a != this){
      delete[] data;
      actualNum = a.actualNum; maxNumOfAir = a.maxNumOfAir;
      maxValue = a.maxValue;
      data = new double[a.maxNumOfAir];
      for (int i = 0; i < actualNum; i++) data[i] = a.data[i];
    }
    return *this;
  }
  void Register(double pressure){
    if(actualNum == maxNumOfAir) throw range_error("FULL!");
    if(pressure > maxValue) throw range_error("Entered value is greather than max value!!!");
    data[actualNum++] = pressure;
  }
  double getHighest() const {
    double high = data[0];
    for (int i = 1; i < actualNum; i++)
    {
      if(data[i] > high) high = data[i];
    }
    return high;    
  }
  double getAvarage() const {
    double sum = 0.0;
    for (int i = 0; i < actualNum; i++)
    {
      sum += data[i];
    }
    return sum / actualNum;    
  }
  double& operator[](int index){
    if(index < 1 || index > actualNum) throw range_error("Index must be in range!");
    return data[index - 1];
  }
  void Display() const {
    for (int i = 0; i < actualNum; i++) cout << data[i] << " ";
    cout << endl;
  }
};


struct Pair { double x, y; };

class Pairs{
  int actualNum, maxNumOfPairs;
  Pair *data;
  public:
  Pairs(int capacity){
    actualNum = 0; maxNumOfPairs = capacity;
    data = new Pair[capacity];
  }
  ~Pairs() { delete[] data; }
  Pairs(const Pairs &p){
    actualNum = p.actualNum; maxNumOfPairs = p.maxNumOfPairs;
    data = new Pair[p.maxNumOfPairs];
    for (int i = 0; i < actualNum; i++) data[i] = p.data[i];
  }
  Pairs& operator=(const Pairs &p){
    if(&p != this){
      delete[] data;
      actualNum = p.actualNum; maxNumOfPairs = p.maxNumOfPairs;
      data = new Pair[p.maxNumOfPairs];
      for (int i = 0; i < actualNum; i++) data[i] = p.data[i];
    }
    return *this;
  }
  void Register(double x, double y){
    if(actualNum == maxNumOfPairs) throw range_error("FULL!");
    for (int i = 0; i < actualNum; i++) if (data[i].x == x) throw domain_error("ERROR!");
    data[actualNum++] = {x,y}; 
  }
  void Delete(int valueX){
    for (int i = 0; i < actualNum; i++)
    {
      if (data[i].x == valueX){
        for (int j = i; j < actualNum-1; j++)
        {
          data[j] = data[j+1];
        }
        actualNum--;
        i--; // sluzi da se vrati nazad da provjeri opet jer se smanjio actualNum za 1
      }
    } 
  }
  void Sort(){
    for (int i = 0; i < actualNum-1; i++)
    {
      for (int j = i+1; j < actualNum; j++)
      {
        if(data[i].x > data[j].x){
          Pair temp = data[i];
          data[i] = data[j];
          data[j] = temp;
        }
      }
    }
  }

  double& operator[](double valueX){
    for (int i = 0; i < actualNum; i++){
      if(data[i].x == valueX) return data[i].y;
    }
    throw domain_error("Given value is not available"); 
  }
  double operator[](double valueX) const {
    for (int i = 0; i < actualNum; i++){
      if(data[i].x == valueX) return data[i].y;
    }
    throw domain_error("Given value is not available"); 
  }
  void Display() const {
    for (int i = 0; i < actualNum; i++) cout << "{" << data[i].x << "," << data[i].y << "}, ";
    cout << endl;
  }
};

struct PairForDict { string English, Bosnian; };

class Dictionary{
  int actualNum, maxNumOfPairs;
  PairForDict *data;
  public:
  Dictionary(int capacity){
    actualNum = 0; maxNumOfPairs = capacity;
    data = new PairForDict[capacity];
  }
  ~Dictionary() { delete[] data; }
  Dictionary(const Dictionary &d){
    actualNum = d.actualNum; maxNumOfPairs = d.maxNumOfPairs;
    data = new PairForDict[d.maxNumOfPairs];
    for (int i = 0; i < actualNum; i++) data[i] = d.data[i];
  }
  Dictionary& operator=(const Dictionary &d){
    if(&d != this){
      delete[] data;
      actualNum = d.actualNum; maxNumOfPairs = d.maxNumOfPairs;
      data = new PairForDict[d.maxNumOfPairs];
      for (int i = 0; i < actualNum; i++) data[i] = d.data[i];
    }
    return *this;
  }
  void Register(string e, string b){
    if(actualNum == maxNumOfPairs) throw range_error("FULL");
    for (int i = 0; i < actualNum; i++)
    {
      if(data[i].English == e) throw domain_error("English word already exist!");
    }
    data[actualNum++] = {e,b};
  }
  void Delete(string engWord){
    for (int i = 0; i < actualNum; i++)
    {
      if(data[i].English == engWord){
        for (int j = i; j < actualNum - 1; j++)
        {
          data[j] = data[j+1];
        }
        actualNum--;
        i--;
      }
    }
  }
  string& operator[](string engWord){
    for (int i = 0; i < actualNum; i++)
    {
      if(data[i].English == engWord) return data[i].Bosnian;
    }
    throw domain_error("This word not exist!");
  }
  string operator[](string engWord) const {
    for (int i = 0; i < actualNum; i++)
    {
      if(data[i].English == engWord) return data[i].Bosnian;
    }
    throw domain_error("This word not exist!");
  }
  void Display() const {
    for (int i = 0; i < actualNum; i++) cout << "{" << data[i].English << ", " << data[i].Bosnian << "}, ";
    cout << endl;
  }
};


class City {
  string name;
  int inhabitans;
public:
  City() {}
  City(string name1, int inh) { name = name1; inhabitans = inh; }
  string GetName() const { return name; }
  int GetInhabitans() const { return inhabitans; }
};

class Cities{
  int actualNum, maxNumOfCities;
  City *data;
  public:
  Cities(int capacity){
    actualNum = 0; maxNumOfCities = capacity;
    data = new City[capacity];
  }
  ~Cities() { delete[] data; }
  Cities(const Cities &c){
    actualNum = c.actualNum; maxNumOfCities = c.maxNumOfCities;
    data = new City[c.maxNumOfCities];
    for (int i = 0; i < actualNum; i++) data[i] = c.data[i];
  }
  Cities operator=(const Cities &c){
    if(&c != this){
      delete[] data;
      actualNum = c.actualNum; maxNumOfCities = c.maxNumOfCities;
      data = new City[c.maxNumOfCities];
      for (int i = 0; i < actualNum; i++) data[i] = c.data[i];
    }
    return *this;
  }

  void Register(string name, int numOfInhabitans){
    if(actualNum == maxNumOfCities) throw range_error("FULL!");
    for (int i = 0; i < actualNum; i++){
      if(data[i].GetName() == name) throw domain_error("Already exist!");
    }
    data[actualNum++] = {name, numOfInhabitans};
  }
  double getInhabitans(string name){
    for (int i = 0; i < actualNum; i++)
    {
      if(data[i].GetName() == name) return data[i].GetInhabitans();
    }
    throw domain_error("City nooot exist!!");
  }
  double operator[](string name) const {
    for (int i = 0; i < actualNum; i++)
    {
      if(data[i].GetName() == name) return data[i].GetInhabitans();
    }
    throw domain_error("City nooot exist!!");
  }
  void Sort(){
    for (int i = 0; i < actualNum-1; i++)
    {
      for (int j = i+1; j < actualNum; j++)
      {
        if(data[i].GetInhabitans() > data[j].GetInhabitans()){
          City temp = data[i];
          data[i] = data[j];
          data[j] = temp;
        }
      }
    }
  }
  void Display() const {
    for (int i = 0; i < actualNum; i++) cout << data[i].GetName() << ": " << data[i].GetInhabitans() << ", ";
    cout << endl;
  }
};

class Student {
  int index;
  string name;
public:
  Student(int index, string name) : index(index), name(name) {}
  int GetIndex() const { return index; }
  string GetName() const { return name; }
};

class Students{
  int actualNum, maxNumOfStudents;
  Student **data;
  public:
  Students(int capacity){
    actualNum = 0; maxNumOfStudents = capacity;
    data = new Student*[capacity];
  }
  ~Students() {
    for(int i = 0; i < actualNum; i++) delete data[i];
    delete[] data; 
  }

  Students(const Students &s){
    actualNum = s.actualNum; maxNumOfStudents = s.maxNumOfStudents;
    data = new Student*[s.maxNumOfStudents];
    for (int i = 0; i < actualNum; i++) data[i] = new Student(*s.data[i]);
  }
  Students& operator=(const Students &s){
    if(&s != this){
      for (int i = 0; i < actualNum; i++) {
          delete data[i];
      }
      delete[] data;
      actualNum = s.actualNum; maxNumOfStudents = s.maxNumOfStudents;
      data = new Student*[maxNumOfStudents];
      for (int i = 0; i < actualNum; i++) data[i] = new Student(*s.data[i]);
    }
    return *this;
  }
  void Register(int index, string name){
    if(actualNum == maxNumOfStudents) throw range_error("FULL!");
    for (int i = 0; i < actualNum; i++)
    {
      if(data[i]->GetIndex() == index) throw domain_error("Already exist!!!");
    }
    data[actualNum++] = new Student(index, name);
  }
  void Sort(){
    for (int i = 0; i < actualNum - 1; i++)
    {
      for (int j = i+1; j < actualNum; j++)
      {
        if(data[i]->GetIndex() > data[j]->GetIndex()){
          Student *temp = data[i];
          data[i] = data[j];
          data[j] = temp;
        }
      }
    }
  }
  string operator[](int index){
    for (int i = 0; i < actualNum; i++)
    {
      if(data[i]->GetIndex() == index) return data[i]->GetName();
    }
    throw domain_error("Not exist!!");
  }
  void Display() const {
    for (int i = 0; i < actualNum; i++) cout << data[i]->GetIndex() << ", " << data[i]->GetName() << " | ";
    cout << endl;
  }

};

int main(){
  Students s(4);
  s.Register(1233, "Kemal"); s.Register(121, "Ahmed"); s.Register(1111, "Edin"); s.Register(3211, "Rijad");
  s.Display();

  cout << "After sorting: " << endl;
  s.Sort(); s.Display();
  cout << "Name with index 1233 is: "<< s[1233] << endl;
  /*
  Cities c(4);
  c.Register("Novi Pazar", 120000); c.Register("Tuzla", 200000); c.Register("Sjenica", 20000); c.Register("Sarajevo", 520000);
  c.Display();
  
  
  cout << "Inhabitans of Novi Pazar: " << c.getInhabitans("Novi Pazar") << endl; //function getInhabitans()
  cout << "Inhabitans of Sarajevo: " << c["Sarajevo"] << endl; //operator[]
  
  cout << "After sorting (by inhabitans): " << endl;
  c.Sort(); c.Display();
  */

  
  /*
  Dictionary d(4);
  d.Register("Apple", "Jabuka"); d.Register("Orange", "Pomorandza"); d.Register("Pineapple", "Ananas"); d.Register("Grapes", "Grozdje");
  d.Display();
  
  cout << "Apple on Bosnian: " << d["Apple"] << endl;
  d["Apple"] = "Crvena jabuka";
  cout << "Apple on Bosnian: " << d["Apple"] << endl;
  
  d.Delete("Orange");
  cout << "After deleting: " << endl;
  d.Display();
  */

  /*
  Pairs p(3);
  p.Register(2.3, 3.2); p.Register(1.5, 2.2); p.Register(0.3, 1.2);
  p.Display();
  
  cout << "After sorting: " << endl;
  p.Sort();
  p.Display();
  cout << "p[givenXValue] y: " << p[2.3];
  */

  /*
  Air a(4, 12.3);
  a.Register(11.2); a.Register(4.2); a.Register(3.5); a.Register(8.9);
  a.Display();
  
  cout << "Avarage: " << a.getAvarage() << endl;
  cout << "Highest: " << a.getHighest() << endl;
  */


  /*
  MeasuredTemperatures t(5, 3.1, 35.5);
  t.Registar(22.3); t.Registar(12.2); t.Registar(3.3); t.Registar(28.7);
  cout << "t[3]: " << t[3] << endl;
  
  cout << "Avarage: " << t.getAvarage() << endl;
  cout << "Min temp: " << t.getMinimum() << endl;
  cout << "Max temp: " << t.getHighest() << endl;
  
  cout << "Before sorting: " << endl;
  t.Display();
  
  t.Sort();
  cout << "After sorting: " << endl;
  t.Display();
  */

  /*
  Temperatures t(5);
  t.Register(23); t.Register(13); t.Register(15); t.Register(3); t.Register(4);
  t.getActualNumOfTemps();
  t.Display();
  cout << "t[3]: " << t[3] 
  Temperatures t2 = t; //copy constructor
  */

  return 0;
}