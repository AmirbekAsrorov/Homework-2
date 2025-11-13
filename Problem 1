#include <iostream>
#include <vector>
using namespace std;

void heapDown(vector<int>& A, int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < n && A[left] < A[smallest]) {
        smallest = left;
    }

    if (right < n && A[right] < A[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(A[i], A[smallest]);
        heapDown(A, n, smallest);
    }
}

void displayHeap(const vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, i;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements of the array:\n";
    for (int j = 0; j < n; ++j) {
        cin >> A[j];
    }

    cout << "Enter the index to perform HeapDown: ";
    cin >> i;

    cout << "Array before HeapDown at index " << i << ": ";
    displayHeap(A);

    heapDown(A, n, i);

    cout << "Array after HeapDown at index " << i << ": ";
    displayHeap(A);

    return 0;
}
