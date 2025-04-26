#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* queue;
    int capacity;

public:
    Queue(int cap) {
        capacity = cap;
        front = size = 0;
        rear = capacity - 1;
        queue = new int[capacity];
    }


    bool isFull() {
        return (size == capacity);
    }

    bool isEmpty() {
        return (size == 0);
    }

    void insert(int item) {
        if (isFull()) {
            cout << "Queue is full, cannot insert item: " << item << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = item;
        size++;
        cout << item << " inserted to queue\n";
    }

    int Delete() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot Delete item\n";
            return INT_MIN;
        }
        int item = queue[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    Queue q(capacity);
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. insert\n";
        cout << "2. Delete\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.insert(value);
                break;
            case 2:
                value = q.Delete();
                if (value != INT_MIN) {
                    cout << value << " Deleteped from queue\n";
                }
                break;
            case 3:
                if (q.isEmpty()) {
                    cout << "Queue is empty\n";
                } else {
                    cout << "Queue is not empty\n";
                }
                break;
            case 4:
                if (q.isFull()) {
                    cout << "Queue is full\n";
                } else {
                    cout << "Queue is not full\n";
                }
                break;
            case 5:
                q.display();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice, please try again\n";
        }
    }
}
