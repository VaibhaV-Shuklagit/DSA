#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void finder(vector<string> &ans, vector<string> &combination, string &build, int idx1, int idx2, int limit)
    {
        if (build.size() >= limit)
        {
            if (build.size() == limit)
                ans.push_back(build);
            return;
        }
        if (idx1 >= combination.size())
            return;
        if (idx2 >= combination[idx1].size())
            return;

        build.push_back(combination[idx1][idx2]);
        finder(ans, combination, build, idx1 + 1, 0, limit);
        build.pop_back();
        finder(ans, combination, build, idx1, idx2 + 1, limit);
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> letters = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combination;
        for (int i = 0; i < digits.size(); i++)
        {
            combination.push_back(letters[digits[i] - '0']);
        }
        vector<string> ans;
        string build;
        finder(ans, combination, build, 0, 0, digits.size());
        return ans;
    }
};

int main()
{
    Solution solver;

    string testInput = "23";

    vector<string> result = solver.letterCombinations(testInput);
    cout << "[ ";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << " ]" << endl;

    return 0;
}
