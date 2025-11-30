/*
// TC -> O(n log n ), worst case TC --> O(n^2) ,  SC -> O(1) , but recusive extra space also . 

⭐ Interview Answer: What is Quick Sort?

“Quick Sort is a fast and widely used sorting algorithm based on the divide-and-conquer approach.
 The idea is to pick a pivot element from the array and then partition the remaining elements into
  two groups — those smaller than the pivot and those greater than it. After this partitioning,
   the pivot moves to its correct sorted position. We then recursively apply the same process on the left
   and right subarrays. Quick Sort is very efficient on average with a time complexity of O(n log n),
    but in the worst case — when the pivot is consistently chosen poorly — it can degrade to O(n²).
     However, in practice, it performs extremely well and uses only O(log n) space due to recursion.”

     “Yes, the worst case commonly happens when the input array is already sorted and the pivot selection is poor,
      such as always picking the first or last element.”

      Partition Step: O(n)

Recursion Depth: O(log n) on average

Total Time Complexity:
Average: O(n log n)
Best: O(n log n)
Worst: O(n²) (poor pivot selection)

Space Complexity:
Average: O(log n)
Worst: O(n) (skewed recursion)
Algorithm Type: In-place, Not Stable, Divide-and-Conquer
*/


class Solution {
public:

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1)
            i++;

        while (arr[j] > pivot && j >= low + 1)
            j--;

        if (i < j) 
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

    vector<int> quickSort(vector<int>& arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

};
