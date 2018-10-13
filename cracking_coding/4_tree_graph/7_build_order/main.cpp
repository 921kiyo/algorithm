#include <iostream>
#include <tuple>

using namespace std;

int main(){
  char projects[] = {'a','b','c','d','e','f'};
  auto a = make_tuple('d', 'a');
  auto b = make_tuple('b', 'f');
  auto c = make_tuple('d', 'b');
  auto d = make_tuple('a', 'f');
  auto e = make_tuple('c', 'd');
  return 0;
}
