#include <iostream>
using namespace std;

// Class definition for a Circular Queue
class CircularQueue {
private:
    // Array to store the elements of the circular queue
    int* cqueue;

    // Variables to track the front, rear, and size of the queue
    int front, rear, size;

public:
    // Constructor to initialize the circular queue with a given size
    CircularQueue(int s) {
        // Set the size of the circular queue
        size = s;

        // Dynamically allocate memory for the circular queue array
        cqueue = new int[size];

        // Initialize front and rear to -1, indicating an empty queue
        front = rear = -1;
    }

    void insertCQ(int val) {
        // Check for queue overflow
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            cout << "Queue Overflow \n";
            return;
        }
        // Initialize front and rear if the queue is empty
        if (front == -1) {
            front = rear = 0;
            
        } else {
            // Update rear, considering wraparound
            if (rear == size - 1)
                rear = 0;
            else
                rear = rear + 1;
        }

        // Insert the value at the rear of the circular queue
        cqueue[rear] = val;
    }


    void deleteCQ() {
        // Check for queue underflow
        if (front == -1) {
            cout << "Queue Underflow\n";  // Display error message if the queue is empty
            return;
        }

        // Display and delete the element at the front
        cout << "Element deleted from queue is : " << cqueue[front] << endl;

        // Update front and rear if there's only one element in the queue
        if (front == rear) {
            front = -1;  // Reset front and rear to indicate an empty queue
            rear = -1;
        } else {
            // Update front, considering wraparound
            if (front == size - 1)
                front = 0;  // Wraparound to the beginning of the array if front is at the end
            else
                front = front + 1;  // Move front to the next position in the array
        }
    }


    void displayCQ() {
        int f = front, r = rear;
        
        // Check if the queue is empty
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue elements are :\n";

        // Display elements when front <= rear
        if (f <= r) {
            while (f <= r) {
                cout << cqueue[f] << " ";
                f++;
            }
        } else {
            // Display elements when front > rear (considering wraparound)

            // Display elements from front to the end of the circular queue
            while (f <= size - 1) {
                cout << cqueue[f] << " ";
                f++;
            }

            // Reset f to the beginning of the circular queue
            f = 0;

            // Display elements from the beginning of the circular queue to rear
            while (f <= r) {
                cout << cqueue[f] << " ";
                f++;
            }
        }
        cout << endl;
    }


    void menu() {
        int ch, val;

        cout << "1) Insert\n";
        cout << "2) Delete\n";
        cout << "3) Display\n";
        cout << "4) Exit\n";

        do {
            cout << "Enter choice: " << endl;
            cin >> ch;

            switch(ch) {
                case 1:
                    cout << "Input for insertion: " << endl;
                    cin >> val;
                    insertCQ(val);
                    break;

                case 2:
                    deleteCQ();
                    break;

                case 3:
                    displayCQ();
                    break;

                case 4:
                    cout << "Exit\n";
                    break;

                default:
                    cout << "Incorrect!\n";
            }
        } while(ch != 4);
    }

    ~CircularQueue() {
        delete[] cqueue;
    }
};

int main() {
    int size;
    cout << "Enter the size of the Circular Queue: ";
    cin >> size;

    CircularQueue cq(size);
    cq.menu();

    return 0;
}
