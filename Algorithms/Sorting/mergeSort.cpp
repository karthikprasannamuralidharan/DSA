#include<iostream>

using namespace std;

void merge(int *arr, int low, int mid, int high) {
    int size1 = mid - low + 1;
    int size2 = high - mid;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    for (int i = 0; i < size1; i++) {
        arr1[i] = arr[low + i];
    }

    for (int i = 0; i < size2; i++) {
        arr2[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < size2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }

    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int *arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
    int size;
    cout << "Enter size of an array: ";
    cin >> size;

    int *array = new int[size];

    cout << "Enter elements in array: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    cout << "Unsorted array is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    mergeSort(array, 0, size - 1);

    cout << "\nMerge-Sorted array is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    delete[] array;

    return 0;
}
