/*Write a menu driven program to perform the following Queue as ADT
1. Make Empty
2.isfull
3.isempty
4.enqueue
5.Dequeue
6.Traverse
*/


#include <iostream>
#include <vector>
using namespace std;

class Queue {
public:
    int rear, front, size;
    vector<int> qu;

    Queue() {
        rear = -1;
        front = 0;

        cout << "Enter the  size of the queue: ";
        cin >> size;

        qu.resize(size);
    }

    void makeEmpty() {
        rear = -1;
        front = 0;
        cout << "The queue has been made empty." << endl;
    }

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue() {
        if (!isFull()) {
            ++rear;
            int choice;
            cout << "Enter the element to be placed in the queue: ";
            cin >> choice;
            qu[rear] = choice;
            cout << "Element has been placed in the Queue." << endl;
        } else {
            cout << "Queue is full." << endl;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            cout << qu[front] << " dequeued." << endl;
            ++front;
        } else {
            cout << "Queue is empty." << endl;
        }
    }

    void traverse() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; ++i) {
                cout << qu[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q1;

    int choice;
    bool run = true;

    while (run) {
        cout << "\nMenu:" << endl;
        cout << "1. Make Queue Empty" << endl;
        cout << "2. Check if Queue is Full" << endl;
        cout << "3. Check if Queue is Empty" << endl;
        cout << "4. Enqueue" << endl;
        cout << "5. Dequeue" << endl;
        cout << "6. Traverse elements of Queue" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                q1.makeEmpty();
                break;

            case 2:
                if (q1.isFull()) {
                    cout << "Queue is full." << endl;
                } else {
                    cout << "You can add elements to the Queue." << endl;
                }
                break;

            case 3:
                if (q1.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;

            case 4:
                q1.enqueue();
                break;

            case 5:
                q1.dequeue();
                break;

            case 6:
                q1.traverse();
                break;

            case 7:
                cout << "Exiting the program." << endl;
                run = false;
                break;

            default:
                cout << "Enter a valid choice!" << endl;
                break;
        }
    }

    return 0;
}

