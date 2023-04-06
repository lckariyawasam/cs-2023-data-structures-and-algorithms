#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    int value;
    Node *link;
};

struct StackArray {
    int size;
    int top;
    int *arr;

    StackArray(int size_input) {
        // Set the size of the array and create arr of the required size
        size = size_input;
        arr = new int[size];
        top = -1;
    }

    void push(int data) {
        // If stack is not full, push the given data onto the stack
        if (!isFull()) {
            arr[++top] = data;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        // If the stack is not empty, pop the top element from the stack
        if (top > -1) {
            // Here top pointer is decremented to pop the item from the stack
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    void display() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int stacktop() {
        // If the stack is not empty, returns the value of the top element in the stack
        if (top == -1) {
            cout << "Stack Underflow" << endl;
        } else {
            return arr[top];
        }
    }

    bool isEmpty() {
        return top == -1;
    }
 
    bool isFull() {
        return top == size - 1;
    }
}; 

struct StackLinkedList {
    Node *head;

    void push(int data) {
        //New item pushed onto the stack here
        if (head == NULL) {
            // If the head is null, create a new node and set it as the head
            head = new Node();
            head->value = data;
        } else {
            // Create a new node and set it as the head and set the previous head node as its next pointer
            Node *temp = new Node();
            temp->value = data;
            temp->link = head;
            head = temp;
        }
    }

    void pop() {
        if (!isEmpty()) {
            head = head->link;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    int stacktop() {
        if (head == NULL) {
            cout << "Stack Underflow" << endl;
        } else {
            return head->value;
        }
    }

    void display() {
        Node *current = head;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->link;
        }
        cout << endl;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main (void) {

    // Take the size of the stack (for array implementation) from the user
    int size;
    cout << "Size of the stack: ";
    cin >> size;


    // First do the operations for the linked list based stack and record the timing

    // Record the start time
    auto start_time = chrono::high_resolution_clock::now();

    // Stack implemented using linked list
    StackLinkedList *stack_linkedlist = new StackLinkedList();
    stack_linkedlist->push(8);
    stack_linkedlist->push(10);
    stack_linkedlist->push(5);
    stack_linkedlist->push(11);
    stack_linkedlist->push(15);
    stack_linkedlist->push(23);
    stack_linkedlist->push(6);
    stack_linkedlist->push(18);
    stack_linkedlist->push(20);
    stack_linkedlist->push(17);
    stack_linkedlist->display();
    stack_linkedlist->pop();
    stack_linkedlist->pop();
    stack_linkedlist->pop();
    stack_linkedlist->pop();
    stack_linkedlist->pop();
    stack_linkedlist->display();
    stack_linkedlist->push(4);
    stack_linkedlist->push(30);
    stack_linkedlist->push(3);
    stack_linkedlist->push(1);
    stack_linkedlist->display();


    // Record the end time
    auto end_time = chrono::high_resolution_clock::now();

    // Compute the elapsed time in microseconds
    double time_taken = chrono::duration_cast<chrono::duration<double> >(end_time - start_time).count();

    cout << "Stack LinkedList | Operations completed in " << fixed << setprecision(10)<< time_taken << " microseconds"<< endl;


    // Next to the same operations for the array based stack and record the timing

    // Record the start time
    auto start_time_2 = chrono::high_resolution_clock::now();

    StackArray *stack_array = new StackArray(size);
    stack_array->push(8);
    stack_array->push(10);
    stack_array->push(5);
    stack_array->push(11);
    stack_array->push(15);
    stack_array->push(23);
    stack_array->push(6);
    stack_array->push(18);
    stack_array->push(20);
    stack_array->push(17);
    stack_array->display();
    stack_array->pop();
    stack_array->pop();
    stack_array->pop();
    stack_array->pop();
    stack_array->pop();
    stack_array->display();
    stack_array->push(4);
    stack_array->push(30);
    stack_array->push(3);
    stack_array->push(1);
    stack_array->display();


    // Record the end time
    auto end_time_2 = chrono::high_resolution_clock::now();

    // Compute the elapsed time in microseconds
    double time_taken_2 = chrono::duration_cast<chrono::duration<double> >(end_time_2 - start_time_2).count();

    cout << "Stack Array | Operations completed in " << fixed << setprecision(10)<< time_taken_2 << " microseconds"<< endl;
}