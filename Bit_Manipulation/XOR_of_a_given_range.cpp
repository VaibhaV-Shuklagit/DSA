#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long prefixXOR(long long n) {
        /*
         * This represents an empty prefix and also allows
         * the same range formula to work when L is 0.
         */
        if (n < 0) {
            return 0;
        }

        long long remainder = n % 4;

        /*
         * XOR from 0 through n follows a four-case pattern,
         * so only n % 4 is needed to determine the result.
         */
        if (remainder == 0) {
            return n;
        }

        if (remainder == 1) {
            return 1;
        }

        if (remainder == 2) {
            return n + 1;
        }

        return 0;
    }

public:
    long long findRangeXOR(long long L, long long R) {
        if (L > R) {
            return 0;
        }

        /*
         * The prefix before L appears in both XOR groups
         * and cancels, leaving only values from L through R.
         */
        return prefixXOR(R) ^ prefixXOR(L - 1);
    } // TC --> O(1)
    // SC --> O(1)
};

int main() {
    long long L = 3;
    long long R = 6;

    Solution solution;
    cout << solution.findRangeXOR(L, R) << endl;

    return 0;
}