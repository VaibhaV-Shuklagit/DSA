#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Swap 2 Numbers using bitwise Operations
void Swap(int& a, int& b)
{
    a = a ^ b;
    b = a ^ b; // (a ^ b) ^ b => a
    a = a ^ b; // (a ^ b) ^ a(b has become a) => b
}

// // Check if ith bit is set or not
// There are two Ways to do that:

// 1. using Left shift operator: 
// if(N & (1 << i)) then YES else NO

// 2. using Right shift operator:
// if((N >> i) & 1) then YES else NO

// // Set ith Bit
// (N | (1 << i)) Taking the OR

// // Clear ith Bit
// (N & ( ~(1 << i) )) // Take the NOT and then AND with the num

// // Toggle ith Bit
// (N ^ (1 << i))

// // Remove the last Set Bit (RightMost)
// (N & (N - 1))

// // Check if the Number is a power of 2 
// after removing the rightmost bit if the num get equals to zero then it's a power of 2 else No
// if(N & (N - 1) == 0) then YES else NO

// Count Number of Set Bits
int Count_Set_Bits(int n)
{
    int cnt = 0;
    while(n != 0)
    {
        n = (n & (n - 1));
        cnt++; 
    }
    return cnt;
} // TC --> O(number of set bits) or O(31) [Max for INT]

// // check if num is odd or not
// if((N & 1) == 1) then YES else NO
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a = 5;
    int b = 3;
    cout << "Before: " << a << " " << b << "\n";
    swap(a, b);
    cout << "After: " << a << " " << b << "\n";
    
    int cnt = __builtin_popcount(a); // inbuilt function to count set bits  
    
    cout << "no. of bits: " << Count_Set_Bits(a) << "\n";
    return 0;
}