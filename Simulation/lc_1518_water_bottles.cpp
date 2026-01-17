/*
LeetCode 1518
Water Bottles

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int totalDrank = 0;
        int emptyBottles = 0;

        // continue while we have full bottles to drink
        while (numBottles > 0) {

            // drink all current bottles
            totalDrank += numBottles;
            emptyBottles += numBottles;

            // exchange empty bottles for new full bottles
            numBottles = emptyBottles / numExchange;

            // remaining empty bottles after exchange
            emptyBottles = emptyBottles % numExchange;
        }

        return totalDrank;
    }
};


/*
Input:  numBottles = 9, numExchange = 3
Output: 13

Input:  numBottles = 15, numExchange = 4
Output: 19

Input:  numBottles = 5, numExchange = 5
Output: 6
*/
