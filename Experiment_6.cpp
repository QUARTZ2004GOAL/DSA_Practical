#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear;
    int size;

public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void enqueue(int x) {
        if (rear == size - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = x;
        cout << "Inserted: " << x << endl;
    }
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Deleted: " << arr[front] << endl;
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
    void peek() {
        if (front == -1) {
            cout << "Queue is Empty\n";
        } else {
            cout << "Front element is: " << arr[front] << endl;
        }
    }
    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter size of Queue: ";
    cin >> n;
    Queue q(n);
    int choice, value;
    do {
        cout << "\n1. Enqueue";
        cout <<"\n2. Dequeue";
        cout << "\n3. Peek";
        cout <<"\n4. Display";
        cout << "\n5. Exit";
        cout <<"\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout <<"Enter value: ";
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

    } while (choice != 5);

    return 0;
}