#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
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
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to insert a node at the head of the list
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a node at any position in the list
    void insertAtPosition(int val, int position) {
        if (position < 0) {
            cout << "Invalid position. Position should be non-negative.\n";
            return;
        }

        Node* newNode = new Node(val);

        if (position == 0) {
            // Insert at the head
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position. Position exceeds the length of the list.\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete an item from the list
    void deleteItem(int val) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Item not found in the list.\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Function to search for a given item
    bool searchItem(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to retrieve a node from the linked list
    Node* retrieveNode(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Function to display the linked list
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Function to find the length of the list
    int length() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to destroy the linked list
    void destroyList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList myList;

    cout << "Is the list empty? " << (myList.isEmpty() ? "Yes" : "No") << "\n";

    myList.insertItemAtEnd(10);
    myList.insertItemAtEnd(20);
    myList.insertItemAtEnd(30);

    cout << "List: ";
    myList.displayList();

    cout << "Length of the list: " << myList.length() << "\n";

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

    cout << "Length of the list: " << myList.length() << "\n";

    return 0;
}

