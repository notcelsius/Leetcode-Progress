// Date Completed: 12/9/2024

// Leetcode Problem: https://leetcode.com/problems/squares-of-a-sorted-array/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // problem works because after squaring the numbers the largest numbers are always on the outside of nums
        // ex: -1, 0, 4 becomes 1, 0 , 16 after squaring the numbers
        vector<int> result(nums.size());    // stores the result
        // using 2 pointer approach
        int left = 0;
        int right = nums.size() - 1;
        // puts in the numbers from right to left in result, so largest to smallest
        for (int i = result.size() - 1; i >= 0; i--) {
            if (abs(nums[left]) < abs(nums[right])) {   // the right side of nums is greater than left side
                result[i] = nums[right] * nums[right];  // puts it at the ith index in result
                right--;    // decrement the right pointer
            }
            else {  // the left side of nums is greater than the right side
                result[i] = nums[left] * nums[left];    // puts it at the ith index in result
                left++; // increase the left pointer
            }
        }
        return result;
    }
};