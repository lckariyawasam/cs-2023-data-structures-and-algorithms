#include <iostream>
#include <iomanip>
using namespace std;

void mergesort_recursive(int arr[], int p, int r);

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
        auto start_time = chrono::high_resolution_clock::now();

        mergesort_recursive(arr, 0, size - 1);

        // Record the end time
        auto end_time = chrono::high_resolution_clock::now();

        // Compute the elapsed time in microseconds
        double time_taken = chrono::duration_cast<chrono::duration<double> >(end_time - start_time).count() ;

        cout << "Array size: " << size << " sorted in " << fixed << setprecision(10)<< time_taken << " microseconds | Recursive"<< endl;
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

void mergesort_recursive(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergesort_recursive(arr, left, mid);
        mergesort_recursive(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}