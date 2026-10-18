#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static bool comp(const pair<ll,ll>& p1, const pair<ll, ll>& p2) {
    return p1.second < p2.second;
}
    int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<pair<ll, ll>> nums(n);
        vector<ll> powers(q);
        for(int i = 0; i < n; i++) 
        {
            cin >> nums[i].first;
            nums[i].second = i + 1;
        }
        for(int i = 0; i < q; i++) cin >> powers[i];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < q; i++)
        {
        for(int j = n - 1; j >= 0; j--)
        {
        if(nums[j].first % 2 != 0) continue;
        else if(nums[j].first % (ll)pow(2,powers[i]) == 0)
        {
            nums[j].first+= (ll)pow(2,powers[i] - 1);
        }
        else break;
        }
    }
    sort(nums.begin(), nums.end(), comp);
    for(int i = 0; i < n; i++) cout << nums[i].first <<" ";
    cout << "\n";
}
    return 0;
}
