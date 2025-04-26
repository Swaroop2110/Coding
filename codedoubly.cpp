#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    // Insert a new node
    void insert(int key) {
        root = insertRec(root, key);
    }

    // Delete a node
    void deleteNode(int key) {
        if (search(key) == nullptr) {
            cout << "Element " << key << " not found in the tree. Cannot delete." << endl;
            return;
        }
        root = deleteRec(root, key);
    }

    // Search for a node
    Node* search(int key) {
        return searchRec(root, key);
    }

private:
    Node* root;

    Node* insertRec(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insertRec(node->left, key);
        } else if (key > node->key) {
            node->right = insertRec(node->right, key);
        }
        return node; // return the unchanged node pointer
    }

    Node* deleteRec(Node* node, int key) {
        if (node == nullptr) {
            return node;
        }
        if (key < node->key) {
            node->left = deleteRec(node->left, key);
        } else if (key > node->key) {
            node->right = deleteRec(node->right, key);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(node->right);
            node->key = temp->key; // Copy the inorder successor's content to this node
            node->right = deleteRec(node->right, temp->key); // Delete the inorder successor
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* searchRec(Node* node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return searchRec(node->left, key);
        }
        return searchRec(node->right, key);
    }
};

int main() {
    BinarySearchTree bst;
    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                bst.deleteNode(value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (bst.search(value)) {
                    cout << value << " found in the tree." << endl;
                } else {
                    cout << value << " not found in the tree." << endl;
                }
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}
