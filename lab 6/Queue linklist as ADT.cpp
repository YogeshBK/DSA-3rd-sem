#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int maxSize;
    int currentSize;

public:
    Queue(int size) {
        front = rear = NULL;
        maxSize = size;
        currentSize = 0;
    }

    void enqueue(int value) {
        if (currentSize == maxSize) {
            cout  << "Queue is full! "  << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        currentSize++;
        cout << value << " successfully enqueued." << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        currentSize--;
        cout << "Element dequeued from front of the queue." << endl;
    }

    int peek() {
        if (front == NULL) {
            cout  << "Queue is empty." << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }

    bool isFull() {
        return currentSize == maxSize;
    }

    void display() {
        if (front == NULL) {
            cout  << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout  << "Queue contents: ";
        while (temp != NULL) {
            cout << temp->data << " <- ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    int maxSize;
    cout << "Enter the maximum size for the queue: ";
    cin >> maxSize;

    Queue q(maxSize);
    int choice, value;

    while (true) {
        cout << endl << "Queue Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if Queue is Empty" << endl;
        cout << "5. Check if Queue is Full" << endl;
        cout << "6. Display Queue" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                cout << "Front element is: " << q.peek() << endl;
                break;

            case 4:
                if (q.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;

            case 5:
                if (q.isFull()) {
                    cout  << "Queue is full." << endl;
                } else {
                    cout  << "Queue is not full." << endl;
                }
                break;

            case 6:
                q.display();
                break;

            case 7:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

