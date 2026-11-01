#include<bits/stdc++.h>
using namespace std;

// Decimal to Binary String
string convert_to_Binary(int n)
{
     if (n == 0) return "0";

    string res = "";
    while(n > 0)
    {
        if(n % 2 == 1) res+='1';
        else res+='0';
        n/=2;
    }
    reverse(res.begin(), res.end());
    return res;
} // TC --> O(LogN)
// SC --> O(LogN)

// Binary to Decimal
int convert_to_Decimal(string& num)
{
    int len = num.length();
    int p2 = 1;
    int n = 0;
    for(int i = len - 1; i >=0 ; i--)
    {
        if(num[i] == '1') n+=p2;
        p2*=2;
    }
    return n;
}


// Computer Stores Neg Values into 2's Complement form
// int range --> [-2^31 to 2^31 - 1]
// unsigned int range --> [0 to 2^32 - 1]
// long long range --> [-2^63 to 2^63 - 1]
// unsigned long long range --> [0 to 2^64 - 1]

// AND --> all true => true
//     --> 1 false => false

// OR --> 1 true => true
//    --> all false => false 

// XOR --> if no. of 1s odd => 1
//     --> if no. of 1s even => 0

// NOT --> 1. flip the bits
//     --> 2. then checks after flipping the bits if num got neg sign or pos sign at last bit
//     --> 3. if it's neg sign then it takes the 2's Complement form of remaining bits except sign bit and stores in the comp
//     --> 4. if it's pos sign then it stores as it 

// ~(-6) => 5
// ~(5) => -6

// x << k => x * (2 ^ k)
// x >> k => x / (2 ^ k)

int main()
{
    int n = 13;
    string num = convert_to_Binary(n);

    // Converts to a 32-bit binary string and strips leading zeros 
    string res = bitset<32>(n).to_string(); // (inbuilt function)
    
    cout << num << "\n";
    cout << convert_to_Decimal(num) << "\n";
}