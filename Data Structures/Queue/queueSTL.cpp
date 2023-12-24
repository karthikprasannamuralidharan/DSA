#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Creating a queue of integers
    queue<int> myQueue;

    // Pushing elements onto the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Accessing the front and back elements
    cout << "Front element: " << myQueue.front() << endl;
    cout << "Back element: " << myQueue.back() << endl;

    // Checking and printing the size of the queue
    cout << "Queue size: " << myQueue.size() << endl;

    // Using emplace to construct an element in-place at the end
    myQueue.emplace(70);
    myQueue.pop();

    // Accessing the updated front and back elements
    cout << "Updated Front element: " << myQueue.front() << endl;
    cout << "Updated Back element: " << myQueue.back() << endl;

    // Checking the updated size
    cout << "Updated queue size: " << myQueue.size() << endl;


    // Swapping the contents of two queues
    queue<int> anotherQueue;
    anotherQueue.push(100);
    anotherQueue.push(200);

//     Before Swap:
// myQueue: 10 20 30 70 
// anotherQueue: 100 200 

    // Swapping
    myQueue.swap(anotherQueue);

    cout << "\nAfter Swap:" << endl;
    cout << "myQueue: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }

    cout << "\nanotherQueue: ";
    while (!anotherQueue.empty()) {
        cout << anotherQueue.front() << " ";
        anotherQueue.pop();
    }

    return 0;
}
