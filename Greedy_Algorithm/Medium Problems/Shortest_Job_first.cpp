#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    ll solve(vector<int>& bt) {
        int n = bt.size();
        if (n <= 1) return 0;

        // Sort burst times in ascending order for Shortest Job First (SJF)
        sort(bt.begin(), bt.end());

        ll total_wait_time = 0;
        ll current_wait_time = 0;

        // The last process's burst time never contributes to anyone's waiting time,
        // so we only loop up to n - 1.
        for (int i = 0; i < n - 1; i++) {
            current_wait_time += bt[i];
            total_wait_time += current_wait_time;
        }

        return total_wait_time / n;
    } // TC --> O(NLogN)
    // SC --> O(1)
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter the number of processes: ";
    if (!(cin >> n) || n < 0) return 0;

    vector<int> burst_times(n);
    if (n > 0) {
        cout << "Enter the burst times: ";
        for (int i = 0; i < n; i++) {
            cin >> burst_times[i];
        }
    }

    Solution obj;
    ll avg_wait = obj.solve(burst_times);

    cout << "Average Waiting Time: " << avg_wait << "\n";

    return 0;
}
