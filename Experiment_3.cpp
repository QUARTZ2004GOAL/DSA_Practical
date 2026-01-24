#include<iostream>
using namespace std ;

void display(int arr[] , int length ){
    cout<<"Array Entered :"<<endl ;
    for(int i =0 ; i<length ; i++){
        cout<<arr[i]<<" ";
    }

}

void linear_search(int arr[] , int length , int search_ele){
    bool ispresent = false ;
    for(int i = 0 ; i<length ; i++){
        if(arr[i] == search_ele){
            ispresent = true;
            cout<<"Element is present at index "<<i <<endl ;
            break;
        }
    }
     if(!ispresent){
            cout<<"Element is not present in array !"<<endl;
    }
}

void binary_search(int arr[] , int length , int search_ele){
    bool ispresent = false ;
    int start = 0 ; 
    int end = length ;
    while(start <= end){
        int mid = (start+end) /2 ;
       
        if(arr[mid] == search_ele){
            cout<<"Element is present at index "<< mid <<endl ;
            ispresent = true;
            break;
        }else if(search_ele < arr[mid]){
            end = mid-1;
        }else {
            start = mid+1;
        }


    }
    if(!ispresent){
        cout<<"Elemtent is not present in array !"<<endl;
    }

}

int main(){
    int length ; 
    cout<< "Enter the length of array ";
    cin>> length;
    int arr[length];

    cout<<"Enter the array element :"<<endl ;
    for(int i = 0 ; i< length ; i++){
        cin>> arr[i] ;
    }

    int search_ele ; 
    cout<<"Enter the elemnet you want to search : ";
    cin>>search_ele;

    int choice ;
    char repeat ; 
    do{
        cout<< "\n---MENUE----\n";
        cout<< "0. Display array \n" 
            << "1. Linear Search \n"
            << "2. Binary Search \n"
            <<  "3. Exit \n";
        cout<<"Enter your choice :";
        cin>> choice ;

        switch(choice){
            case 0 : display(arr,length) ; break;
            case 1 : linear_search(arr , length , search_ele) ; break;
            case 2 : binary_search(arr, length , search_ele); break;
            default :
                cout<<"Invalid Input !";
        }
         cout << "\nDo you want to continue? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0 ;

}