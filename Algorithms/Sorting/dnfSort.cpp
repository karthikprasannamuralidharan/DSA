#include<iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void dnfSort(int *arr, int n) {
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int size;
    cout << "Enter size of an array: ";
    cin >> size;

    int array[size];
    cout << "Enter elements in array: " << endl;
    for (auto &i : array) {
        cin >> i;
    }

    cout << "Unsorted array is: ";
    for (auto i : array) {
        cout << i << " ";
    }

    dnfSort(array, size);

    cout << "\nDNF-Sorted array is: ";
    for (auto i : array) {
        cout << i << " ";
    }

    return 0;
}
