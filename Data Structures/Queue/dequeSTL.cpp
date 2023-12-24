#include <iostream>
#include <deque>

using namespace std;

int main() {
    // Create a deque containing integers
    deque<int> myDeque = {1, 2, 3, 4, 5};

    // Print the initial deque
    cout << "Initial deque: ";
    for (const auto &element : myDeque) {
        cout << element << ' ';
    }
    cout << '\n';

    // Insert elements at the front and back
    myDeque.push_front(0);
    myDeque.push_back(6);

    // Print deque after insertion
    cout << "Deque after insertion: ";
    for (const auto &element : myDeque) {
        cout << element << ' ';
    }
    cout << '\n';

    // Access front and back elements
    cout << "Front element: " << myDeque.front() << '\n';
    cout << "Back element: " << myDeque.back() << '\n';

    // Remove elements from the front and back
    myDeque.pop_front();
    myDeque.pop_back();

    // Print deque after removal
    cout << "Deque after removal: ";
    for (const auto &element : myDeque) {
        cout << element << ' ';
    }
    cout << '\n';

    // Insert elements at a specific position
    auto it = myDeque.begin() + 2;
    myDeque.insert(it, 100);

    // Print deque after insertion at a specific position
    cout << "Deque after insertion at a specific position: ";
    for (const auto &element : myDeque) {
        cout << element << ' ';
    }
    cout << '\n';

    // Erase elements at a specific position
    it = myDeque.begin() + 3;
    myDeque.erase(it);

    // Print deque after erasing at a specific position
    cout << "Deque after erasing at a specific position: ";
    for (const auto &element : myDeque) {
        cout << element << ' ';
    }
    cout << '\n';

    return 0;
}
