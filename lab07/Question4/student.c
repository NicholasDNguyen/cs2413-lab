/*
Question 4: Insertion Sort

Description:
Implement insertion sort for an integer array.

Insertion sort builds the sorted portion of the array one element at a time.
For each element, it inserts that element into the correct position among
the elements before it.

The function should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- Do not use any built-in sorting function.
*/

void insertionSort(int arr[], int size) {
    // If the array is empty or has only one element, do nothing
    if (size <= 1) {
        return;
    }

    // Start from the second element because the first element is already "sorted"
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one position to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key into its correct position
        arr[j + 1] = key;
    }
}
