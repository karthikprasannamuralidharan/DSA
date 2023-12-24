#include<iostream>

using namespace std;

class BubbleSort {
private:
    int *arr;  // Pointer to the array to be sorted
    int size;  // Size of the array

public:
    // Constructor
    BubbleSort(int arr[], int n) {
        this->arr = arr;  // Assign the array pointer to the member variable
        this->size = n;   // Assign the size of the array to the member variable
    }

    // Other member functions for BubbleSort class can be added here



    // Function to perform bubble sort
    void performBubbleSort() {
        // Outer loop controls the number of passes through the array
        for(int i = 0; i < size - 1; i++) {
            // Inner loop controls the comparisons and swaps in each pass
            for(int j = 0; j < size - 1 - i; j++) {
                // Compare adjacent elements and swap them if they are in the wrong order
                if(arr[j] > arr[j + 1]) {
                    // Swap elements using a temporary variable
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }


    // Function to display the sorted array
    void displaySortedArray() {
        // Print a label indicating that the following numbers are from the sorted array
        cout << "Sorted Array: ";

        // Loop through each element in the array
        for(int i = 0; i < size; i++) {
            // Print the current element followed by a space
            cout << arr[i] << " ";
        }

        // Move to the next line after printing all elements
        cout << endl;
    }

};

int main() {
    int n;

    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // Get array elements from the user
    cout << "Enter the elements of the array:" << endl;
    for (int &it : arr) {
        cin >> it;
    }

    cout << "Unsorted Array: ";
    for(int &i : arr){
        cout << i << " ";
    }
    cout << endl;

    BubbleSort bubbleSortObject(arr, n);

    // Perform bubble sort
    bubbleSortObject.performBubbleSort();

    // Display the sorted array
    bubbleSortObject.displaySortedArray();

    return 0;
}
