#include <iostream>
#include <iomanip>
using namespace std;

void mergesort_iterative(int arr[], int n);

int main(void) {
    srand(time(NULL));
    for (int size = 10; size <= 10000; size *= 10) {

        int arr[size];
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 1001;
        }
        int length = sizeof(arr);


        //Print the sorted array
        // cout << "size " << size << " ||  " ;
        // for (int i = 0; i < size; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;


        // Record the start time
        auto start_time_2 = chrono::high_resolution_clock::now();

        mergesort_iterative(arr, size);

        // Record the end time
        auto end_time_2 = chrono::high_resolution_clock::now();

        // Compute the elapsed time in microseconds
        double time_taken_2 = chrono::duration_cast<chrono::duration<double> >(end_time_2 - start_time_2).count() ;

        cout << "Array size: " << size << " sorted in " << fixed << setprecision(10)<< time_taken_2 << " microseconds | Iterative"<< endl;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1+1], R[n2+1];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    L[n1] = INT_MAX; 

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    R[n2] = INT_MAX;

    int i = 0;
    int j = 0;

    for(int k = left; k <= right; k++) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }
}

void mergesort_iterative(int arr[], int n) {
    int curr_size;
    int left_start;

    for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
    {
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           // Find ending point of left subarray. mid+1 is starting
           // point of right
           int mid = left_start + curr_size - 1;
           if (mid > n - 1) {
            mid = n - 1;
           }
 
           int right_end = left_start + 2*curr_size - 1;
           if (right_end > n - 1) {
                right_end = n - 1;
           } 
 
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
           merge(arr, left_start, mid, right_end);
       }
   }

}