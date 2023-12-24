#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to calculate the height of a binary tree
int height(Node* p) {
    // Variable to store the height
    int h;

    // Check if the current node is a leaf (nullptr)
    if (p == nullptr) {
        // If it's a leaf, return -1 (height of an empty tree is -1)
        return -1;
    }

    // Recursively calculate the height of the left subtree
    int left = height(p->left);
    
    // Recursively calculate the height of the right subtree
    int right = height(p->right);

    // Compare the heights of the left and right subtrees
    if (left > right)
        // If the left subtree is taller, set the height to 1 + left
        h = 1 + left;
    else
        // If the right subtree is taller or equal, set the height to 1 + right
        h = 1 + right;

    // Return the calculated height
    return h;
}

// In-order traversal function
void inorder(Node* root) {
    // Base case: if the current node is null, return (end of traversal)
    if (root == nullptr) {
        return;
    }
    
    // Recursive call to traverse the left subtree
    inorder(root->left);
    
    // Process the current node (print its data in this case)
    cout << root->data << " ";
    
    // Recursive call to traverse the right subtree
    inorder(root->right);
}

// Pre-order traversal function
void preorder(Node* root) {
    // Base case: if the current node is null, return (end of traversal)
    if (root == nullptr) {
        return;
    }
    
    // Process the current node (print its data in this case)
    cout << root->data << " ";
    
    // Recursive call to traverse the left subtree
    preorder(root->left);
    
    // Recursive call to traverse the right subtree
    preorder(root->right);
}

// Post-order traversal function
void postorder(Node* root) {
    // Base case: if the current node is null, return (end of traversal)
    if (root == nullptr) {
        return;
    }
    
    // Recursive call to traverse the left subtree
    postorder(root->left);
    
    // Recursive call to traverse the right subtree
    postorder(root->right);
    
    // Process the current node (print its data in this case)
    cout << root->data << " ";
}

void levelOrderWithInfo(Node* root) {
    // Check if the tree is empty
    if (root == nullptr) {
        return;
    }

    // Create a queue to perform level-order traversal, 
    // each element of the queue is a pair (node, level)
    queue<pair<Node*, int>> q;
    q.push({root, 0}); // Push the root node with level 0 into the queue

    while (!q.empty()) {
        // Dequeue the front element of the queue
        Node* current = q.front().first;
        int level = q.front().second;
        q.pop();

        // Print information about the current node's level, parent, and child
        cout << "At Level: " << level << ", Parent is: ";
        if (current != nullptr) {
            cout << current->data; // Print parent node's data
        } else {
            cout << "None"; // If current node is null, print "None" for parent
        }
        cout << ", Child: ";

        // Check and enqueue the left child if it exists
        if (current != nullptr && current->left != nullptr) {
            cout << current->left->data << " ";
            q.push({current->left, level + 1}); // Enqueue left child with updated level
        }

        // Check and enqueue the right child if it exists
        if (current != nullptr && current->right != nullptr) {
            cout << current->right->data << " ";
            q.push({current->right, level + 1}); // Enqueue right child with updated level
        }

        cout << endl; // Move to the next line for the next level
    }
}

void levelOrder(Node* root) {
    if (root == nullptr) {
        return;  // If the tree is empty, nothing to do
    }

    queue<Node*> q;  // Create a queue to perform level order traversal
    q.push(root);    // Enqueue the root node to start the traversal

    while (!q.empty()) {
        int levelSize = q.size();  // Number of nodes at the current level

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();  // Get the front node of the queue
            q.pop();                    // Dequeue the current node

            cout << current->data << " ";  // Print the data of the current node

            // Enqueue the left child if it exists
            if (current->left != nullptr) {
                q.push(current->left);
            }

            // Enqueue the right child if it exists
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << endl;  // Move to the next level after printing all nodes at the current level
    }
}

// Function to build a binary tree using recursive approach
Node* buildTree() {
    // Variable to store user input for node data
    int data;
    
    // Prompt the user to enter data for the current node
    cout << "Enter data (enter -1 for null): ";
    cin >> data;

    // Check if the entered data is -1, indicating a null node
    if (data == -1) {
        // Return nullptr to represent a null node
        return nullptr;
    }

    // Create a new node with the entered data
    Node* root = new Node(data);
    
    // Recursively build the left subtree of the current node
    cout << "Enter left child of " << data << ": ";
    root->left = buildTree();

    // Recursively build the right subtree of the current node
    cout << "Enter right child of " << data << ": ";
    root->right = buildTree();

    // Return the root of the current subtree
    return root;
}

// Function to build a binary tree using level order traversal
Node* buildTreeLO() {
    int data;
    cout << "Enter the root data: ";
    cin >> data;

    // If the root data is -1, return a null pointer (indicating an empty tree)
    if (data == -1) {
        return nullptr;
    }

    // Create a new node with the entered data as the root of the tree
    Node* root = new Node(data);

    // Create a queue to perform level order traversal and initialize it with the root
    queue<Node*> q;
    q.push(root);

    // Continue until the queue is empty (all nodes are processed)
    while (!q.empty()) {
        // Get the front node from the queue
        Node* current = q.front();
        q.pop();

        int leftData, rightData;

        // Prompt for and input the data for the left child of the current node
        cout << "Enter left child of " << current->data << " (-1 for null): ";
        cin >> leftData;

        // If the entered data is not -1, create a new node and set it as the left child
        if (leftData != -1) {
            current->left = new Node(leftData);
            // Enqueue the left child for further processing
            q.push(current->left);
        }

        // Prompt for and input the data for the right child of the current node
        cout << "Enter right child of " << current->data << " (-1 for null): ";
        cin >> rightData;

        // If the entered data is not -1, create a new node and set it as the right child
        if (rightData != -1) {
            current->right = new Node(rightData);
            // Enqueue the right child for further processing
            q.push(current->right);
        }
    }

    // Return the root of the constructed binary tree
    return root;
}

// Function to count the number of nodes in a binary tree
int countNodes(Node* root) {
    // Base case: if the current node is null, return 0
    if (root == nullptr) {
        return 0;
    }

    // Recursive case: count the current node and recursively
    // count nodes in the left and right subtrees
    // The total count is the sum of the current node and its subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // Example usage
    // Node* root = buildTree();
    Node* root = buildTreeLO();

    //             1
    //     2                3
    // 4       5


    cout << "Level Order traversal with newline for each level:" << endl;
    levelOrder(root);
    
    cout << "Level Order traversal with info:" << endl;
    levelOrderWithInfo(root);
    
    cout << "Number of nodes in the tree: " << countNodes(root) << endl;

    cout << "Height of the tree: " << height(root) << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    // Don't forget to free the allocated memory
    // (In a real-world scenario, you might use smart pointers or a proper memory management strategy)
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
