#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> nums(n);
        int evens = 0;
        int odds = 0;
        for (int i = 0; i < n; i++)
        {
             cin >> nums[i];
            if(nums[i] % 2 == 0) evens++;
            else odds++;
        }
        if(n == 2){
            if(evens == 1 && odds == 1) cout << "Larpity" << "\n";
            else cout << "Moggity" << "\n";
        }
        else if(n == 3&& evens == 0)
        {
            cout << "Larpity" << "\n";
        }
        else cout << "Moggity" << "\n";
    }
    return 0;
}