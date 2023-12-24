#include <iostream>

using namespace std;

// Node structure for a circular linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() : head(nullptr) {}

    // Destructor
    ~CircularLinkedList() {
        destroyList();
    }

    // Function to check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Function to insert an item at the end of the list
    void insertItemAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Pointing to itself to form a circular structure
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to insert a node at the head of the list
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Function to delete an item from the list
    void deleteItem(int val) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // Traverse the list to find the node to delete
        do {
            if (temp->data == val) {
                break;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (temp == head && temp->next == head) {
            // Single node case
            head = nullptr;
        } else if (temp == head) {
            // Deleting the head node
            prev->next = temp->next;
            head = temp->next;
        } else {
            // Deleting a non-head node
            prev->next = temp->next;
        }

        delete temp;
    }

    // Function to search for a given item
    bool searchItem(int val) {
        if (head == nullptr) {
            return false;
        }

        Node* temp = head;
        do {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        return false;
    }

    // Function to retrieve a node from the circular linked list
    Node* retrieveNode(int val) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* temp = head;
        do {
            if (temp->data == val) {
                return temp;
            }
            temp = temp->next;
        } while (temp != head);

        return nullptr;
    }

    // Function to display the circular linked list
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << "\n";
    }

    // Function to destroy the circular linked list
    void destroyList() {
        if (head == nullptr) {
            return;
        }

        Node* current = head;
        Node* nextNode;

        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
    }
};

int main() {
    CircularLinkedList myList;

    cout << "Is the list empty? " << (myList.isEmpty() ? "Yes" : "No") << "\n";

    myList.insertItemAtEnd(10);
    myList.insertItemAtEnd(20);
    myList.insertItemAtEnd(30);

    cout << "List: ";
    myList.displayList();

    cout << "Is the list empty? " << (myList.isEmpty() ? "Yes" : "No") << "\n";

    int searchValue = 20;
    cout << "Is " << searchValue << " in the list? " << (myList.searchItem(searchValue) ? "Yes" : "No") << "\n";

    Node* foundNode = myList.retrieveNode(searchValue);

    if (foundNode != nullptr) {
        cout << "Node with value " << searchValue << " found at address: " << foundNode << "\n";
    } else {
        cout << "Node with value " << searchValue << " not found in the list.\n";
    }

    myList.deleteItem(20);
    cout << "List after deleting 20: ";
    myList.displayList();

    return 0;
}
