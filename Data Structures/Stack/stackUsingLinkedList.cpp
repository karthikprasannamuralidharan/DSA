#include <iostream>

using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node with given data and next as nullptr
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top; // Pointer to the top of the stack
    int size;  // Variable to keep track of the size of the stack

public:
    // Constructor to initialize an empty stack
    Stack() : top(nullptr), size(0) {}

    // Function to push an element onto the stack
    void push(int element) {
        // Create a new node with the given data
        Node* newNode = new Node(element);

        // Set the next of the new node to the current top
        newNode->next = top;

        // Update the top to the new node
        top = newNode;

        // Increment the size
        size++;
    }

    // Function to pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        // Store the current top node
        Node* temp = top;

        // Update the top to the next node
        top = top->next;

        // Delete the previous top node
        delete temp;

        // Decrement the size
        size--;
    }

    // Function to get the top element of the stack
    int getTop() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1; // Returning a sentinel value for an empty stack
        }

        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Function to print the stack
    void printStack() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to swap the contents of two stacks
    void swapStacks(Stack& otherStack) {
        // Swap the tops
        Node* tempTop = top;
        top = otherStack.top;
        otherStack.top = tempTop;

        // Swap the sizes
        int tempSize = size;
        size = otherStack.size;
        otherStack.size = tempSize;
    }

    // Function to get the size of the stack
    int getSize() const {
        return size;
    }

    // Destructor to free memory when the stack is destroyed
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    // Creating a stack of integers
    Stack myStack;

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
    Stack anotherStack;
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