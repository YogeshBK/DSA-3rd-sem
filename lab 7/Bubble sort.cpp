#include<iostream>
using namespace std;

void bubblesort(int A[], int n) {
    int temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {  
            if (A[j] > A[j+1]) {
                
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void printArray(int A[], int n) {
    for(int i = 0; i < n; i++) {
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
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    bubblesort(A, n);  

    cout << "Sorted array: ";
    printArray(A, n);  

    return 0;
}
