#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int Minimum_Bits_to_Flip(int start, int goal)
{
return __builtin_popcount(start ^ goal); // it's the fatest way 
} // TC --> O(1)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int start = 10;
    int goal = 7;

    cout << Minimum_Bits_to_Flip(start, goal) << "\n";
    return 0;
}