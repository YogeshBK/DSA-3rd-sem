#include<iostream>
using namespace std;

void shellSort(int A[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {  
        for (int i = gap; i < n; i++) {  
            int key = A[i];
            int j = i;
            while (j >= gap && A[j - gap] > key) {
                A[j] = A[j - gap];
               j -= gap;
        }
            A[j] = key;
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
    
   
    
    shellSort(A, n);  
    
    cout << "Sorted array: ";
    printArray(A, n); 
    
    return 0;
}
