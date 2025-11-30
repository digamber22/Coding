/*
 // TC ->O(n Log n) , SC -> O(n);   

⭐ Interview Answer: What is Merge Sort?

“Merge Sort is a divide-and-conquer sorting algorithm. It works by repeatedly splitting the array
 into two halves until each subarray contains a single element. Then, it merges these smaller sorted
  parts back together in a way that maintains sorted order. Because merging two sorted lists is efficient,
   the overall algorithm is very fast and stable. 
   
   Merge Sort consistently runs in O(n log n) time in all
    cases — best, average, and worst — and it is widely used when predictable performance is required.
     However, it needs extra memory for the temporary arrays used during merging, 
     so its space complexity is O(n).”
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to merge two halves of the array
    void merge(vector<int>& arr, int low, int mid, int high) {
        // Create temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        // Copy remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy sorted elements back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    // Recursive merge sort function
    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high)
            return;

        // Find the middle index
        int mid = (low + high) / 2;

        // Recursively sort left half
        mergeSort(arr, low, mid);

        // Recursively sort right half
        mergeSort(arr, mid + 1, high);

        // Merge the two sorted halves
        merge(arr, low, mid, high);
    }
};

int main() {
    vector<int> arr = {5, 2, 8, 4, 1};
    Solution sol;
    sol.mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}