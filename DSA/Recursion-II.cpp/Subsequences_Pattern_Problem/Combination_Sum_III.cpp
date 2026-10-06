#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void subsequences(vector<vector<int>> &ans, int idx, vector<int> &nums, int sum, int n, int k)
    {
        // Target Reached Pruning & Base Case
        if (sum >= n)
        {
            if (nums.size() == k && sum == n)
                ans.push_back(nums);
            return;
        }

        // Early Pruning: Stop if we already picked too many numbers
        // OR if we run out of valid single-digit numbers (1-9)
        if (nums.size() >= k || idx >= 10)
            return;

        // Option 1: Pick the current number
        nums.push_back(idx);
        subsequences(ans, idx + 1, nums, sum + idx, n, k);
        nums.pop_back();

        // Option 2: Don't pick the current number
        subsequences(ans, idx + 1, nums, sum, n, k);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> nums;
        subsequences(ans, 1, nums, 0, n, k);
        return ans;
    }
};

int main()
{
    Solution solver;

    int k = 3;
    int n = 9;

    vector<vector<int>> result = solver.combinationSum3(k, n);

    for (const auto &combination : result)
    {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i)
        {
            cout << combination[i] << (i == combination.size() - 1 ? "" : ", ");
        }
        cout << "]\n";
    }

    return 0;
}
