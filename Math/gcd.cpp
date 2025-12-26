/*
GCD of Two Numbers
    Find the Greatest Common Divisor (GCD) of two numbers
    using Euclidean Algorithm.

Time Complexity: O(log(min(a, b)))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {

        // Euclidean Algorithm
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }

        // final value of a is GCD
        return a;
    }
};
