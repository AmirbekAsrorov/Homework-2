#include <iostream>
#include <vector>
using namespace std;

void heapDown(vector<int>& A, int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < n && A[left] < A[smallest])
        smallest = left;

    if (right < n && A[right] < A[smallest])
        smallest = right;

    if (smallest != i) {
        swap(A[i], A[smallest]);
        heapDown(A, n, smallest);
    }
}

void buildMinHeap(vector<int>& A, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapDown(A, n, i);
}

int extractMin(vector<int>& A, int& n) {
    if (n <= 0)
        return -1;
    int minVal = A[0];
    A[0] = A[n - 1];
    n--;
    heapDown(A, n, 0);
    return minVal;
}

vector<int> heapSort(vector<int>& A) {
    int n = A.size();
    buildMinHeap(A, n);

    vector<int> sorted;
    while (n > 0) {
        int minVal = extractMin(A, n);
        sorted.push_back(minVal);
    }
    return sorted;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements (they can be positive or negative):\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> sorted = heapSort(A);

    cout << "Sorted array (non-decreasing order): ";
    for (int x : sorted) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
