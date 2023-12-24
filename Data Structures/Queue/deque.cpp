#include <iostream>

using namespace std;

class Deque {
    int *arr;
    int size;
    int front;
    int rear;

public:
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        // If the front index is -1, the queue is empty
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        // If the rear index is at the last position and the front index is either 0 or just before the rear
        // it indicates that the queue is full
        return rear == size - 1 && (front == 0 || front == rear + 1);
    }

    // Function to enqueue an element at the front of the queue
    void enqueueFront(int value) {
        // Check if the queue is full
        if (isFull()) {
            cout << "Queue Overflow" << endl;
        } 
        // Check if the queue is empty
        else if (isEmpty()) {
            // If empty, set both front and rear to 0
            rear = front = 0;
        } 
        // Check if front is at the beginning of the array
        else if (front == 0) {
            // If front is at the beginning, wrap around to the end of the array
            front = size - 1;
        } 
        // If none of the above conditions are met, decrement front
        else {
            front--;
        }

        // Place the value at the new front position
        arr[front] = value;
    }


    // Function to enqueue an element at the rear of the circular queue
    void enqueueRear(int value) {
        // Check if the queue is full
        if (isFull()) {
            cout << "Queue Overflow" << endl; // Display overflow message if the queue is full
        } 
        // Check if the queue is empty
        else if (isEmpty()) {
            rear = front = 0; // If empty, set both front and rear to 0 and add the first element
        } 
        // Check if rear is at the end of the circular queue
        else if (rear == size - 1) {
            rear = 0; // If at the end, wrap around to the beginning of the circular queue
        } 
        // If none of the above conditions are met, increment rear
        else {
            rear++;
        }

        // Add the value to the rear of the circular queue
        arr[rear] = value;
    }

    void dequeueFront() {
        // Check if the queue is empty
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
        } 
        // Check if there is only one element in the queue
        else if (rear == front) {
            rear = front = -1; // Reset both front and rear to -1, indicating an empty queue
        } 
        // Check if front is at the end of the queue
        else if (front == size - 1) {
            front = 0; // Wrap around to the beginning of the queue
        } 
        // Normal case, increment front to dequeue from the front
        else {
            front++;
        }
    }


    void dequeueRear() {
        // Check if the queue is empty
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
        } else if (rear == front) {
            // If there is only one element in the queue, set both front and rear to -1
            rear = front = -1;
        } else if (rear == 0) {
            // If rear is at the beginning of the array, wrap around to the end
            rear = size - 1;
        } else {
            // Move rear one step towards the front (circular decrement)
            rear--;
        }
    }

    // Function to display the elements of the deque
    void display() {
        // Check if the deque is empty
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
        } else {
            // Initialize a variable 'i' with the front index
            int i = front;
            
            // Loop through the deque elements
            while (true) {
                // Print the element at the current index
                cout << arr[i] << " ";
                
                // Check if 'i' has reached the rear index, exit the loop if true
                if (i == rear) break;

                // Move to the next index in a circular manner
                i = (i + 1) % size;
            }
        // Print a newline to separate the output
        cout << endl;
        }
    }

};

int main() {
    Deque dq(5);

    dq.enqueueRear(1);
    dq.enqueueRear(2);
    dq.enqueueFront(0);
    dq.display(); // Output: 0 1 2

    dq.dequeueFront();
    dq.display(); // Output: 1 2

    dq.enqueueFront(-1);
    dq.enqueueRear(3);
    dq.display(); // Output: -1 1 2 3

    dq.dequeueRear();
    dq.display(); // Output: -1 1 2
}
