#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        ll sum = 0;
        int maxelem = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            maxelem = max(b[i], maxelem);
            c[i] = ((k - (i + 1)) * (maxelem)) + sum;
            if ((k - (i + 1)) == 0)
                break;
        }
        ll maxele = *max_element(c.begin(), c.end());
        if (maxele > sum)
            cout << maxele << "\n";
        else
            cout << sum << "\n";
    }
    return 0;
}