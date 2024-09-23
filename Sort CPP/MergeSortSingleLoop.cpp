    #include <iostream>
    #include <vector>
    using namespace std;
    
    // Function to merge two sorted arrays and return the merged sorted array
    vector<int> merge(const vector<int>& left, const vector<int>& right) {
        vector<int> merged;
        size_t i = 0, j = 0;
    
        // Merge sorted arrays 'left' and 'right' into 'merged'
        while (i < left.size() || j < right.size()) {
            if ((i < left.size() && left[i] <= right[j]) || j >= right.size()) {
                merged.push_back(left[i]);
                ++i;
            } else {
                merged.push_back(right[j]);
                ++j;
            }
        }

        return merged;
    }
    
    // Function to perform Merge Sort on an array
    void mergeSort(vector<int>& arr) {
        if (arr.size() <= 1) {
            return; // Base case: array is already sorted or empty
        }
    
        // Divide the array into two halves
        size_t mid = arr.size() / 2;
        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());
    
        // Recursively sort the left and right halves
        mergeSort(left);
        mergeSort(right);
    
        // Merge the sorted halves back into 'arr'
        arr = merge(left, right);
    }
    
    int main() {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    
        // Display the original array
        cout << "Original Array: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    
        // Sort the array using Merge Sort
        mergeSort(arr);
    
        // Display the sorted array
        cout << "Sorted Array: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    
        return 0;
    }
