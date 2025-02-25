#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

class DoublyCircular {
private:
    Node* head;

public:
   DoublyCircular() {
        head = NULL;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }

    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* temp = head->prev;
            newNode->next = head;
            newNode->prev = temp;
            temp->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtPosition(int value, int position) {
        if (position == 1) {
            insertBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        int count = 1;

        while (temp != NULL && count < position - 1) {
            temp = temp->next;
            count++;
            if (temp == head) break;
        }

        if (temp == NULL || temp->next == head) {
            cout << "Position is out of bounds, inserting at the end." << endl;
            insertEnd(value);
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    void deleteBeginning() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            Node* last = head->prev;
            head = head->next;
            head->prev = last;
            last->next = head;
            delete temp;
        }
    }

    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;
        delete temp;
    }

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
        int count = 1;

        while (temp != NULL && count < position) {
            temp = temp->next;
            count++;
            if (temp == head) break;
        }

        if (temp == head || temp == NULL) {
            cout << "Position is out of bounds." << endl;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyCircular list;
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
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertEnd(value);
                cout << value << " successfully inserted at the end." << endl;
                break;

            case 2:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertBeginning(value);
                cout << value << " successfully inserted at the beginning." << endl;
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(value, position);
                cout << value << " successfully inserted at " << position << "-th position ." << endl;
                break;

            case 4:
                list.deleteBeginning();
                cout << "Deleted successfully from the beginning." << endl;
                break;

            case 5:
                list.deleteEnd();
                cout << "Deleted successfully from the end." << endl;
                break;

            case 6:
                cout << "Enter  the position to delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                cout << "Deleted successfully from " << position << "-th position ." << endl;
                break;

            case 7:
                list.display();
                break;

            case 8:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
};

