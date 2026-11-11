#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    vector<ll> temp = nums;
    ll ops1 = 0;
    ll cost1 = 0;
    int mid = -1;
    if(n & 1) mid = n/2;
    else mid = n/2 - 1;
    int i = mid;
    while(i >= 0)
    {      
        nums[i]+=ops1;
        ops1+=(nums[mid] - nums[i]);
        cost1+=(nums[mid] - temp[i]);
        i--;
    }
    ll ops2 = 0;
    ll cost2 = 0;
    int j = mid;
    while(j < n)
    {   
        nums[j]-=ops2;
        ops2+=(nums[j] - nums[mid]);
        cost2+=(temp[j] - nums[mid]);
        j++;
    }
    cout << cost1 + cost2 << " " << ops1 + ops2 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
