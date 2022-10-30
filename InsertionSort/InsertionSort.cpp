// This program sorts array using insertion sort.
// Insertion Sort: a simple sorting algorithm that
// works similar to the way you sort playing cards
// in your hands. The array is virtually split into
// a sorted and an unsorted part. Values from the
// unsorted part are picked and placed at the correct
// position in the sorted part. Insertions sort is stable.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <iostream>

using namespace std;

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int arr[] = {12, 34, 54, 33, 52, 33, 78, 86};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original Array: ";
    printArray(arr, n);
    insertionSort(arr, n);
    cout << "Sorted Array: ";
    printArray(arr, n);
    
}

void insertionSort(int arr[], int n){
    
    for(int i = 0; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/**
 Output:
 Original Array: 12 34 54 33 52 33 78 86
 Sorted Array: 12 33 33 34 52 54 78 86
 Program ended with exit code: 0
 */
