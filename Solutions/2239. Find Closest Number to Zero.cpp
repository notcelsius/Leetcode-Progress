// Date Completed: 12/3/2024

// Leetcode Problem: https://leetcode.com/problems/find-closest-number-to-zero/description/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closestNumber = nums[0];    // keeps track of closest number to 0
        for (int num: nums) {   // goes through all numbers in the vector
            if (abs(num) < abs(closestNumber)) {    // if the number is closer to 0 than the closestNumber (3 is closer to 0 than 4)
                closestNumber = num;    // set the number as the closest number to 0
            }
            else if (abs(num) == abs(closestNumber)) {  // if the number is same distance from 0 as the closestNumber (-4 same distance as 4)
                closestNumber = max(num, closestNumber);    // get the larger of the 2 numbers and set it to the closest number to 0
            }
        }
        return closestNumber;   // return the closest number to 0
    }
};