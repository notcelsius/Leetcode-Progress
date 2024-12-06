// Date Completed: 12/7/2024

// Leetcode Problem: https://leetcode.com/problems/maximum-number-of-balloons/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // a is 0
        // b is 1
        // l is 2
        // n is 3
        // o is 4
        int letters[5] = {0};   // stores instances of a,b,l,n, and o
        // gets the number of instances of a,b,l,n, and o
        for (char letter: text) {
            if (letter == 'a') {
                letters[0]++;
            }
            else if (letter == 'b') {
                letters[1]++;
            }
            else if (letter == 'l') {
                letters[2]++;
            }
            else if (letter == 'n') {
                letters[3]++;
            }
            else if (letter == 'o'){
                letters[4]++;
            }
        }
        return min({letters[0], letters[1], letters[2]/2, letters[3], letters[4]/2});   // returns the limitting reagent for balloon in the provided text
    }
};