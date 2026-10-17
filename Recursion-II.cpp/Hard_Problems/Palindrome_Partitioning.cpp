#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function to check if a substring is a palindrome
    bool checker(const string &str)
    {
        int low = 0;
        int high = str.size() - 1;
        while (low < high)
        {
            if (str[low] != str[high])
                return false;
            low++;
            high--;
        }
        return true;
    }

    // Backtracking function to build all valid palindrome partitions
    void builder(string &s, int idx, vector<vector<string>> &ans, vector<string> &build)
    {
        if (idx >= s.size())
        {
            ans.push_back(build);
            return;
        }

        for (int i = idx; i < s.size(); i++)
        {
            string temp = s.substr(idx, i - idx + 1);

            // If the current substring is not a palindrome, skip this path
            if (!checker(temp))
                continue;

            build.push_back(temp);
            builder(s, i + 1, ans, build);
            build.pop_back(); // Backtrack
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> build;
        builder(s, 0, ans, build);
        return ans;
    }
};

int main()
{
    Solution solver;

    string s1 = "aab";
    cout << "Input string: \"" << s1 << "\"" << endl;
    vector<vector<string>> result1 = solver.partition(s1);

    cout << "Palindrome Partitions:" << endl;
    for (const auto &partition : result1)
    {
        cout << "[ ";
        for (const string &str : partition)
        {
            cout << "\"" << str << "\" ";
        }
        cout << "]" << endl;
    }
    return 0;
}
