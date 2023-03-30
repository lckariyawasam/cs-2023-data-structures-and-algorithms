#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    for (int i = 0; i < 5; ++i) { 
      // generate 5 arrays
        cout << "Enter length of array : ";
        int length ;
        cin >> length;
      // choose a random length between 3 and 20
        int arr[length];
        for (int j = 0; j < length; ++j) {
            arr[j] = rand() % 1001;  // generate random integers between 0 and 100
        }

        // Record the start time
        auto start_time = chrono::high_resolution_clock::now();

        // Sort the array
        insertion_sort(arr, length);

        // Record the end time
        auto end_time = chrono::high_resolution_clock::now();

        // Compute the elapsed time in microseconds
        double time_taken = chrono::duration_cast<chrono::duration<double> >(end_time - start_time).count() ;

        // Print the sorted array and the time taken in microseconds
        cout << "Array" << i+1 << " sorted in " << fixed << setprecision(10)<< time_taken << " microseconds"<< endl;
        cout << "Array length : "<< length<<endl;
    }

    return 0;
}