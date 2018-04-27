#include <iostream>

using namespace std;

class EmployeeList{
  EmployeeList* next;
  Employee* theEmployee;

public:
  EmployeeList(Employee* e): theEmployee(e), next(nullptr){}

  void insert(Employee* e){
    EmployeeList* newList = new EmployeeList(e);
    newList->next = next;
    next = nextList;
  }

  frind ostream& operator<<(ostream& o, const EmployeeList& l){
    o << *(l.theEmployee) << endl;

    return (l.next == nullptr) ? o << endl : o << *(l.next);
  }

  void paycut(float a){
    theEmployee->paycut(a);
    if(next != nullptr) next->paycut(a);
  }
};

int main(){
  return 0;
}
