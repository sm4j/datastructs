#include<iostream>
using namespace std;

// Node class that represents the building blocks of our linked list
class Node {

public:

    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}

};

// LinkedList Class representing a linked list
class LinkedList {

private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Insert an element at the beginning of the linked list
    void insertAtHead(int value) {

        Node* newNode = new Node(value);
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;

        // If the list was empty, update the tail
        if (tail == nullptr) {
            tail = newNode;
        }

    }

    // Insert a node after the specified node and update all connections necessary

    void insertAfter(Node* prevNode, int value) {

        if (prevNode == nullptr) {
            return;
        }

        Node* newNode = new Node(value);
        newNode->prev = prevNode;
        newNode->next = prevNode->next;

        if (prevNode->next != nullptr) {
            prevNode->next->prev = newNode;
        }
        else {
            tail = newNode;
        }

        prevNode->next = newNode;

    }

    // Insert an element at the end of a linked list
    void insertAtTail(int value) {

        Node* newNode = new Node(value);
        newNode->prev = tail;
        newNode->next = nullptr;

        if (tail != nullptr) {
            tail->next = newNode;
        }

        tail = newNode;

        if (head == nullptr) {
            head = newNode;
        }

    }

    // Delete a node from the beginning of the linked list
    void deleteAtHead() {

        // Check if the list is empty
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = temp->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }

        delete temp;

        // If the list is now empty
        if (head == nullptr) {
            tail == nullptr;
        }
    }
    
    // Delete specified node in the linked list
    void deleteNode(Node* nodeToDelete) {
        if (nodeToDelete == nullptr) {
            return;  // Cannot delete null node
        }

        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;

        delete nodeToDelete;
    }

    // Delete the last node in the linked list
    void deleteAtTail() {

        if (tail == nullptr) {
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }

        delete temp;

    }

    // Display the elements in the list

    void display() {

        Node* current = head;

        if (head == nullptr) {
            cout << "The list is empty";
        }

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;

    }

    Node* getHead() const {

        return head;

    }

    // Reverse the linked list

    void reverse() {

        // Create an empty node
        Node* temp = nullptr;

        // Create a node used as current when traversing and set equal to head
        Node* current = head;

        // If head is null, list is empty
        if (head == nullptr) {
            cout << "The list is empty";
        }

        // While the current node is not empty, iterate through this loop
        while (current != nullptr) {

            // Set the temp node equal to the previous node from current (starting at head)
            temp = current->prev;

            // Where the reversal starts:
            // Current->prev = current->next
            current->prev = current->next;

            // Current->next = temp, which is has the value stored of the 
            // previous node from before
            current->next = temp;

            // Current node is now updated to the previous node
            current = current->prev;

        }

        // If the temp node is not null, set head = temp->prev
        // This ends the reversal of linked list
        if (temp != nullptr) {
            head = temp->prev;
        }
    
        /*Source: https://www.geeksforgeeks.org/reverse-a-doubly-linked-list/ */
    }
};

int main() {

    // Construct list called myList
    LinkedList myList;

    // Insert values at head for list
    myList.insertAtHead(3);
    myList.insertAtHead(7);
    myList.insertAtHead(1);
    myList.insertAtHead(9);

    // Display list
    cout << "Original List: ";
    myList.display();

    // Reverse list
    myList.reverse();

    // Display list after reversal

    cout << endl << "List after reversal: ";
    myList.display();

    return 0;

}