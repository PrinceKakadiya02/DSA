/*
Prime Number Check

Time Complexity: O(√n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPrime(int n) {

        // numbers less than 2 are not prime
        if (n <= 1)
            return false;

        // check divisibility from 2 to √n
        for (int i = 2; i * i <= n; i++) {

            // if divisible, not a prime number
            if (n % i == 0)
                return false;
        }

        // no divisors found → prime
        return true;
    }
};
