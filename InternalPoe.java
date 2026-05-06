// Q . Write a program to sort  an array using  Merge Sort . Take input an array from  the user . 
import java.util.Scanner;

class MergeSortMenu {

    int arr[];
    int n;

    public void createArray() {
       Scanner sc = new Scanner(System.in);
     System.out.print("Enter number of elements: ");
     n = sc.nextInt();

        arr = new int[n];
    System.out.println("Enter elements:");
      for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
    }

    public void display() {
        if (arr == null) {
            System.out.println("Array not created!");
            return;
        }

     System.out.println("Array elements:");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public void merge(int arr[], int low, int mid, int high) {
        int temp[] = new int[high - low + 1];

      int i = low;
      int j = mid + 1;
        int k = 0;

     while (i <= mid && j <= high) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

      while (i <= mid) {
            temp[k++] = arr[i++];
        }

      while (j <= high) {
            temp[k++] = arr[j++];
        }

        for (int x = 0; x < temp.length; x++) {
            arr[low + x] = temp[x];
        }
    }

    public void mergeSort(int arr[], int low, int high) {
        if (arr == null) {
            System.out.println("Array not created!");
            return;
        }
        if (low < high) {
            int mid = (low + high) / 2;

            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }
   
}

public class  InternalPoe{
	
	public static void main(String[] args){
	MergeSortMenu obj = new MergeSortMenu(); 
	MergeSortMenu obj2 = new MergeSortMenu() ; 
	Scanner sc = new Scanner(System.in);
	int choice = 0; 
	
	do{
		System.out.println("\n---MergeSort Menu --- \n1.Create Array \n2.display Array \n3.MergeSort \n4.exit  ");
		System.out.print("Enter the Choice :");
		choice = sc.nextInt(); 
		

		
		switch(choice ){
			case 1 : obj.createArray(); break ; 
			case 2 : obj.display(); break ; 
			case 3 : obj.mergeSort(obj.arr , 0 , obj.n-1) ;  break ; 
			case 4 : System.out.println("Exiting the program ! "); break ; 
			default : System.out.println("Invalid input"); break ;
				
		}

	}while(choice != 4);

}

}
