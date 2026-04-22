#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Inserted: " << value << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        cout << "Deleted: " << temp->data << endl;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void peek() {
        if (front == NULL) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Front element is: " << front->data << endl;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << "Program Ended\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 5);

    return 0;
}