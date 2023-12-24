#include<iostream>

using namespace std;

class Stack {
public:
    // Member variables
    int *arr;   // Pointer to the array representing the stack
    int size;   // Maximum size of the stack
    int top;    // Index of the top element in the stack

    // Constructor to initialize the stack
    Stack(int length) {
        this->size = length;          // Set the maximum size of the stack
        arr = new int[size];          // Dynamically allocate memory for the stack array
        top = -1;                      // Initialize top as -1 since the stack is empty initially
    }

// Function to add an element to the stack
void push(int element) {
    // Check if there is space in the stack (size - top > 1)
    if (size - top > 1) {
        // Increment the top index to move to the next empty slot
        top++;
        // Add the element to the stack at the updated top index
        arr[top] = element;
    } else {
        // Print an error message if the stack is full (Stack Overflow)
        cout << "Stack Overflow\n";
    }
}

// Function to remove the top element from the stack
void pop() {
    // Check if the stack is not empty
    if (top != -1) {
        // Decrement the top index to remove the top element
        top--;
    } else {
        // If the stack is empty, print an error message (Stack Underflow)
        cout << "Stack Underflow\n";
    }
}

// Function to get the top element of the stack
int getTop() {
    // Return the element at the top of the stack
    return arr[top];
}

// Function to check if the stack is empty
bool isEmpty() {
    // Returns true if the top of the stack is -1, indicating an empty stack
    return top == -1;
}

// Function to get the size of the stack
int getSize() {
    // The size of the stack is determined by the value of 'top' variable.
    // 'top' represents the index of the topmost element in the stack.
    // Since array indices start from 0, adding 1 gives the total number of elements in the stack.
    return top + 1;
}

// Function to swap the contents of two stacks
void swapStacks(Stack &otherStack) {
    // Swap the contents by exchanging the arrays
    int *tempArr = arr;         // Store the current stack's array in a temporary variable
    arr = otherStack.arr;       // Assign the other stack's array to the current stack
    otherStack.arr = tempArr;    // Assign the temporary array to the other stack

    // Swap the sizes
    int tempSize = size;        // Store the current stack's size in a temporary variable
    size = otherStack.size;     // Assign the other stack's size to the current stack
    otherStack.size = tempSize;  // Assign the temporary size to the other stack

    // Swap the tops
    int tempTop = top;          // Store the current stack's top index in a temporary variable
    top = otherStack.top;       // Assign the other stack's top index to the current stack
    otherStack.top = tempTop;    // Assign the temporary top index to the other stack
}

// Function to print the stack without modifying it
void printStack() const {
    // Iterate through the elements in the stack
    for (int i = 0; i <= top; ++i) {
        // Print the current element followed by a space
        cout << arr[i] << " ";
    }
    // Move to the next line to separate the output
    cout << endl;
}
};

int main() {
    // Creating a stack of integers
    Stack myStack(10);

    // Pushing elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Accessing the top element
    cout << "Top element: " << myStack.getTop() << endl;

    // Popping the top element
    cout << "Top element popped\n";
    myStack.pop();

    cout << "Top element: " << myStack.getTop() << endl;

    // Checking if the stack is empty
    if (!myStack.isEmpty()) {
        cout << "Stack is not empty. Size: " << myStack.getSize() << endl;
    } else {
        cout << "Stack is empty\n";
    }

    // Pushing more elements
    myStack.push(40);
    myStack.push(50);

    // Creating another stack
    Stack anotherStack(10);
    anotherStack.push(100);
    anotherStack.push(200);

    // Call swapStacks on an instance of the Stack class
    myStack.swapStacks(anotherStack);

    // Print the contents of anotherStack after swap
    cout << "Contents of anotherStack after swap: ";
    anotherStack.printStack();

    // Print the contents of myStack before swap
    cout << "Contents of myStack before swap: ";
    myStack.printStack();

    return 0;
}
