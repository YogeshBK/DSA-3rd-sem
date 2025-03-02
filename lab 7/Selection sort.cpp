#include<iostream>
using namespace std;

void selectionSort(int A[], int n) {
    int least, p;
    for (int i = 0; i < n - 1; i++) {
        least = A[i];
        p = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[p]) {
                p = j;
            }
        }
        if (i != p) {
            swap(A[i], A[p]);
        }
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
   
    selectionSort(A, n);
    cout << "Sorted array: ";
    printArray(A, n);
    return 0;
}
