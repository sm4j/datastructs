#include <iostream>
#include <vector>
using namespace std;

// Node class represents each element in the linked list
class Node {
public:
    int key;
    int value;
    Node* next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class ArrayList {
private:
    vector<Node*> arraylist_1;  // std::vector to store linked lists

public:
    ArrayList() {
        // Initialize the array list with 8 elements, all initialized to nullptr
        arraylist_1.resize(8, nullptr);
    }

    // Insert an element using a hash function (key mod 8)
    void insertWithHash(int key, int value) {
      //TODO: compute the index
        int index = key % 8;

      //TODO: if nothing is there add the node at the computed location
        if (arraylist_1[index] == nullptr) {

            arraylist_1[index] = new Node(key, value);
            return;

        }

      //TODO: if there is a collision, traverse the linked list and add the new node at the end
        Node* current = arraylist_1[index];

        while (current->next != nullptr) {

            current = current->next;

        }

        current->next = new Node(key, value);

    }

    // Delete a specific node with a given key using hash function
    void remove(int key) {
        //TODO: compute the index
        int index = key % 8;

        //TODO: check if there is anything at the computed index
        if (arraylist_1[index] == nullptr) {

            cout << "Node with key " << key << " not found." << endl;
            return;

        }
        
        Node* current = arraylist_1[index];
        Node* prev;

        //TODO: find the node with the specified key
        if (current->key == key) {
            arraylist_1[index] = current->next;
        }
        
        else {
            //Note: make sure to handle cases where it is at the head and in the middle of the list
            while (current != nullptr && current->key != key) {
                prev = current;
                current = current->next;
            }

            if (current == nullptr) {

                cout << "Node with key " << key << " not found." << endl;
                return;

            }
            
            //TODO: update the pointers correctly
            prev->next = current->next;
            //TODO: Delete the Node
            delete current;
            cout << "Node with key " << key << " removed succesfully!" << endl;
        }

    }

    // Display the elements of the array list
    void display() {
        cout << "Array List: ";
        for (int i = 0; i < arraylist_1.size(); ++i) {
            Node* current = arraylist_1[i];
            while (current != nullptr) {
                cout << "(" << current->key << "," << current->value << ") ";
                current = current->next;
            }
            cout << "| "; // Separate linked lists with a pipe symbol
        }
        cout << endl;
    }

    // Destructor to free memory
    ~ArrayList() {
        for (int i = 0; i < arraylist_1.size(); ++i) {
            Node* current = arraylist_1[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    ArrayList list;  // Create an array list 

    //test your code with a series of insertion and removal operations

    list.insertWithHash(36, 20); //36mod8 = 4
    list.display();

    list.insertWithHash(22, 43); //22mod8 = 6
    list.display();

    list.insertWithHash(20, 46); //20mod8 = 4
    list.display();

    list.insertWithHash(30, 4); //30mod8= 6
    list.display();

    list.remove(9);
    list.remove(36);
    list.display();

    return 0;
}
