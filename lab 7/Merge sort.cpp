#include<iostream>
#include<cmath>
using namespace std;

void merge(int A[], int B[], int l, int m, int r) {
    int x = l, y = m + 1, k = l;
    
    while (x <= m && y <= r) {
        if (A[x] < A[y]) {
            B[k] = A[x];
            x++;
        } else {
            B[k] = A[y];
            y++;
        }
        k++;
    }
	 while (x <= m) {
        B[k] = A[x];
        x++;
        k++;
    }
		 while (y <= r) {
        B[k] = A[y];
        y++;
        k++;
    }
	for (int i = l; i <= r; i++) {
        A[i] = B[i];
    }
}

void mergesort(int A[], int B[], int l, int r) {
    if (l < r) {
        int m = floor((l + r) / 2);
        
        mergesort(A, B, l, m);    
        mergesort(A, B, m + 1, r); 
        
        merge(A, B, l, m, r);      
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
    
    int A[n], B[n];
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    mergesort(A, B, 0, n - 1);
    cout << "Sorted array: ";
    printArray(A, n);
    
    return 0;
}


