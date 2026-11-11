#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();

        ll idx = 1LL << n; // Initalizing no of ways of selection choices i.e..if(n == 3){{00},{01},{10},{11}}

        vector<vector<int>> ans;

        for (ll i = 0; i < idx; i++) // travesing through the no of selection choices
        {
            vector<int> temp;
            for (int j = 0; j < n; j++) // choosing the elements
            {
                ll mask = 1ll << j;
                if (mask & i)
                    temp.push_back(nums[j]); // if the bit is set include the number
            }
            ans.push_back(temp);
        }

        return ans;
    } // TC --> O(N*(2^N))
    // SC --> O(N*(2^N))
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