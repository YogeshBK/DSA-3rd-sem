#include <iostream>

#define MAX_SIZE 5

using namespace std;
 // Maximum size of the priority queue

// Priority Queue Class
class PriorityQueue {
private:
    int arr[MAX_SIZE]; // Array to store elements
    int size; // Current number of elements
    bool isAscending; // Mode: true for Min-Heap, false for Max-Heap

public:
    // Constructor
    PriorityQueue(bool order) {
        size = 0;
        isAscending = order;
    }

    // Function to insert an element into the priority queue
    void insert(int value) {
        if (size >= MAX_SIZE) {
            cout << "Priority Queue is full."<<endl;
            return;
        }

        // Insert at the end
        arr[size] = value;
        size++;

        // Sort based on order type
        for (int i = size - 1; i > 0; i--) {
            if ((isAscending && arr[i] < arr[i - 1]) || (!isAscending && arr[i] > arr[i - 1])) {
                swap(arr[i], arr[i - 1]);
            } else {
                break;
            }
        }

        cout << "Element inserted successfully."<<endl;
    }

    // Function to delete the minimum element (for Ascending order)
    void deleteMin() {
        if (size == 0 || !isAscending) {
            cout << " Priority Queue is empty!"<<endl;
            return;
        }
        cout << "Deleted minimum element: " << arr[0] << endl;
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Function to delete the maximum element (for Descending order)
    void deleteMax() {
        if (size == 0 || isAscending) {
            cout << " Priority Queue is empty!"<<endl;
            return;
        }
        cout << "Deleted maximum element: " << arr[0] << endl;
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Function to display the queue
    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty."<<endl;
            return;
        }
        cout << "Priority Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to clear the queue
    void makeEmpty() {
        size = 0;
        cout << "Priority Queue is empty."<<endl;
    }
};

int main() {
    int orderChoice;
    cout << "Choose Priority Queue Order:"<<endl;
    cout << "1. Ascending Order (Min-Priority)"<<endl;
    cout << "2. Descending Order (Max-Priority)"<<endl;
    cout << "Enter your choice: ";
    cin >> orderChoice;

    bool orderType = (orderChoice == 1);
    PriorityQueue pq(orderType);

    int choice, value;

    do {
    	if (orderType)
    	
        cout <<endl<<"Ascending Priority Queue Menu:"<<endl;
        else 
        
        cout <<endl<<" Descending Priority Queue Menu:"<<endl;
        
        cout << "1. Insert an element"<<endl;
        if (orderType)
            cout << "2. Delete the minimum element"<<endl;
        else
            cout << "2. Delete the maximum element"<<endl;
        cout << "3. Display the queue"<<endl;
        cout << "4. Make Empty"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert: ";
                cin >> value;
                pq.insert(value);
                break;

            case 2:
                if (orderType)
                    pq.deleteMin();
                else
                    pq.deleteMax();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                pq.makeEmpty();
                break;

            case 5:
                cout << "Exiting the program..."<<endl;
                break;

            default:
                cout << "Invalid choice! Please try again."<<endl;
        }
    } while (choice != 5);

    return 0;
}

