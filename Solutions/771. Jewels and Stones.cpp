// Date Completed: 12/7/2024

// Leetcode Problem: https://leetcode.com/problems/jewels-and-stones/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> typesOfJewels;  // use an unordered set for O(1) find operation
        for (char jewel : jewels) { // adds all the jewels to the set
            typesOfJewels.insert(jewel);
        }
        int numOfJewels = 0;    // keeps tracks of jewels in stones
        for (char stone: stones) {   // goes through all the stones
            if (typesOfJewels.contains(stone)) {    // if the stone is a jewel
                numOfJewels++;  // increment number of jewels
            }
        }
        return numOfJewels; // returns number of jewels
    }
};