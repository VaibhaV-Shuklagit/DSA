#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /*
    Returns the minimum jumps needed from the given index
    to reach the last index using recursion and memoization.
    */
    int solve(int index, vector<int> &nums, vector<int> &memo)
    {
        int n = nums.size();

        // If the current index has reached the destination,
        // no more jumps are needed.
        if (index >= n - 1)
        {
            return 0;
        }

        // If this index was already solved,
        // reuse the stored answer.
        if (memo[index] != -1)
        {
            return memo[index];
        }

        // This stores the best answer found from this index.
        int minJumps = INT_MAX;

        // This prevents checking jumps beyond the array boundary.
        int farthestJump = min(n - 1, index + nums[index]);

        for (int nextIndex = index + 1; nextIndex <= farthestJump; nextIndex++)
        {
            int nextJumps = solve(nextIndex, nums, memo);

            // Use this path only if the next index can reach the end.
            if (nextJumps != INT_MAX)
            {
                minJumps = min(minJumps, 1 + nextJumps);
            }
        }

        memo[index] = minJumps;
        return memo[index];
    }

public:
    /*
    Returns the minimum number of jumps needed
    to reach the last index.
    */
    int jump_BF(vector<int> &nums)
    {
        // Stores solved answers for each index.
        vector<int> memo(nums.size(), -1);

        return solve(0, nums, memo);
    } // TC --> O(N^2)
    // SC --> O(1)

    /*
    Returns the minimum number of jumps needed
    to reach the last index using greedy ranges.
    */
    int jump_Optimal(vector<int> &nums)
    {
        int n = nums.size();

        // A single index is already the destination.
        if (n <= 1)
        {
            return 0;
        }

        // Stores how many jumps have been used so far.
        int jumps = 0;

        // Marks the end of the range covered by current jumps.
        int currentEnd = 0;

        // Stores the farthest index reachable from the current range.
        int farthest = 0;

        for (int i = 0; i < n - 1; i++)
        {
            // Try to extend the next reachable range from this index.
            farthest = max(farthest, i + nums[i]);

            // When the current range ends, one more jump is needed.
            if (i == currentEnd)
            {
                jumps++;
                currentEnd = farthest;

                // Once the last index is inside the range,
                // no more scanning is needed.
                if (currentEnd >= n - 1)
                {
                    break;
                }
            }
        }

        return jumps;
    } // TC --> O(N)
    // SC --> O(1)
};

// Driver code starts
int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    Solution solution;
    cout << solution.jump_Optimal(nums);

    return 0;
}