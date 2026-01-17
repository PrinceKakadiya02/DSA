/*
LeetCode 3100
Water Bottles II

Time Complexity: O(total exchanges)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int totalDrank = 0;
        int emptyBottles = 0;

        // continue while we have full bottles
        while (numBottles > 0) {

            // drink all current bottles
            totalDrank += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;

            // exchange empty bottles
            while (emptyBottles >= numExchange) {
                emptyBottles -= numExchange;
                numExchange++;   // exchange cost increases
                numBottles++;    // get one new bottle
            }
        }

        return totalDrank;
    }
};

/*
Input:  numBottles = 13, numExchange = 6
Output: 15

Input:  numBottles = 10, numExchange = 3
Output: 13

Input:  numBottles = 1, numExchange = 2
Output: 1
*/
