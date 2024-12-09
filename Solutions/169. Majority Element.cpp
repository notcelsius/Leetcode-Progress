// Date Completed: 12/9/2024

// Leetcode Problem: https://leetcode.com/problems/majority-element/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // follows the boyer-moore voting algorithm which can be used to find the majority element if it exists
        // this works because 1 element should always be dominating the polls
        // the moment we see that the element is not dominating, find a new candidate
        int candidate = nums[0];    // set candidate to 0th element
        int count = 0;              // set count to 0

        for (int num : nums) {
            if (count == 0) {       // if the count is 0, then this means the old candidate was not dominating with more than n/2 votes

                candidate = num;    // so we set it to a new candidate
            }
            count += (candidate == num) ? 1 : -1;   // if num is equal to the candidate add a vote to them
                                                    // if num is not the new candidate take a vote away from them
        }

        return candidate;
    }
};