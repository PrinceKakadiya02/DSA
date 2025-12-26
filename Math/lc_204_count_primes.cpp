/*
LeetCode 204
Count Primes
    Count the number of prime numbers strictly less than n
    using the Sieve of Eratosthenes technique.

Time Complexity: O(n log log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int countPrimes(int n) {

        // count of prime numbers
        int count = 0;

        // prime[i] will be true if i is prime
        vector<bool> prime(n + 1, true);

        // 0 and 1 are not prime
        if (n > 0) prime[0] = false;
        if (n > 1) prime[1] = false;

        // apply sieve
        for (int i = 2; i < n; i++) {

            // if current number is prime
            if (prime[i]) {
                count++;

                // mark all multiples of i as non-prime
                for (int j = 2 * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        return count;
    }
};
