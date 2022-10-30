// This program optimized bubble sort by stopping the
// algorithm if inner loop did'n cause any swap.
// Bubble Sort: the simplest sorting algorithm that
// works by repeatedly swapping the adjacent elements
// if they are in wrong order.

#include <iostream>

using namespace std;

void swap(int *firstP, int *secondP);
void BubbleSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int arr[] = {9, 5, 3, 11, 23, 43, 54};
    // get number of element in array using sizeof
    // ints are 4 bytes long, so sizeof(arr) will be 28
    // but we need to divide the total size by how
    // many bytes one element takes
    int numberOfElements = sizeof(arr)/sizeof(arr[0]);
    cout << "Original Array: ";
    printArray(arr, numberOfElements);
    BubbleSort(arr, numberOfElements);
    cout << "Sorted Array: ";
    printArray(arr, numberOfElements);
    return 0;
}

void swap(int *firstP, int *secondP){
    // swap the elements if needed.
    int temp = *firstP;   // deference the pointer to get the value
    *firstP = *secondP;
    *secondP = temp;
}

void BubbleSort(int arr[], int n){
    bool swapped;
    // compare each
    for(int i = 0; i < n - 1; i++){
        // last i elements are alreay in place
        swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        // if no two elements were swapped by inner loop,
        // then use break to jump out the loop
        if(swapped == false)
            break;
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/**
 Output:
 Original Array: 9 5 3 11 23 43 54
 Sorted Array: 3 5 9 11 23 43 54
 Program ended with exit code: 0
 */
