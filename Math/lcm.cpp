/*
LCM of Two Numbers
    Find the Least Common Multiple (LCM) of two numbers
    using the relation between LCM and GCD.

Formula:
LCM(a, b) = (a / GCD(a, b)) * b

Time Complexity: O(log(min(a, b)))
Space Complexity: O(1)
*/

class Solution {
public:
    int gcd(int a, int b) {

        // Euclidean Algorithm
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    int lcm(int a, int b) {

        // LCM formula using GCD
        return (a / gcd(a, b)) * b;
    }
};
