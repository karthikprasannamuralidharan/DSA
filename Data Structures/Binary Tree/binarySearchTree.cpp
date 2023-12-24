#include <iostream>

using namespace std;

// Definition of a TreeNode class representing a node in a binary tree
class TreeNode {
public:
    // Data stored in the node
    int data;

    // Pointers to the left and right children of the node
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a TreeNode with a given value
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};


// Binary Search Tree (BST) class
class BST {
private:
    // Private member variable representing the root of the BST
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        // If the current node is null, create a new node with the given value
        if (node == nullptr) {
            return new TreeNode(value);
        }

        // If the value is less than the current node's data, insert it in the left subtree
        if (value < node->data) {
            node->left = insert(node->left, value);
        }

        // If the value is greater than the current node's data, insert it in the right subtree
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        // If the value is equal to the current node's data, do nothing (no duplicates allowed)
        // Return the updated node (with the new value inserted)
        return node;
    }

    // TreeNode is assumed to be a structure or class representing a node in a binary tree
    // Function to find the node with the minimum value in a binary search tree
    TreeNode* findMin(TreeNode* node) {
        // Traverse the left subtree until the leftmost leaf is reached
        while (node->left != nullptr) {
            node = node->left;
        }

        // Return the node with the minimum value (leftmost leaf)
        return node;
    }

    // Function to remove a node with a specific value from a binary search tree
    TreeNode* remove(TreeNode* node, int value) {
        // Base case: If the current node is nullptr, there's nothing to remove
        if (node == nullptr) {
            return nullptr;
        }

        // If the value to be removed is less than the current node's value,
        // recursively call remove on the left subtree
        if (value < node->data) {
            node->left = remove(node->left, value);
        }
        // If the value to be removed is greater than the current node's value,
        // recursively call remove on the right subtree
        else if (value > node->data) {
            node->right = remove(node->right, value);
        }
        // If the current node's value matches the value to be removed
        else {
            // Case 1: Node with only one child or no child
            if (node->left == nullptr) {
                // Store the right child in a temporary variable
                TreeNode* temp = node->right;
                // Delete the current node
                delete node;
                // Return the right child (may be nullptr)
                return temp;
            }
            else if (node->right == nullptr) {
                // Store the left child in a temporary variable
                TreeNode* temp = node->left;
                // Delete the current node
                delete node;
                // Return the left child
                return temp;
            }

            // Case 3: Node with two children
            // Find the minimum value in the right subtree (smallest value in the right subtree)
            TreeNode* temp = findMin(node->right);
            // Copy the minimum value to the current node
            node->data = temp->data;
            // Recursively remove the node with the minimum value in the right subtree
            node->right = remove(node->right, temp->data);
        }

        // Return the modified node
        return node;
    }


    // Function to search for a value in a binary search tree
    // Returns true if the value is found, false otherwise
    bool search(TreeNode* node, int value) {
        // If the current node is null, the value is not found
        if (node == nullptr) {
            return false;
        }

        // If the value matches the data in the current node, it is found
        if (value == node->data) {
            return true;
        } 

        // If the value is less than the data in the current node, search in the left subtree
        else if (value < node->data) {
            return search(node->left, value);
        } 
        // If the value is greater than the data in the current node, search in the right subtree
        else {
            return search(node->right, value);
        }
    }


    // Function to perform an inorder traversal of a binary tree
    // and print the nodes in ascending order.
    void inorderTraversal(TreeNode* node) {
        // Check if the current node is not null.
        if (node != nullptr) {
            // Recursively traverse the left subtree.
            inorderTraversal(node->left);

            // Print the data of the current node.
            cout << node->data << " ";

            // Recursively traverse the right subtree.
            inorderTraversal(node->right);
        }
    }




public:
    // Constructor: Initializes an empty BST with a null root
    BST() : root(nullptr) {}

    // Public method to insert a value into the BST
    void insert(int value) {
        root = insert(root, value);  // Calls private insert method
    }

    // Public method to remove a value from the BST
    void remove(int value) {
        root = remove(root, value);  // Calls private remove method
    }

    // Public method to search for a value in the BST
    bool search(int value) {
        return search(root, value);  // Calls private search method
    }

    // Public method to perform an inorder traversal of the BST
    void inorderTraversal() {
        inorderTraversal(root);  // Calls private inorderTraversal method
        cout << endl;
    }
};

int main() {
    BST bst;

    cout << "Enter values to insert into the BST (enter -1 to stop):\n";
    int inputValue;
    while (true) {
        cin >> inputValue;
        if (inputValue == -1) {
            break;
        }
        bst.insert(inputValue);
    }

    cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    cout << "Enter a value to search in the BST: ";
    cin >> inputValue;
    cout << "Search for " << inputValue << ": " << (bst.search(inputValue) ? "Found" : "Not found") << endl;

    cout << "Enter a value to remove from the BST: ";
    cin >> inputValue;
    bst.remove(inputValue);
    cout << "Inorder Traversal after removal: ";
    bst.inorderTraversal();

    return 0;
}
