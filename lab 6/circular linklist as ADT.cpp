
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Circular Linked List Class
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Insert at End
    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;  
        } else {
            Node* temp = head;
            while (temp->next != head) {  
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;  
        }
    }

    // Insert at Beginning
    void insertBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert at Specific Position
    void insertAtPosition(int value, int position) {
        if (position == 1) {
            insertBeginning(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        Node* temp = head;
        int count = 1;

        while (temp->next != head && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp->next == head && count < position - 1) {
            cout << "Position out of bounds. Inserting from end." << endl;
            insertEnd(value);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Delete from Beginning
    void deleteBeginning() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        if (head->next == head) {  
            head = NULL;
        } else {
            head = head->next;
            last->next = head;
        }

        delete temp;
    }

    // Delete from End
    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL) {  
            head = NULL;
        } else {
            prev->next = head;
        }

        delete temp;
    }

    // Delete from Specific Position
    void deleteAtPosition(int position) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if (position == 1) {
            deleteBeginning();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        int count = 1;

        while (temp->next != head && count < position) {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (count < position) {
            cout << "Position out of bounds." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Display the List
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(HEAD)" << endl;
    }

 
   
};

// Main Function
int main() {
    CircularLinkedList list;
    int choice, value, position;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Insert at End" << endl;
        cout << "2. Insert at Beginning" << endl;
        cout << "3. Insert at Specific Position" << endl;
        cout << "4. Delete from Beginning" << endl;
        cout << "5. Delete from End" << endl;
        cout << "6. Delete from Specific Position" << endl;
        cout << "7. Traverse List" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at end of circular linklist: ";
                cin >> value;
                list.insertEnd(value);
                cout << value << " successfully inserted at end of circular linklist." << endl;
                break;

            case 2:
                cout << "Enter value to insert at beginning of the circular linklist: ";
                cin >> value;
                list.insertBeginning(value);
                cout << value << " successfully inserted at beginning of the circular linklist." << endl;
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(value, position);
                cout << value << " successfully inserted at " << position << "-th position of the circular linklist." << endl;
                break;

            case 4:
                list.deleteBeginning();
                cout << "Deleted successfully from beginning of the circular linklist." << endl;
                break;

            case 5:
                list.deleteEnd();
                cout << "Deleted successfully from end of the circular linklist." << endl;
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                cout << "Deleted successfully from " << position << "-th position of the circular linklist." << endl;
                break;

            case 7:
                list.display();
                break;

            case 8:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

