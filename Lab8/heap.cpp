#include <iostream>
#include <cstdlib>
using namespace std;

  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify

   // Initialize the root as the largest element
   int largest = root;

   // Get the indexes of the two child nodes
   int left = root*2 + 1;
   int right = root*2 + 2;
  
   // If the left child is greater than the largest, set it as the largest
   if (left < n && arr[left] > arr[largest]) {
      largest = left;
   }

   // If the right child is greater than the largest, set it as the largest
   if (right < n && arr[right] > arr[largest]) {
      largest = right;
   }

   // If the root is not the largest, swap the values of largest and root
   // Then recursively call heapify on the subtree with largest index as root
   if (largest != root) {
      int temp = arr[root];
      arr[root] = arr[largest];
      arr[largest] = temp;

      heapify(arr, n, largest);
   }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap

   // The last parent node is at (n//2) - 1 index
   // Iteratively run the heapify function on roots from
   // the last to the first parent node
   for (int i = (n/2) - 1; i >= 0; i--) {
      heapify(arr, n, i);
   }

   // Now the max-heap has been built
   
   // extracting elements from heap one by one
   for (int heapsize = n; heapsize > 1; heapsize--) {
      // Exchange the values of first and last elements of the heap
      int temp = arr[0];
      arr[0] = arr[heapsize - 1];
      arr[heapsize - 1] = temp;
      
      // Rerun the heapify function to maintain the heap property
      heapify(arr, heapsize - 1, 0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   // Initialize the number of elements in the array
   int N = 12;
   int heap_arr[N];

   for (int i = 0; i < N; i++) {
      // Add a random value to the array between 0 and 100
      heap_arr[i] = rand() % 100;
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr, N);
  
   heapSort(heap_arr, N);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, N);
}