#include <bits/stdc++.h>
using namespace std;
class BinaryTree {
public:
    BinaryTree(int capacity) : capacity(capacity) {
        tree.resize(capacity, -1); 
    }
    void insert(int value) {
        if (size >= capacity) {
             cout << "Tree is full, cannot insert " << value <<  endl;
            return;
        }
        tree[size] = value;
        size++;
    }
    // In-order traversal
    void inOrder(int index) {
        if (index >= size || tree[index] == -1) return;
        inOrder(2 * index + 1);  // Left child
         cout << tree[index] << " "; // Current node
        inOrder(2 * index + 2);  // Right child
    }

    // Pre-order traversal
    void preOrder(int index) {
        if (index >= size || tree[index] == -1) return;
         cout << tree[index] << " "; // Current node
        preOrder(2 * index + 1);  // Left child
        preOrder(2 * index + 2);  // Right child
    }

    // Post-order traversal
    void postOrder(int index) {
        if (index >= size || tree[index] == -1) return;
        postOrder(2 * index + 1);  // Left child
        postOrder(2 * index + 2);  // Right child
         cout << tree[index] << " "; // Current node
    }

private:
     vector<int> tree;
    int size = 0;
    int capacity;
};

int main() {
    int capacity;
     cout << "Enter the capacity of the binary tree: ";
     cin >> capacity;
    
    BinaryTree bt(capacity);
    int choice, value;

    do {
         cout << "\nMenu:\n";
         cout << "1. Insert Node\n";
         cout << "2. In-Order Traversal\n";
         cout << "3. Pre-Order Traversal\n";
         cout << "4. Post-Order Traversal\n";
         cout << "5. Exit\n";
         cout << "Enter your choice: ";
         cin >> choice;

        switch (choice) {
            case 1:
                 cout << "Enter value to insert: ";
                 cin >> value;
                bt.insert(value);
                break;
            case 2:
                 cout << "In-order traversal: ";
                bt.inOrder(0); // Start from the root (index 0)
                 cout <<  endl;
                break;
            case 3:
                 cout << "Pre-order traversal: ";
                bt.preOrder(0);
                 cout <<  endl;
                break;
            case 4:
                 cout << "Post-order traversal: ";
                bt.postOrder(0);
                 cout <<  endl;
                break;
            case 5:
                 cout << "Exiting program.\n";
                break;
            default:
                 cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
