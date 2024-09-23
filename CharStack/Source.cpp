#include <iostream>
#include <string>

using namespace std;

const size_t capacity = 100; // constant to allow you to adjust the capacity

class Stack {
private:
    char elements[capacity];
    size_t t; //variable to track the top element

public:
    // Constructor
    Stack() : t(-1) {}

    // Push element onto the stack
    void push(char element) {
        
        //check if the array is full
        if (t+1 < capacity) {
            t++; //increment the pointer to the space on top of the previous top
            elements[t] = element; 
        } else {
            cout << "Stack overflow!" << endl; 
        }
    }

    // Remove and return the top element from the stack
    char pop() {
        //make sure the stack is not empty
        if (t >=0) {
            return elements[t--];
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }

    // Return the top element from the stack
    char top() {
        if (t >= 0) {
            return elements[t];
        }
        // Return 0 if the stack is empty
        return -1;
    }

    // Check if the stack is empty
    bool empty() {
        return t == -1;
    }

    // Return the number of elements in the stack
    size_t size() {
        return t+1;
    }


    string removeDupes(string full) {

        Stack temp;
        int i = 0;

        while (i < full.length()) {

            if (temp.empty() || full[i] != temp.top()) {
                temp.push(full[i]);
                i++;
            }

            else {
                temp.pop();
                i++;
            }
        }

        if (temp.empty()) {
            return("Empty String");
        }

        else {
            string null = "";

            while (!temp.empty()) {

                null = temp.top() + null;
                temp.pop();

            }

            return (null);
        }
    }

};

int main() {

    // Create a stack of integers
    Stack myStack;

    myStack.removeDupes("aabbvcc");


    return 0;
}
