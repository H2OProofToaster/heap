#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

struct Heap {

  int* data = new int[100];
  int nextEmpty = 0;

  Heap() { for (int i = 0; i < 100; i++) { data[i] = 0; } }
  ~Heap() { delete data; }
  
  int getParent(int index) { return floor( (index - 1) / 2); }
  int getRight(int index) { return 2 * index + 2; }
  int getLeft(int index) { return 2 * index + 1; }

  void swap(int i1, int i2) {

    int temp = data[i1];
    data[i1] = data[i2];
    data[i2] = temp;
  }

  void swapR(int i) { swap(i, getRight(i)); }
  void swapL(int i) { swap(i, getLeft(i)); }
  void swapP(int i) { swap(i, getParent(i)); }

  void insert(int num) {

    int i = nextEmpty;
    data[i] = num;

    while (data[getParent(i)] < num) {

      if (i == 0) { if (nextEmpty != 100) { nextEmpty++; return; } }

      swapP(i);
      i = getParent(i);
    }

    nextEmpty++;
  }

  void del() {

    cout << data[0] << endl;

    swap(0, nextEmpty - 1);
    if (nextEmpty != 0) { nextEmpty--; }
    delRec(0);
  }

  void delRec(int i) {

    int left = getLeft(i);
    int right = getRight(i);

    if (left >= nextEmpty) { return; } //No children

    if (right >= nextEmpty) { //Only left child

      if (data[left] > data[i]) { swapL(i); delRec(left); } //Left child is bigger
      return;
    }

    int biggerChild = (data[left] > data[right]) ? left: right;
    if (data[biggerChild] > data[i]) { swap(i, biggerChild); delRec(biggerChild); }
  }

  void print(int i = 0, int indent = 0) {

    if (i >= nextEmpty) { return; }

    print(getRight(i), indent + 1);

    for (int j = 0; j < indent; j++) { cout << "\t"; }

    if (data[i] < 10 && data[i] != 0) { cout << "0"; }
    if (data[i] != 0) { cout << data[i] << endl; }

    print(getLeft(i), indent + 1);
  }
};

int main () {

  Heap* heap = new Heap();

  bool running = true;

  while (running) {

    cout << "What is your action? (ADD, READ, DELETE, PRINT, QUIT)" << endl;
    string action;
    cin >> action;

    if ( (action == "ADD") ||(action == "a") ) {

      cout << "Adding..." << endl;

      //Add
      cout << "What number? ";
      int num;
      cin >> num;
      heap->insert(num);
      
      cout << "Done" << endl << endl;
    }
    else if ( (action == "READ") || (action == "r") ) {

      cout << "Reading..." << endl;

      //Read
      cout << "What file? ";
      string fileName;
      cin >> fileName;
      ifstream readFile(fileName);
      if (readFile.is_open()) {

	int v;
	while (readFile >> v) { heap->insert(v); }
      }
      readFile.close();
      
      cout << "Done" << endl << endl;
    }
    else if ( (action == "DELETE") || (action == "d") ) {

      cout << "Deleting..." << endl;

      //Delete
      heap->del();

      cout << "Done" << endl << endl;
    }
    else if ( (action == "PRINT") || (action == "p") ) {

      cout << "Printing..." << endl;

      //Print
      heap->print();

      cout << "Done" << endl << endl;
    }
    else if ( (action == "QUIT") || (action == "q") ) {

      cout << "Quitting..." << endl;

      running = false;
      delete heap;
    }
    else { cout << "Not an action" << endl; }

    action.clear();
  }   
  
  return 0;
}
