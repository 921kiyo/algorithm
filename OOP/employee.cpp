#include <iostream>

using namespace std;

class Employee{

protected:
  char* name;
  float salary;

public:
  Employee(float s, char* n){
    salary = s;
    name = n;
  }

  friend ostream& operator<< (ostream& o, const Employee& e){
    return o << e.name << " earns " << e.salary;
  }
};

class Manager : public Employee {

private:
  int level;

public:
  Manager(int l, char* n) : Employee(10000.0 * 1, n){
    level = 1;
  }
  // Manager(int l, char* n){
  //   level = l;
  //   name = n;
  //   salary = 10000.0 * 1;
  // }

  ostream& operator >> (ostream& o) const {
    return o << *this << " at level " << level;
  }
};

class Desk{
public:
  Desk(){ cout << "Desk::Desk() \n"; }
  ~Desk(){ cout << "Desk::~Desk() \n"; }
};

class Office{
public:
  Office(){ cout << "Office::Office() \n"; }
  ~Office(){ cout << "Office::~Office() \n"; }
};

class PC{
public:
  PC(){ cout << "PC::PC() \n"; }
  ~PC(){ cout << "PC::~PC() \n"; }

  void turnOn(){ cout << "turns PC on \n"; }
  void turnOff(){ cout << "turns PC off \n"; }

};

class Empl{
  Desk myDesk;
  Office* myOffice;
public:
  Empl(Office* o){
    myOffice = o;
    cout << "Empl::Empl() \n";
  }
  ~Empl() { cout << "Empl::~Empl() \n"; }
};

class Boss : public Empl{
  PC myPC;
public:
  Boss(Office* o) : Empl(o){
    myPC.turnOn();
    cout << "Boss::Boss() \n";
  }
  ~Boss(){
    myPC.turnOff();
    cout << "Boss::~Boss() \n";
  }
};

int main(){
  Office* pOff;
  pOff = new Office;

  Empl* pEmpl = new Empl(pOff);

  delete pEmpl;
  cout << "------------" << endl;
  Boss* pBoss = new Boss(pOff);

  delete pBoss;
  return 0;
}
