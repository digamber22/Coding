/*
// TC -> O(N^2), SC -> O(1) ; 
⭐ Interview Answer: What is Bubble Sort?  

“Bubble Sort is a simple comparison-based sorting algorithm where we repeatedly scan 
through the list and compare adjacent elements. If any two elements are in the wrong 
order, we swap them. This process continues for multiple passes until the entire list
 becomes sorted. The reason it's called ‘Bubble Sort’ is because in each pass, the largest 
 element gradually ‘bubbles up’ to the end of the array, just like a bubble rising to the top. 
 Even though Bubble Sort is easy to understand and implement, it is inefficient for large datasets 
 because its worst-case and average time complexity is O(n²). However, it’s commonly used for 
 teaching the basics of sorting and algorithm analysis.”
*/

#include <bits/stdc++.h>
using namespace std;

class BubbleSort {
public:
    void bubble_sort(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {  //Use two nested loops to iterate over the array
            for (int j = 0; j <= i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]); //Swap arr[i] with arr[j+1]
                }
            }
        }
        cout << "After Using Bubble Sort:\n";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {13, 46, 24, 52, 20, 9};

    cout << "Before Using Bubble Sort:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    BubbleSort sorter;
    sorter.bubble_sort(arr);

    return 0;
}