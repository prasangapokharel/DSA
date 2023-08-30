#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted arrays
void merge(vector<int>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    // Create temp arrays to store the two halves
    vector<int> L(n1), R(n2);
  
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    // Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to sort an array using merge sort
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Calculate mid point of array
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Main function to test the above functions
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
  
    int arr_size = arr.size();
  
    cout << "Given array is \n";
    for(auto &num : arr) {
        cout << num << " ";
    }
    cout << endl;
  
    mergeSort(arr, 0, arr_size - 1);
  
    cout << "Sorted array is \n";
    for(auto &num : arr) {
        cout << num << " ";
    }
    cout << endl;
  
    return 0;
}
