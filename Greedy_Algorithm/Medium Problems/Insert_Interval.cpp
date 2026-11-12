#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert_BF(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        // Add the new interval to the original list
        intervals.push_back(newInterval);

        // Sort the intervals by their start times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        // Iterate through and merge overlapping intervals
        for (int i = 0; i < intervals.size(); i++)
        {
            if (merged.empty() || merged.back()[1] < intervals[i][0])
            {
                merged.push_back(intervals[i]);
            }
            else
            {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
        }

        return merged;
    } // TC --> O(NlogN)
    // SC --> O(N)

    vector<vector<int>> insert_Optimal(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        // Phase 1: Add all intervals completely before the new interval
        while (i < n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }

        // Phase 2: Merge all overlapping intervals into one massive interval
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Add the fully merged new interval
        result.push_back(newInterval);

        // Phase 3: Add all remaining intervals
        while (i < n)
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    } // TC --> O(N)
    // SC --> O(N)
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = sol.insert_Optimal(intervals, newInterval);

    cout << "Merged Intervals: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[" << result[i][0] << ", " << result[i][1] << "] ";
    }
    cout << endl;
    return 0;
}