#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReachFrom(int index, vector<int> &nums, vector<int> &memo)
    {
        /*
           If index reaches or crosses the last position,
           the destination is reachable.
        */
        if (index >= nums.size() - 1)
        {
            return true;
        }

        /*
           If this index was already solved, reuse the
           stored answer instead of recalculating it.
        */
        if (memo[index] != -1)
        {
            return memo[index] == 1;
        }

        /*
           farthest stores the last index that can be tried
           from the current position.
        */
        int farthest = min((int)nums.size() - 1, index + nums[index]);

        for (int next = index + 1; next <= farthest; next++)
        {
            /*
               If any reachable next index can reach the end,
               the current index is also successful.
            */
            if (canReachFrom(next, nums, memo))
            {
                memo[index] = 1;
                return true;
            }
        }

        /*
           If no jump from this index works, mark it as
           unable to reach the last index.
        */
        memo[index] = 0;
        return false;
    }

    /*
       Returns true if the last index can be reached
       from the first index using DP memoization.
    */
    bool canJump_BF(vector<int> &nums)
    {
        /*
           memo stores -1 for unknown, 0 for false,
           and 1 for true.
        */
        vector<int> memo(nums.size(), -1);

        return canReachFrom(0, nums, memo);
    } // TC --> O(N^2)
    // SC --> O(N) [STACK SPACE]

    /*
       Returns true if the last index can be reached
       from the first index using greedy reach tracking.
    */
    bool canJump_Optimal(vector<int> &nums)
    {
        /*
           farthest stores the maximum index that can be
           reached using the jumps seen so far.
        */
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            /*
               If the current index is beyond farthest,
               this position cannot be reached.
            */
            if (i > farthest)
            {
                return false;
            }

            /*
               From a reachable index, try to extend the
               farthest reachable position.
            */
            farthest = max(farthest, i + nums[i]);

            /*
               If the reachable range already covers the
               last index, the answer is confirmed.
            */
            if (farthest >= nums.size() - 1)
            {
                return true;
            }
        }
        return true;
    } // TC --> O(N)
    // SC --> O(1)
};

// Driver code starts
int main()
{
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << (solution.canJump_Optimal(nums) ? "true" : "false") << endl;

    return 0;
}