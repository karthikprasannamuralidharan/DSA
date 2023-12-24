#include<iostream>

using namespace std;

// Class definition for a basic queue implementation
class Queue {
    int *arr;        // Array to store queue elements
    int size;        // Maximum size of the queue
    int frontIndex;   // Index pointing to the front element of the queue
    int rear;         // Index pointing to the rear element of the queue

public:
    // Constructor to initialize the queue with a default size of 1000
    Queue() {
        size = 1000;           // Setting the maximum size of the queue
        frontIndex = 0;        // Initializing the front index to 0
        rear = 0;              // Initializing the rear index to 0
        arr = new int[size];   // Dynamically allocating memory for the array
    }

    // Function to enqueue (add) an element to the queue
    void enqueue(int value) {
        // Check if the rear index is at the maximum size
        if (rear == size) {
            // If so, the queue is full, and we have a queue overflow
            cout << "Queue Overflow" << endl;
        } else {
            // If there is space in the queue, add the value to the rear position
            arr[rear] = value;

            // Move the rear index to the next available position
            rear++;
        }
    }


    int dequeue() {
    // Check if the queue is empty (frontIndex is equal to rear)
    if (frontIndex == rear) {
        // Return -1 to indicate that the queue is empty
        return -1;
    } else {
            // Retrieve the element at the front of the queue
            int answer = arr[frontIndex];

            // Mark the front element as removed by setting it to -1
            arr[frontIndex] = -1;

            // Move the frontIndex to the next position
            frontIndex++;

            // Check if the queue is now empty after dequeuing
            if (frontIndex == rear) {
                // If empty, reset both frontIndex and rear to 0
                frontIndex = 0;
                rear = 0;
            }

            // Return the dequeued element
            return answer;
        }
    }


    // Function to get the front element of the queue
    // Returns -1 if the queue is empty, otherwise returns the front element
    int getFront() {
        // Check if the front index is equal to the rear index, indicating an empty queue
        if (frontIndex == rear) {
            return -1;  // Return -1 for an empty queue
        } else {
            return arr[frontIndex];  // Return the front element of the queue
        }
    }

    // Function to check if the queue is empty
    // Returns true if the queue is empty, false otherwise
    bool isEmpty() {
        return frontIndex == rear;  // If front index is equal to rear index, the queue is empty
    }

};

int main() {
    Queue myQueue;

    // Enqueue elements
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Display front element
    cout << "Front element: " << myQueue.getFront() << endl;

    // Dequeue elements
    cout << "Dequeued element: " << myQueue.dequeue() << endl;
    cout << "Dequeued element: " << myQueue.dequeue() << endl;

    // Check if the queue is empty
    if (myQueue.isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    // Enqueue more elements
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    // Display front element
    cout << "Front element: " << myQueue.getFront() << endl;

    return 0;
}
