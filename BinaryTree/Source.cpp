/*
Jordan Small
27 MAR 2024
Professor Boujarwah

This source.cpp includes the Binary Tree implementation from class.

For Assignment 2:
Appended are functions for pre and post order traversal (question 1), a
Breadth First Search function that utilizes two queues (question 2), and
a function that removes nodes from a Binary Search Tree outside of a 
specified range (question 4).

Question 1: Lines 50-69
Question 2: Lines 128-170
Question 4: Lines 172-204

The functionality for these functions are tested/debugged in main (lines 207-282).
*/

#include<iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode {
    char key;
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(char key, int value) {
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
    }

    //prints out the keys in the tree inOrder
    void inOrderTraversal(BinaryTreeNode* node) {
        if (node == NULL) {
            return;
        }

        inOrderTraversal(node->left);
        cout << node->key << " ";
        inOrderTraversal(node->right);
    }

    //prints out the keys in the tree in preOrder
    void preOrderTraversal(BinaryTreeNode* node) {

        if (node == NULL) return;

        cout << node->key << " ";        // print key
        preOrderTraversal(node->left);   // recur on left subtree
        preOrderTraversal(node->right);  // recur on right subtree

    }

    //prints out the keys in the tree in postOrder
    void postOrderTraversal(BinaryTreeNode* node) {

        if (node == NULL) return;

        postOrderTraversal(node->left);  // recur on left subtree
        postOrderTraversal(node->right); // recur on right subtree
        cout << node->key << " ";        // print key

    }

    //Searches and returns the node with the target key using DFS assuming it is unique in the tree.
    BinaryTreeNode* DFS(BinaryTreeNode* node, char target) {
        if (node == NULL) {
            return NULL;
        }

        //search the left subtree
        BinaryTreeNode* left_res = DFS(node->left, target);
        if (left_res != NULL) {
            return left_res;
        }

        //search the right subtree
        BinaryTreeNode* right_res = DFS(node->right, target);
        if (right_res != NULL) {
            return right_res;
        }

        //check the current node for the specified key 
        if (node->key == target) {
            return node;
        }

        return NULL;
    }

    //Searches and returns the node with the target key using BFS assuming it is unique in the tree.
    BinaryTreeNode* BFS(BinaryTreeNode* node, char target) {
        if (node == NULL) {
            return NULL;
        }

        queue<BinaryTreeNode*> open_queue;
        open_queue.push(node);

        while (!open_queue.empty()) {
            BinaryTreeNode* currentNode = open_queue.front();
            cout << currentNode->key << " ";

            //is this the target we are looking for?
            if (currentNode->key == target) {
                return currentNode;
            }
            if (currentNode->left != NULL) {
                open_queue.push(currentNode->left);
            }
            if (currentNode->right != NULL) {
                open_queue.push(currentNode->right);
            }

            open_queue.pop();
        }

        //if we exit the while look we have not found the target 
        return NULL;
    }

    // BFS using a queue for current level and next level
    BinaryTreeNode* BFS2(BinaryTreeNode* root, char target) {

        // check if the tree is empty
        if (root == NULL) return NULL;
        
        // initialize queue for current and next level of the tree
        queue<BinaryTreeNode*> currentLevel;
        queue<BinaryTreeNode*> nextLevel;

        // start the current level with the root node
        currentLevel.push(root);

        // continue traversal until all nodes are visited
        while (!currentLevel.empty()) {

            // process the front node in the current level and output its key
            BinaryTreeNode* currentNode = currentLevel.front();
            currentLevel.pop();
            cout << currentNode->key << " ";

            // check if the current node's key matches the target
            if (currentNode->key == target) {
                //output message indicating the target is found and return the node it is found on
                cout << "BFS: Found node with key '" << target << "' and value " << currentNode->value << endl;
                return currentNode;
            }

            // enqueue child nodes to the next level if they exist
            if (currentNode->left != NULL) nextLevel.push(currentNode->left);
            if (currentNode->right != NULL) nextLevel.push(currentNode->right);

            // if all the nodes in the current level are processed, move to the next level
            if (currentLevel.empty()) {
                swap(currentLevel, nextLevel);
            }
        }

        // if the loop is exited, the key was not found
        cout << "Key '" << target << "' not found." << endl;
        return NULL;

    }

    // removes nodes outside specified range
    // parameters: root is node to start, and min/max are lower/upper bounds for key value
    BinaryTreeNode* removeOutsideRange(BinaryTreeNode* root, int min, int max) {
        // check if current node is NULL
        if (root == NULL) return NULL;

        // recursively remove nodes from left and right subtrees
        root->left = removeOutsideRange(root->left, min, max);
        root->right = removeOutsideRange(root->right, min, max);

        // check if value of current node is less than min
        if (root->value < min) {
            // print the value of the node being removed
            cout << "Removing node with value " << root->value << endl;
            // delete current node and return its right child as the new root
            BinaryTreeNode* rightChild = root->right;
            delete root;
            return rightChild;
        }

        // check if value of current node is greater than max
        if (root->value > max) {
            // print the value of the node being removed
            cout << "Removing node with value " << root->value << endl;
            // delete the current node and return its left child as the new root
            BinaryTreeNode* leftChild = root->left;
            delete root;
            return leftChild;
        }

        // return current node if it is in specified range
        return root;
    }
};

int main() {
    // Create a binary tree
    BinaryTreeNode* root = new BinaryTreeNode('A', 1);
    root->left = new BinaryTreeNode('B', 2);
    root->right = new BinaryTreeNode('C', 3);
    root->left->left = new BinaryTreeNode('D', 4);
    root->left->right = new BinaryTreeNode('E', 5);
    root->right->left = new BinaryTreeNode('F', 6);
    root->right->right = new BinaryTreeNode('G', 7);

    // Test in-order traversal
    cout << "In-order traversal: ";
    root->inOrderTraversal(root);
    cout << endl;

    // Test pre-order traversal
    cout << "Pre-order traversal: ";
    root->preOrderTraversal(root);
    cout << endl;

    // Test post-order traversal
    cout << "Post-order traversal: ";
    root->postOrderTraversal(root);
    cout << endl;

    // Test DFS
    char targetDFS = 'E';
    BinaryTreeNode* resultDFS = root->DFS(root, targetDFS);
    if (resultDFS != nullptr) {
        cout << "DFS: Found node with key '" << targetDFS << "' and value '" << resultDFS->value << "'" << endl;
    }
    else {
        cout << "DFS: Node with key '" << targetDFS << "' not found." << endl;
    }

    // Test BFS
    char targetBFS = 'F';
    BinaryTreeNode* resultBFS = root->BFS(root, targetBFS);
    if (resultBFS != nullptr) {
        cout << "BFS: Found node with key '" << targetBFS << "' and value '" << resultBFS->value << "'" << endl;
    }
    else {
        cout << "BFS: Node with key '" << targetBFS << "' not found." << endl;
    }

    // Test BFS using 2 queues
    cout << endl << "BFS2: " << endl;
    BinaryTreeNode* result2 = root->BFS2(root, targetBFS);

    // Test Remove Outside Range function
    // 
    // Instantiate a Binary Search Tree
    BinaryTreeNode* BSTr = new BinaryTreeNode('A', 41);
    BSTr->left = new BinaryTreeNode('B', 20);
    BSTr->right = new BinaryTreeNode('C', 65);
    BSTr->left->left = new BinaryTreeNode('D', 11);
    BSTr->left->right = new BinaryTreeNode('E', 29);
    BSTr->right->left = new BinaryTreeNode('F', 50);
    BSTr->right->right = new BinaryTreeNode('G', 91);

    // Display the original tree
    cout << endl << "Testing remove outside range:" << endl << "Original Tree (inOrderTraversal):" << endl;
    BSTr->inOrderTraversal(BSTr);
    cout << endl;

    // Remove nodes outside the range [3, 6] based on values
    cout << "Removing nodes with values outside the range [25, 60]" << endl;
    BinaryTreeNode* newRoot = BSTr->removeOutsideRange(BSTr, 25, 60);

    // Display the modified tree
    cout << "Modified Tree after removing nodes with values outside range [25, 60]:" << endl;
    newRoot->inOrderTraversal(newRoot);
    cout << endl;

    return 0;
}

/*
Source: https://www.geeksforgeeks.org/remove-bst-keys-outside-the-given-range/
*/