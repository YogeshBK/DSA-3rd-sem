#include<iostream>
using namespace std;

int partition(int A[], int l, int r) {
    int x = l, y = r;
    int p = A[l];

    while (x < y) {
        while (A[x] <= p && x < r) x++;
        while (A[y] > p) y--;
        
        if (x < y)
            swap(A[x], A[y]);
    }
    swap(A[l], A[y]);
    return y;
}

void quickSort(int A[], int l, int r) {
    if (l < r) {
        int p = partition(A, l, r);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, r);
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
    	 quickSort(A, 0, n - 1);
	 cout << "Sorted array: ";
    printArray(A, n); 
    
    return 0;
}
