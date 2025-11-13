#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class MaxPriorityQueue {
private:
    vector<int> pq;
    int currentSize = 0;

public:
    void insert(int x) {
        pq.push_back(x);
        currentSize++;
    }

    void getMax() {
        if (currentSize == 0) {
            cout << "EMPTY" << endl;
            return;
        }
        int maxElem = INT_MIN;
        for (int i = 0; i < currentSize; i++) {
            if (pq[i] > maxElem) {
                maxElem = pq[i];
            }
        }
        cout << maxElem << endl;
    }

    void extractMax() {
        if (currentSize == 0) {
            cout << "EMPTY" << endl;
            return;
        }

        int maxElem = INT_MIN;
        int maxIndex = -1;

        for (int i = 0; i < currentSize; i++) {
            if (pq[i] > maxElem) {
                maxElem = pq[i];
                maxIndex = i;
            }
        }

        swap(pq[maxIndex], pq[currentSize - 1]);
        pq.pop_back();
        currentSize--;

        cout << maxElem << endl;
    }

    void size() {
        cout << currentSize << endl;
    }
};

int main() {
    MaxPriorityQueue pq;

    int choice, x;
    while (true) {
        cout << "1. Insert x\n";
        cout << "2. Get Max\n";
        cout << "3. Extract Max\n";
        cout << "4. Size\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> x;
                pq.insert(x);
                break;
            case 2:
                pq.getMax();
                break;
            case 3:
                pq.extractMax();
                break;
            case 4:
                pq.size();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
