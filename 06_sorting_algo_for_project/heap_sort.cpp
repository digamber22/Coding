/*
TC -> O(n log n ), SC -> O(1); 

⭐ Interview Answer: What is Heap Sort ?

“Heap Sort is a comparison-based sorting algorithm that uses a special binary tree structure called a heap 
to efficiently sort elements. The algorithm works in two main steps: First, it builds a max-heap from the
 input array, where the largest element is always at the root. Then, it repeatedly swaps the root with the 
 last element of the heap and reduces the heap size. After each swap, the heap property is restored by heapifying
  the remaining elements. Over multiple iterations, the largest elements move to the end one by one, eventually
   producing a fully sorted array. Heap Sort always runs in O(n log n) time, regardless of the input order, 
   and it works in-place using only O(1) extra space. It is efficient, predictable, but not stable.”


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
