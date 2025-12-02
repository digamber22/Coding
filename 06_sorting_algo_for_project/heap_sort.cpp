/*
TC -> O(n log n ), SC -> O(1); 

⭐ Interview Answer: What is Heap Sort ?

Heap Sort is a comparison-based sorting algorithm that uses a special binary tree structure called a heap
 to sort elements efficiently.The algorithm works in mainly two steps : 

Step 1: Build a Max-Heap
In the beginning, the algorithm converts the entire input array into a max-heap, where the largest element 
is always at the root of the heap. This structure helps us easily access the maximum value in constant time.

Step 2: Repeatedly Remove the Maximum & Restore Heap
Once the max-heap is built, the algorithm starts sorting by swapping the root (largest element) with the last
 element of the heap. After this swap, the heap size is reduced by one since the last element is now in its
 correct sorted position.
To maintain the heap property, the algorithm then heapifies the remaining elements—this ensures that the 
next largest element moves to the root.

This process is repeated again and again. Each iteration places the next largest element at the end of the 
array, slowly forming the sorted sequence.

Over these repeated operations, all elements eventually move to their correct positions, producing a fully sorted array.

 Build Heap: O(n)
 Heapify each time: O(log n)
 Total Time Complexity: O(n log n) (best, average, worst)
 Space Complexity: O(1) (in-place)
 Algorithm Type: In-place, Not Stable, Comparison-Based

*/

#include <bits/stdc++.h>
using namespace std;

// Heapify function – ensures max-heap property
void heapify(vector<int> &arr, int n, int i) {

    int largest = i;          // root
    int left = 2*i + 1;       // left child
    int right = 2*i + 2;      // right child

    // check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if root is not largest, swap and continue heapifying
    if (largest != i) {
        
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Step 1: Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);     // move largest to the end
        heapify(arr, i, 0);       // heapify the reduced heap
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2};
    heapSort(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}
