#include<iostream>

using namespace std;

void waveSort(int *arr, int n){
    for(int i=1; i<n-1; i+=2){
        if(arr[i] > arr[i-1]){
            swap(arr[i], arr[i-1]);
        }
        if(i <= n-2 && arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
}

int main() {
    int size;
    cout << "Enter size for array: ";
    cin >> size;

    int *array = new int[size];

    cout << "Enter elements in array: ";
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    cout << "Unsorted array is: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    waveSort(array, size);

    cout << "Wave-sorted array is: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;

    return 0;
}
