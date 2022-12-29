//The program shows the implementation of separate chaining using hashing technique

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class hashing {
private:
  int data;
  list <int> *table;
public:
  hashing(int num);
  void insertItem(int a);
  void deleteItem(int key);
  int hFunction(int value){
    return  (value % data);
  }
  void printHashing();
};

hashing::hashing(int num){
  this->data = num;
  table = new list<int>[data];
}

void hashing::insertItem(int a){
  int index = hFunction(a);
  table[index].push_back(a);
}

 
void hashing::deleteItem(int key)
{
  int index = hFunction(key);
  list <int> :: iterator num;
  for (num = table[index].begin(); num != table[index].end(); num++) {
    if (*num == key)
      break;
  }
  if (num != table[index].end())
    table[index].erase(num);
}

void hashing::printHashing() {
  for (int i = 0; i < data; i++) {
    cout << i;
    for (auto x : table[i])
      cout << " -> " << x;
    cout << endl;
  }
}
 
int main() {
  int a[] = {21,5,17,30,45,66,38};
  int n = sizeof(a)/sizeof(a[0]);
 
  hashing h(7); 
  for (int i = 0; i < n; i++)
    h.insertItem(a[i]); 

  h.deleteItem(12);
  h.printHashing();
 
  return 0;
}