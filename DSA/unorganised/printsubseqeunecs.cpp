#include <iostream>
#include <vector>
using namespace std;

void printSubsequences(int ind, vector<int> &ds, int arr[], int n) {
    // BASE CASE: When we run out of elements
    if (ind == n) {
        // Print the collected subsequence
        if (ds.size() == 0) {
            cout << "{}" << endl; // Empty subsequence
        } else {
            for (auto it : ds) {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    // CHOICE 1: TAKE (Pick the element at 'ind')
    ds.push_back(arr[ind]); // Add to bag
    printSubsequences(ind + 1, ds, arr, n); // Move to next index
    
    // CHOICE 2: NOT TAKE (Don't pick, or "Backtrack")
    ds.pop_back(); // Remove the element we just added to restore state
    printSubsequences(ind + 1, ds, arr, n); // Move to next index
}

int main() {
    int arr[] = {3, 1, 2};
    int n = 3;
    
    vector<int> ds; // To store the current subsequence
    printSubsequences(0, ds, arr, n);
    
    return 0;
}