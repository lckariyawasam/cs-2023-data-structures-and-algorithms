#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

//Swap function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min_idx])
              min_idx = j;
        }
        // Swap the found minimum element
        // with the first element
        if (min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
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
        selectionSort(arr, length);

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