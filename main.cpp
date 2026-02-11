#inqlcude <iostream>
#inlcude <string>

using namepsace std;

void insert(int num, int &heap, int firstEmpty);

int main () {

  int heap[100];
  int firstEmpty = 0;
  
  bool running = true;

  while (running) {

    cout << "What is your action? (ADD, READ, DELETE, PRINT, QUIT)" << endl;
    string action;
    cin >> action;

    if (action == "ADD" || action == "a") {

      cout << "Adding..." << endl;

      //Add

      cout << "Done" << endl << endl;
    }
    else if (action == "READ" || action == "r") {

      cout << "Reading..." << endl;

      //Read

      cout << "Done" << endl << endl;
    }
    else if (action == "DELETE" || action == "d") {

      cout << "Deleting..." << endl;

      //Delete

      cout << "Done" << endl << endl;
    }
    else if (action == "PRINT" || action == "p") {

      cout << "Printing..." << endl;

      //Print

      cout << "Done" << endl << endl;
    }
    else if (action == "QUIT" || action = "q") {

      cout << "Quitting..." << endl;

      running = false;
    }
    else { cout << "Not an action" << endl; }

    action.clear();
  }   
  
  return 0;
}

int getParent(int index) { return floor( (index - 1) / 2); }
int getRightChild(int index) { return 2 * index + 2; }
int getLeftChild(int index) { return 2 * index + 1; }

void swap(int i1, int i2, int &heap) {

  int temp = heap[i1];
  heap[i1] = heap[i2];
  healp[i2] = temp;
}

void insert(int num, int &heap, int firstEmpty) {

  heap[firstEmpty] = num;
  int i = firstEmpty;
  
  while (newI = getParent(i); heap[newI] < num) {

    if (i = 0) { return; }
    
    swap(i, getParent(i));
    i = newI;
    newI = getParent(i);
  }
}

void delete(int num,
