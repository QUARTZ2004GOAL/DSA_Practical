#include<iostream>
using namespace std;

void bubble_sort(int arr[], int length) {
    bool isSorted = true;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                isSorted = false;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (isSorted) {
            cout << "Array is already sorted" << endl;
            break;
        }
    }
}

void selection_sort(int arr[], int length) {
    bool isSorted = true;
    for (int i = 0; i < length - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[minIndex]) {
                isSorted = false;
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
         if (isSorted) {
        cout << "Array is already sorted" << endl;
        break;
    }
    }
   
}

void insertion_sort(int arr[], int length) {
    bool isSorted = true;
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            isSorted = false;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        if (isSorted) {
        cout << "Array is already sorted" << endl;
        break;
    }
    }
    
}

void display(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int length;
    cout << "Enter the length of array: ";
    cin >> length;

    int arr[length];
    cout << "Enter the array elements:\n";
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    int choice;
    char repeat;
    do {
        cout << "\n----MENU----\n";
        cout << " 0. Display\n";
        cout << " 1. Bubble sort\n";
        cout << " 2. Selection sort\n";
        cout << " 3. Insertion sort\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0: display(arr, length); break;
            case 1: bubble_sort(arr, length); break;
            case 2: selection_sort(arr, length); break;
            case 3: insertion_sort(arr, length); break;
            case 4: cout << "Exiting....."; break;
            default: cout << "Invalid input!";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
