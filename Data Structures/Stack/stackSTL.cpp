#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Creating a stack of integers
    stack<int> myStack;

    // Pushing elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // // Accessing the top element
    cout << "Top element: " << myStack.top() << endl;

    // // Popping the top element
    cout << "Top element poped";
    myStack.pop();
    cout << "Top element: " << myStack.top() << endl;

    // // Checking if the stack is empty
    if(!myStack.empty()) {
        cout << "Stack is not empty. Size: " << myStack.size() << endl;
    }

    // // Pushing more elements
    myStack.push(40);
    myStack.push(50);

    cout << "Elements in myStack is : " << myStack.size() << endl;
    

    // // Swapping contents with another stack
    stack<int> anotherStack;
    anotherStack.push(100);
    anotherStack.push(200);

    myStack.swap(anotherStack);

    cout << "Contents of anotherStack after swap: ";
    while(!anotherStack.empty()) {
        cout << anotherStack.top() << " ";
        anotherStack.pop();
    }
    cout << endl;

    cout << "Contents of myStack before swap: ";
    while(!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
