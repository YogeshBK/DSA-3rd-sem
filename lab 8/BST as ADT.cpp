#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void deleteNodeFromRoot() {
        if (root != NULL) {
            int deletedValue = root->data;
            root = deleteNode(root, root->data);
            cout << deletedValue << " is deleted from the Root node." << endl;
        } else {
            cout << "Tree is empty." << endl;
        }
    }

    void deleteNodeFromEnd() {
        if (root != NULL) {
            int deletedValue = findEndValue(root);
            root = deleteFromEnd(root);
            cout << deletedValue << " is deleted from the end (leaf node)." << endl;
        } else {
            cout << "Tree is empty." << endl;
        }
    }

    void deleteNodeSpecific(int value) {
        if (search(value)) {  // Check if the value exists
            root = deleteNode(root, value);
            cout << "Value " << value << " deleted from the BST." << endl;
        } else {
            cout << "Value " << value << " not found in the BST. No deletion performed." << endl;
        }
    }

    void displayBST() {
        inorder(root);
        cout << endl;
    }

private:
    Node* insert(Node* root, int value) {
        if (root == NULL) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }

        return root;
    }

    bool search(Node* root, int value) {
        if (root == NULL) return false;
        if (root->data == value) return true;

        if (value < root->data) return search(root->left, value);
        return search(root->right, value);
    }

    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    Node* deleteNode(Node* root, int value) {
        if (root == NULL) return root;

        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    Node* deleteFromEnd(Node* root) {
        if (root == NULL) return NULL;

        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        if (root->right != NULL) {
            root->right = deleteFromEnd(root->right);
        } else if (root->left != NULL) {
            root->left = deleteFromEnd(root->left);
        }

        return root;
    }

    int findEndValue(Node* root) {
        if (root == NULL) return -1;

        Node* current = root;
        while (current->right != NULL) {
            current = current->right;
        }
        return current->data;
    }
};

int main() {
    BST tree;
    int choice, value, searchValue, numValues;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insert a value into the BST" << endl;
        cout << "2. Search for a value in the BST" << endl;
        cout << "3. Display BST (In-order)" << endl;
        cout << "4. Delete from root" << endl;
        cout << "5. Delete from end (leaf node)" << endl;
        cout << "6. Delete specific value from BST" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of values to insert: ";
                cin >> numValues;
					cout << "Enter value to insert: ";
                for (int i = 0; i < numValues; i++) {
                    
                    cin >> value;
                    tree.insert(value);
                   
                }
                cout<<"values succcesfully inserted into the BST"<<endl;
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> searchValue;
                if (tree.search(searchValue)) {
                    cout << "Value " << searchValue << " found in BST." << endl;
                } else {
                    cout << "Value " << searchValue << " not found in BST." << endl;
                }
                break;

            case 3:
                cout << "Binary Search Tree (In-order): ";
                tree.displayBST();
                break;

            case 4:
                tree.deleteNodeFromRoot();
                break;

            case 5:
                tree.deleteNodeFromEnd();
                break;

            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteNodeSpecific(value);
                break;

            case 7:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}

