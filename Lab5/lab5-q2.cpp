#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double running_median(vector<int>& arr, int n);

int main (void) {
    int inputArray[] = {1,5,4,6,7,8};

    //Initialize a vector to store sorted stream
    vector<int> sorted;


    // Iterate through the inputArray and run the running_median function to simulate a data stream
    for (int i: inputArray) {
        double median = running_median(sorted, i);

        // Print the array to the console
        for(int i = 0; i < sorted.size(); i++) {
            cout << sorted[i] << " ";
        }

        //Print the median
        cout << "Median is " << fixed << setprecision(1) <<  median;
        cout << endl;


    }


}

double running_median(vector<int>& arr, int n) {

    //If the array is empty, add the element to the array and return its value since its the median
    if (arr.size() == 0) {
        arr.push_back(n);
        return n;
    }

    // Initialize index to get the index of the required position for n
    int index = -1;

    // Since the array is already sorted, check if the number is less than the elements in the array
    for (int i = 0; i < arr.size(); i++) {
        if (n <= arr[i]) {
            index = i;
            break;
        }
    }

    // If the index has not changed, (i.e. index == -1) it is greater than all the numbers in the array
    if (index == -1) {
        // In that case, add it to the end
        arr.push_back(n);
    } else {
        // Add the element to the required position in the vector
        arr.insert(arr.begin() + index, n);
    }

    // Take the size of the array
    int size = arr.size();

    // If the size of the array is odd, return the middle element of the sorted array
    if(size % 2 == 1) {
        return arr[size/2];
    // If the size of the array is even, return the average of the two middle elements of the sorted array
    } else {
        return (arr[(size/2) - 1] + arr[(size/2)]) / 2.0;
    }
}