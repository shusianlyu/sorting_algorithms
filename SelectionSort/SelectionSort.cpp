// This program sorts an array using selection sort.
// The selection sort algorithm sorts an array by repeatedly
// finding the minimum element (considering ascending order)
// from unsorted part and putting it at the beginning.
// The algorithm maintains two subarrays in a given array.
// Time Complexity: O(n^2)
// Anxiliary Space: O(1)

#include <iostream>
using namespace std;

void swap(int *firstP, int *secondP);
void selectionSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int arr[] = {435, 543, 33, 56, 74, 34, 544};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original Array: ";
    printArray(arr, n);
    selectionSort(arr, n);
    cout << "Sorted Array: ";
    printArray(arr, n);
}

void swap(int *firstP, int *secondP){
    int temp = *firstP;
    *firstP = *secondP;
    *secondP = temp;
}
void selectionSort(int arr[], int n){
    
    for(int i = 0; i < n - 1; i++){
        int miniIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[miniIndex] > arr[j])
                miniIndex = j;
        }
        swap(&arr[miniIndex], &arr[i]);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/**
 Output:
 Original Array: 435 543 33 56 74 34 544
 Sorted Array: 33 34 56 74 435 543 544
 Program ended with exit code: 0
 */
