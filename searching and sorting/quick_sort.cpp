// take the first element and place it in its actual place after that arrange the small element on its left and big element
// on the right side of that element. and then sort the both sides.
#include <iostream>
#include <vector>
using namespace std;

void quick_sort(std::vector<int> &v, int start, int end) {
    if (start >= end) // Base case: if the range is invalid or contains only one element
        return;

    int pivot = v[start]; // Select the pivot element as the first element of the range
    int i = start + 1; // Initialize the left pointer
    int j = end; // Initialize the right pointer

    while (i <= j) {
        while (i <= j && v[i] <= pivot) // Move the left pointer to find an element greater than the pivot
            i++;
        while (i <= j && v[j] > pivot) // Move the right pointer to find an element smaller than or equal to the pivot
            j--;
        if (i < j) // Swap elements if both pointers have not crossed each other
            std::swap(v[i], v[j]);
    }

    // Place the pivot in its correct position
    std::swap(v[start], v[j]);

    // Recursively sort the left and right subarrays
    quick_sort(v, start, j - 1);
    quick_sort(v, j + 1, end);
}

int main()
{
    vector<int> arr = {7, 6, 3, 5, 1, 9, 8};
    cout << "sorted array is -> ";
    quick_sort(arr, 0, arr.size());
    for(int i= 0; i < arr.size(); i++){
        cout << arr[i] <<" ";
    }
}