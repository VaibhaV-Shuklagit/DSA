#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool hasAllChars(vector<int> &freq)
    {
        // Check if we have at least one of each character
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }

public:
    int numberOfSubstrings_SW(string s) // Sliding Window Method
    {
        int len = s.length();
        int left = 0, right = 0;
        // Track frequency of a, b, c
        vector<int> freq(3, 0);
        int total = 0;

        while (right < len)
        {
            // Add character at right pointer to frequency array
            char curr = s[right];
            freq[curr - 'a']++;

            // While we have all required characters
            while (hasAllChars(freq))
            {
                // All substrings from current window to end are valid
                // Add count of these substrings to result
                total += len - right;

                // Remove leftmost character and move left pointer
                char leftChar = s[left];
                freq[leftChar - 'a']--;
                left++;
            }

            right++;
        }

        return total;
    }

int numberOfSubstrings_LI(string s) // Last Visited Index Method
    { 
        int len = s.length();
        // Track last position of a, b, c
        vector<int> lastPos = {-1, -1, -1};
        int total = 0;

        for (int pos = 0; pos < len; pos++)
        {
            // Update last position of current character
            lastPos[s[pos] - 'a'] = pos;

            // Add count of valid substrings ending at current position
            // If any character is missing, min will be -1
            // Else min gives leftmost required character position
            total += 1 + min({lastPos[0], lastPos[1], lastPos[2]});
        }

        return total;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    string s = "abcabc";
    
    cout << sol.numberOfSubstrings_LI(s) << "\n";
}