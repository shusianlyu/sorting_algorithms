// This program sorts array using quick sort.
// It picks an element as pivot and partitions
// the given array around the picked pivot.
// Quick sort is not stable.
// Worse Case: O(n^2)
// (occur when the array is already sort in increasing or decreasing order)
// Best Case: O(nlogn)
// (occur whne picking the middle element as pivot)
// Average Case: O(nlogn)
// Space Complexity: O(logN)

#include <iostream>

using namespace std;
void swap(int *firstP, int *secondP);
int partition(int arr[], int low, int high);
void QuickSort(int arr[], int low, int high);
void printArray(int arr[], int n);

int main() {
    int arr[] = {12, 33, 43, 2, 63, 9, 32, 44, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original Array: ";
    printArray(arr, n);
    cout << "Sorted Array: ";
    QuickSort(arr, 0, n - 1);
    printArray(arr, n);
}

void swap(int *firstP, int *secondP){
    int temp = *firstP;
    *firstP = *secondP;
    *secondP = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;  // index of smaller element
    
    for(int j = low; j < high; j++){
        
        // if current element is smaller than pivot
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high){
    if(low < high){
        // pi is partition index, arr[pi] is now at right place
        int pi = partition(arr, low, high);
        
        // quick sort on the left
        QuickSort(arr, low, pi - 1);
        // quick sort on the right
        QuickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
}

/**
 Output:
 Original Array: 12 33 43 2 63 9 32 44 3
 Sorted Array: 2 3 9 12 32 33 43 44 63
 Program ended with exit code: 0
 */
