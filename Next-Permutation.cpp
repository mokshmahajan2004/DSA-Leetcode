#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int ind = -1;
        int n = A.size();

        // Step 1: Find the first decreasing element from the end
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                ind = i;
                break;
            }
        }

        if (ind == -1) {
            // Last permutation, so reverse to get first
            reverse(A.begin(), A.end());
        } else {
            // Step 2: Find just larger element and swap
            for (int i = n - 1; i > ind; i--) {
                if (A[i] > A[ind]) {
                    swap(A[i], A[ind]);
                    break;
                }
            }
            // Step 3: Reverse suffix
            reverse(A.begin() + ind + 1, A.end());
        }

        // Print the result
        for (int num : A) {
            cout << num << " ";
        }
        cout << endl;
    }
};