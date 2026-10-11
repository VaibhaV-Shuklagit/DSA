#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    ll n, four;
    four = 0;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < 4)
            nums.push_back(x);
        else
            four++;
    }
    sort(nums.begin(), nums.end());
    int low = 0;
    int high = n - 1;
    int cur = 1;
    int rem = 4;
    while (low <= high)
    {
        if (low == high)
        {
            if (rem <= nums[high])
                rem -= nums[low];
            else
                cur++;
            low++;
        }
        else
        {
            if (nums[low] + nums[high] <= rem)
            {
                rem -= nums[low] + nums[high];
                low++;
                high--;
            }
            else if(rem >= nums[high]) rem-=nums[high--];
            else if(rem >= nums[low]) rem-=nums[low++];
            else{
                cur++;
                rem = 4;
            }
        }
    }
    cout << cur + four<< "\n";
    //}
    return 0;
}