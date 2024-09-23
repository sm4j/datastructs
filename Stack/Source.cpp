#include <stack>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

// The reversal function will return the reversed string and take
// the string to reverse as a parameter
string removeDupes(string full) {

	// Construct a stack with the char generic named temp
	stack<char> temp;

	// Declare/initialize counting variable, i, to 0
	int i = 0;

	// The length of the passed string is greater than 0, iterate
	while (i < full.length()) {

		// Check if the stack is empty or the current character is different from the top of the stack
		if (temp.empty() || full[i] != temp.top()) {

			// Push the current, unique character onto the stack
			temp.push(full[i]);
			i++;
		}

		else {
			// Pop the character from the stack as it's a duplicate of the previous one
			temp.pop();
			i++;
		}
	}

	// Check if the stack is empty after processing the entire string
	// This will happen if there are no unique characters
	if (temp.empty()) {
		return("Empty String");
	}

	else {

		// Declare and initialize an empty string to store the reversal result
		string reverse = "";

		// Pop characters from the stack and concatenate to the above string in reverse order
		while (!temp.empty()) {

			reverse = temp.top() + reverse;
			temp.pop();

		}

		// Return the reversed string, containing only unique characters
		return (reverse);
	}
}

int main() {

	string test = "apple";
	string test2 = "aabbcc";
	string test3 = "aadbbgccdga";
	string test4 = "excellent";
	string test5 = "maddam";
	
	cout << "Before: " << endl;
	cout << test << endl << test2 << endl << test3 << endl << test4 << endl << test5 << endl;

	cout << endl << "After: " << endl;
	cout << removeDupes(test) << endl;
	cout << removeDupes(test2) << endl;
	cout << removeDupes(test3) << endl;
	cout << removeDupes(test4) << endl;
	cout << removeDupes(test5);

	return 0;

}

/* Source: https://www.geeksforgeeks.org/remove-all-duplicate-adjacent-characters-from-a-string-using-stack/ */