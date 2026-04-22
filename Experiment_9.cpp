#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node* createTree() {
        int value;
        cout << "Enter node value (-1 for no node): ";
        cin >> value;

        if (value == -1)
            return NULL;

        Node* newNode = new Node(value);

        cout << "Enter left child of " << value << endl;
        newNode->left = createTree();

        cout << "Enter right child of " << value << endl;
        newNode->right = createTree();

        return newNode;
    }

    void preorder(Node* root) {
        if (root == NULL)
            return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root) {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(Node* root) {
        if (root == NULL)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main() {
    BinaryTree bt;
    Node* root = NULL;
    int choice;

    do {
        cout << "\n--- Binary Tree Menu ---";
        cout << "\n1. Create Tree";
        cout << "\n2. Preorder Traversal";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\nCreate Binary Tree\n";
                root = bt.createTree();
                break;

            case 2:
                cout << "Preorder Traversal: ";
                bt.preorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Inorder Traversal: ";
                bt.inorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal: ";
                bt.postorder(root);
                cout << endl;
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