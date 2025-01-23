/*write a enu driven program in array as ADT
1.insert an element in an array
2.delete an element
3.search an element
4.sort
5.display elements of array
6.merge an array
7.exit
*/



#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int main() {
    int arr[MAX_SIZE]; 
    int size;

    
    cout << "Enter the  size of the array ( " << MAX_SIZE << "): ";
    cin >> size;

    
    if (size < 0 || size > MAX_SIZE) {
        cout << "Invalid size! Exiting program."<<endl;
        return 1;
    }

    
    cout << "Enter the elements of the array:"<<endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int choice;
    do {
        cout << "Menu:"<<endl;
        cout << "1. Insert"<<endl;
        cout << "2. Delete"<<endl;
        cout << "3. Search"<<endl;
        cout << "4. Sort"<<endl;
        cout << "5. Display"<<endl;
        cout << "6. Merge"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (size >= MAX_SIZE) {
                    cout << "Array is full." << endl;
                } else {
                    int element;
                    cout << "Enter the element to insert: ";
                    cin >> element;
                    arr[size++] = element;
                    cout << "Element inserted successfully."<<endl;
                }
                break;
            }
            case 2: {
                if (size == 0) {
                    cout << "The array is empty." << endl;
                } else {
                    int element;
                    cout << "Enter the element to delete: ";
                    cin >> element;

                    bool found = false;
                    for (int i = 0; i < size; i++) {
                        if (arr[i] == element) {
                            for (int j = i; j < size - 1; j++) {
                                arr[j] = arr[j + 1];
                            }
                            size--;
                            found = true;
                            cout << "Element deleted successfully."<<endl;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "Element not found in the array."<<endl;
                    }
                }
                break;
            }
            case 3: {
                if (size == 0) {
                    cout << "The array is empty. Nothing to search."<<endl;
                } else {
                    int element;
                    cout << "Enter the element to search: ";
                    cin >> element;
                    
                    for (int i = 0; i < size; i++) {
                        if (arr[i] == element) {
                            cout << "Element found at position " << i + 1 << "."<<endl;
                            
                            
                        }
                    }
                    
                }
                break;
            }
            case 4: {
                if (size == 0) {
                    cout << "The array is empty. Nothing to sort."<<endl;
                } else {
                    for (int i = 0; i < size - 1; i++) {
                        for (int j = 0; j < size - i - 1; j++) {
                            if (arr[j] > arr[j + 1]) {
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                            }
                        }
                    }
                    cout << "Array sorted successfully."<<endl;
                }
                break;
            }
            case 5: {
                if (size == 0) {
                    cout << "The array is empty."<<endl;
                } else {
                    cout << "Current array elements are: ";
                    for (int i = 0; i < size; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case 6: {
               
                    int n;
                    cout << "Enter the number of elements to merge: ";
                    cin >> n;

                    if (size + n > MAX_SIZE) {
                        cout << "Cannot merge. "<<endl;
                    } else {
                        cout << "Enter the elements to merge:"<<endl;
                        for (int i = 0; i < n; i++) {
                            cin >> arr[size++];
                        }
                        cout << "Arrays merged successfully."<<endl;
                    
                }
                break;
            }
            case 7:
                cout << "Exiting the program."<<endl;
                break;
            default:
                cout << "Invalid choice."<<endl;
        }
    } while (choice != 7);

    return 0;
}
