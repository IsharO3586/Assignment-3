#include <iostream>
#include "Queue.h"
using namespace std;
#include <vector>

// Recursive function to find last occurrence
int recursiveLastSearch(const std::vector<int>& vec, int target, int index) {
    if (index < 0) return -1; //base case
    if (vec[index] == target) return index; 
    return recursiveLastSearch(vec, target, index - 1); //keep searching
}

void insertionSortQueue(Queue<int>& q) {
    vector<int> temp;

    // Step 1: Pull all values into a vector
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }

    // Step 2: Standard insertion sort
    for (int i = 1; i < temp.size(); ++i) {
        int key = temp[i];
        int j = i - 1;
        while (j >= 0 && temp[j] > key) {
            temp[j + 1] = temp[j];
            j--;
        }
        temp[j + 1] = key;
    }

    // Step 3: Push sorted values back into queue
    for (int val : temp) {
        q.push(val);
    }
}

int main() {
    Queue<int> q;

    // Push 10 values
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }

    cout << "Q1- Queue elements: ";
    q.display();

    // Move front to rear
    q.move_to_rear();
    cout << "Q1- After move_to_rear(): ";
    q.display();
  cout << "\n";
    // Q2: Recursive last occurrence test
    vector<int> data = {1, 2, 5, 3, 5, 4};
    int target = 5;

    int lastIndex = recursiveLastSearch(data, target, data.size() - 1);
    cout << "Q2- Last occurrence of " << target << " is at index: " << lastIndex << endl;
  cout << "\n"; 
  
  // Shuffle the queue
  Queue<int> unsortedQ;
  unsortedQ.push(4);
  unsortedQ.push(2);
  unsortedQ.push(8);
  unsortedQ.push(1);
  unsortedQ.push(3);
  

  cout << "Q3- Before sorting: ";
  unsortedQ.display();

  insertionSortQueue(unsortedQ);

  cout << "Q3- After insertionSortQueue(): ";
  unsortedQ.display();

    return 0;
}
