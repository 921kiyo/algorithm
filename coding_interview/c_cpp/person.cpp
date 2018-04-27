#include <iostream>
#include <string>

using namespace std;

#define NAME_SIZE 50

class Person{ // Abstract class because of the pure virtual function
  int id;
  char name[NAME_SIZE];

public:
  virtual void aboutMe(){
    cout << "I am a person"  << endl;
  }
  virtual bool addCourse(string s) = 0; // Pure virtual function

  virtual ~Person(){
    cout << "Deleting a person." << endl;
  }
};

class Student: public Person{
public:
  void aboutMe(){
    cout << "I am a student" << endl;
  }

  bool addCourse(string s){
    cout << "Added course " << s << " to student." << endl;
    return true;
  }

  ~Student(){
    cout << "Deleting a student." << endl;
  }
};

int main(){
  // Student *p = new Student();
  Person *p = new Student();
  p->aboutMe();
  delete p;
  return 0;
}

template <class T>class ShiftedList{
  T* array;
  int offset, size;
public:
  ShiftedList(int sz) : offset(0), size(sz){
    array = new T[size];
  }

  ~ShiftedList(){
    delete [] array;
  }

  void shiftBy(int n){
    offset = (offset + n) % size;
  }

  T getAt(int i){
    return array[convertIndex(i)];
  }

  void  setAt(T item, int i){
    array[convertIndex(i)] = item;
  }

private:
  int convertIndex(int i){
    int index = (i - offset) % size;
    while (index < 0) index += size;
    return index;
  }
};
