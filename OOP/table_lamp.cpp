#include <iostream>

using namespace std;

class TableLamp {
  enum {ON, OFF} state;
public:
  TableLamp() { state = ON;}
  void pressSwitch(){
    state = ( state == ON ? OFF : ON);
  }

  friend ostream& operator << (ostream& o, const TableLamp& t){
    return o << (t.state == TableLamp::ON ? " is on": " is off");
  }
};

class AdjTableLamp: public TableLamp {
  float brightness;
public:
  AdjTableLamp(){ brightness = 1.0;}
  void dim(){
    if (brightness > 0.1) brightness -= 0.1;
  }
  void print(ostream& o) const {
    o << *this << " with brightness " << brightness << endl;
  }
};


int main(){
  AdjTableLamp myLamp;

  cout << "myLamp";
  myLamp.print(cout);

  myLamp.pressSwitch();
  cout << "myLamp " << myLamp;

  AdjTableLamp* hisLamp = new AdjTableLamp();
  TableLamp* herLamp = hisLamp; // Implicit conversion of pointers
  // not allowed: hisLamp = herLamp;

  AdjTableLamp myLamp;
  TableLamp theirLamp;

  herLamp = &myLamp;

  // not allowed: hisLamp = & theirLamp
}
