#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
int singleNumber(vector<int>& arr) {
        
        int result = 0; // x ^ 0 => x

        // Equal values cancel under XOR, so every repeated
        // pair disappears from the cumulative result.
        for (int num : arr) {
            result ^= num;
        }

        return result;
    } // TC --> O(N)
    // SC --> O(1)
}; 

int main() {
    vector<int> arr = {4, 1, 2, 1, 2};

    Solution solution;
    cout << solution.singleNumber(arr) << endl;

    return 0;
}