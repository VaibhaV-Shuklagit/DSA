#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void finder(vector<vector<int>> &ans, vector<int> &build, int idx, vector<int> &nums)
    {
        // Base case: Once we've made a decision for every element
        if (idx == nums.size())
        {
            ans.push_back(build);
            return;
        }

        // Choice 1: Include the current element
        build.push_back(nums[idx]);
        finder(ans, build, idx + 1, nums);

        // Backtrack: Remove the current element to try the other choice
        build.pop_back();

        // Choice 2: Exclude the current element
        finder(ans, build, idx + 1, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> build;
        finder(ans, build, 0, nums);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> allSubsets = solution.subsets(nums);

    for (int i = 0; i < allSubsets.size(); ++i)
    {
        cout << "  [";
        for (int j = 0; j < allSubsets[i].size(); ++j)
        {
            cout << allSubsets[i][j];
            if (j < allSubsets[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]\n";
    }
    return 0;
}