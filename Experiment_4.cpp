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

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSortHelper(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge_sort(int arr[], int length) {
    mergeSortHelper(arr, 0, length - 1);
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quick_sort(int arr[], int length) {
    quickSortHelper(arr, 0, length - 1);
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
        cout << " 4. Merge sort\n";
        cout << " 5. Quick sort\n";
        cout << " 6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0: display(arr, length); break;
            case 1: bubble_sort(arr, length); break;
            case 2: selection_sort(arr, length); break;
            case 3: insertion_sort(arr, length); break;
            case 4: merge_sort(arr, length); break ; 
            case 5: quick_sort(arr,length); break ;
            case 6: cout << "Exiting....."; break;
            default: cout << "Invalid input!";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
