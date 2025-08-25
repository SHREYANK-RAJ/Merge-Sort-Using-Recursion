#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int start, int end) {
    int mid = start + (end - start) / 2;

    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    // temporary arrays
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    // copy data to temp arrays
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[start + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // merge both arrays
    int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // copy remaining elements
    while (i < leftSize) {
        arr[k++] = leftArr[i++];
    }
    while (j < rightSize) {
        arr[k++] = rightArr[j++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSortHelper(vector<int>& arr, int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;

    // sort both halves
    mergeSortHelper(arr, start, mid);
    mergeSortHelper(arr, mid + 1, end);

    // merge them back
    merge(arr, start, end);
}

void mergeSort(vector<int>& arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {9, 3, 1, 7, 5, 8, 2, 6};

    cout << "Before sorting: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    mergeSort(arr);

    cout << "After sorting: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
