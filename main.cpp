#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

struct Heap {

  int* data = new int[100];
  int nextEmpty = 0;

  Heap() { for (int i = 0; i < 100; i++) { data[i] = 0; } }

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

      if (i == 0) { nextEmpty++; return; }

      swapP(i);
      i = getParent(i);
    }

    nextEmpty++;
  }

  void del() {

    cout << data[0] << endl;

    swap(0, nextEmpty - 1);
    delRec(0);
    nextEmpty --;
  }

  void delRec(int i) {

    //Bigger than both children
    if (data[i] > data[getRight(i)] && data[i] > data[getLeft(i)]) {}

    //Smaller than right
    else if (data[i] < data[getRight(i)]) { swapR(i); delRec(getRight(i)); }

    //Smaller than left
    else if (data[i] < data[getLeft(i)]) { swapL(i); delRec(getLeft(i)); }

    else { cout << "Something went wrong..." << endl; }
  }

  void print(int i = 0, int indent = 0) {

    //Leaf
    if (data[getRight(i)] == 0 && data[getLeft(i)] == 0) {

      for (int j = indent; j != 0; j--) { cout << "\t"; }
      if (data[i] < 10) { cout << 0; }
      if (data[i] != 0) { cout << data[i] << endl; }
    }

    else {

      print(getRight(i), indent + 1);

      for (int j = indent; j != 0; j--) { cout << "\t"; }
      cout << data[i] << endl;

      print(getLeft(i), indent + 1);
    }
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
