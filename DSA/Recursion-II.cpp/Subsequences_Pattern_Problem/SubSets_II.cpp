#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void finder(std::vector<std::vector<int>> &ans, std::vector<int> &build, int idx, std::vector<int> &nums)
    {
        // Base case: Add the current built subset to the answers
        ans.push_back(build);

        for (int i = idx; i < nums.size(); ++i)
        {
            // If the element is a duplicate of the previous element
            // AND it's not the first element we are picking at this level, skip it.
            if (i > idx && nums[i] == nums[i - 1])
            {
                continue;
            }

            // Include nums[i] in the current subset
            build.push_back(nums[i]);

            // Move to the next element
            finder(ans, build, i + 1, nums);

            // Backtrack: Remove nums[i] to try other combinations
            build.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> build;

        // Sort the input array to bring duplicates next to each other
        std::sort(nums.begin(), nums.end());

        // Start the recursive backtracking
        finder(ans, build, 0, nums);

        return ans;
    }
};

int main()
{
    Solution solver;

    std::vector<int> nums = {1, 2, 2};

    std::vector<std::vector<int>> result = solver.subsetsWithDup(nums);

    std::cout << "Unique Subsets (Total: " << result.size() << "):\n";
    for (const auto &subset : result)
    {
        std::cout << "[";
        for (size_t i = 0; i < subset.size(); ++i)
        {
            std::cout << subset[i] << (i == subset.size() - 1 ? "" : ", ");
        }
        std::cout << "]\n";
    }

    return 0;
}
