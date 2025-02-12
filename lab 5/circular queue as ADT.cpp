#include <iostream>

using namespace std;

class CircularQueue {
private:
    int front, rear, *items, MAX;

public:
    CircularQueue(int size) {
        MAX = size;
        front = -1;
        rear = -1;
        items = new int[MAX];  // Dynamic array allocation
    }

    
    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full." << endl;
        } else {
            if (front == -1) front = 0;
            rear = (rear + 1) % MAX;
            items[rear] = value;
            cout << "Element " << value << " is enqueued to the queue." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to delete." << endl;
            return;
        }
        cout << "Element " << items[front] << " is dequeued from the queue." << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements are: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }

    void makeEmpty() {
        front = -1;
        rear = -1;
        cout << "Queue is now empty." << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the Circular Queue: ";
    cin >> size;

    CircularQueue q(size);
    int choice, item;

    do {
        cout << endl << "--- Circular Queue Menu ---" << endl;
        cout << "1. Make Empty" << endl;
        cout << "2. Is Queue Full?" << endl;
        cout << "3. Is Queue Empty?" << endl;
        cout << "4. Enqueue" << endl;
        cout << "5. Dequeue" << endl;
        cout << "6. Traverse" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                q.makeEmpty();
                break;
            case 2:
                cout << (q.isFull() ? "Queue is Full." : "Queue is not Full.") << endl;
                break;
            case 3:
                cout << (q.isEmpty() ? "Queue is Empty." : "Queue is not Empty.") << endl;
                break;
            case 4:
                cout << "Enter  the element to enqueue: ";
                cin >> item;
                q.enqueue(item);
                break;
            case 5:
                q.dequeue();
                break;
            case 6:
                q.display();
                break;
            case 7:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid Choice. Try again." << endl;
        }
    } while (true);

    return 0;
}

