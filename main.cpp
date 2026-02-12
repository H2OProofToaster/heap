#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int* getParent(int* index);
int* getRight(int* index);
int* getLeft(int* index);

void swap(int* i1, int* i2);
void swapR(int* i);
void swapL(int* i);
void swapP(int* i);

void insert(int num, int* i);
void del(int* i, int* heap);
void delRec(int* i);
void print(int* i, int indent = 0);

int main () {

  int* heap = new int[100];
  int* firstEmpty = heap;
  
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
      insert(num, firstEmpty);
      firstEmpty = firstEmpty + 1;
      
      cout << "Done" << endl << endl;
    }
    else if ( (action == "READ") || (action == "r") ) {

      cout << "Reading..." << endl;

      //Read

      cout << "Done" << endl << endl;
    }
    else if ( (action == "DELETE") || (action == "d") ) {

      cout << "Deleting..." << endl;

      //Delete
      del(firstEmpty, heap);
      firstEmpty = firstEmpty - 1;

      cout << "Done" << endl << endl;
    }
    else if ( (action == "PRINT") || (action == "p") ) {

      cout << "Printing..." << endl;

      //Print
      print(heap);

      cout << "Done" << endl << endl;
    }
    else if ( (action == "QUIT") || (action == "q") ) {

      cout << "Quitting..." << endl;

      running = false;
    }
    else { cout << "Not an action" << endl; }

    action.clear();
  }   
  
  return 0;
}

int* getParent(int* index) { return floor( (index - 1) / 2); }
int* getRight(int* index) { return 2 * index + 2; }
int* getLeft(int* index) { return 2 * index + 1; }

void swap(int* i1, int* i2) {

  int temp = *i1;
  *i1 = *i2;
  *i2 = temp;
}

void swapR(int* i) { swap(i, getRight(i)); }
void swapL(int* i) { swap(i, getLeft(i)); }
void swapP(int* i) { swap(i, getParent(i)); }

void insert(int num, int* i) {

  *i = num;
  
  while (getParent(i) < num) {

    if (i = 0) { return; }
    
    swapP(i);
    i = getParent(i);
  }
}

void del(int* i, int* heap) {

  cout << heap[0] << endl;

  swap(0, i - 1);
  delRec(heap);
}

void delRec(int *i) {

  if (*i > *getRight(i) && *i > *getLeft(i)) { return; }

  else if (*i > *getRight(i)) { swapR(i); delRec(getRight(i)); }

  else if (*i > *getLeft(i)) { swapL(i); delRec(getLeft(i)); }

  else { cout << "Something went wrong..." << endl; return }
}

void print(int* i, int indent) {

  if (getRight(i) == NULL && getLeft(i) == NULL) {

    for (int j = indent; j != 0; j--) { cout << j; }
    cout << "|" << *i << endl;
  }

  else {

    print(getRight(i), indent + 1);
    print(getLeft(i), indent + 1);
  }
}

  
