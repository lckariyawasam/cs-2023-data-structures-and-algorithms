#include <iostream>
#include <iomanip>
using namespace std;

void quicksort_recursive(int arr[], int left, int right);
void quicksort_iterative(int arr[], int left, int right);

int main(void) {
    
    // Seed the random number generator with the current time
    srand(time(NULL));

    //Run the algorithm and get the times for different sized arrays
    for (int size = 10; size <= 10000; size *= 10) {

        int arr[size];
        int arr_duplicate[size];

        //Populate the arrays with random values
        for (int i = 0; i < size; i++) {
            int value = rand() % 1001;
            arr[i] = arr_duplicate[i] =  value;
        }


        // Record the start time
        auto start_time = chrono::high_resolution_clock::now();

        quicksort_recursive(arr, 0, size-1);

        // Record the end time
        auto end_time = chrono::high_resolution_clock::now();

        // Compute the elapsed time in microseconds
        double time_taken = chrono::duration_cast<chrono::duration<double> >(end_time - start_time).count() ;

        cout << "Array size: " << size << " sorted in " << fixed << setprecision(10)<< time_taken << " microseconds | Recursive Quicksort"<< endl;



        // Record the start time
        auto start_time_2 = chrono::high_resolution_clock::now();

        quicksort_iterative(arr_duplicate, 0, size-1);

        // Record the end time
        auto end_time_2 = chrono::high_resolution_clock::now();

        // Compute the elapsed time in microseconds
        double time_taken_2 = chrono::duration_cast<chrono::duration<double> >(end_time_2 - start_time_2).count() ;

        cout << "Array size: " << size << " sorted in " << fixed << setprecision(10)<< time_taken_2 << " microseconds | Iterative Quicksort"<< endl;
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int left, int right) {
    // The the last element as the pivot
    int pivot = arr[right];

    // Initialize i
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    //Finally swap the pivot element into the correct position
    i++;
    swap(&arr[i], &arr[right]);

    // Return the position of the pivot element
    return i;

}

void quicksort_recursive(int arr[], int left, int right) {
    if (right > left) {
        int pivot = partition(arr, left, right);
        quicksort_recursive(arr, left, pivot - 1);
        quicksort_recursive(arr, pivot + 1, right);
    }
}

void quicksort_iterative(int arr[], int left, int right) {

    // Initialize a stack to hold the start and end indexes of each subarray
    int stack[right - left + 1];

    // Initialize top to -1
    int top = -1;

    // Push the left and right into the stack
    stack[++top] = left;
    stack[++top] = right;


    while (top >= 0) {
        // Pop the items off the stack
        right = stack[top--];
        left = stack[top--];

        // Partition the array and get the pivot index
        int pindex = partition(arr, left, right);

        // If there are elements to the left of the pivot, add it to the stack to be sorted
        if (pindex - 1 > left) {
            stack[++top] = left;
            stack[++top] = pindex - 1; 
        }

        // If there are elements to the right of the pivot, add it to the stack to be sorted
        if (pindex < right) {
            stack[++top] = pindex + 1;
            stack[++top] = right;
        }
    }
}

