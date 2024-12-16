// Date Completed: 12/16/2024

// Leetcode Problem: https://leetcode.com/problems/container-with-most-water/description/

// Time Complexity: O(n)
// Space Complexity: O(1)

// using 2 ptrs method
class Solution {
public:
    int trap(vector<int>& height) {
        // If the input height array is empty, no water can be trapped.
        if (height.size() == 0) {
            return 0;
        }

        // Initialize pointers for the left (l) and right (r) ends of the array.
        int l = 0, r = height.size() - 1;

        // Initialize variables to store the maximum heights seen so far from the left and right.
        int leftMax = height[l], rightMax = height[r];

        // Initialize a variable to store the total trapped water.
        int res = 0;

        // Use a two-pointer approach to traverse the array until the pointers meet.
        while (l < r) {
            // If the maximum height from the left is less than that from the right:
            if (leftMax < rightMax) {
                l++;  // Move the left pointer to the right.
                leftMax = max(leftMax, height[l]);  // Update the left maximum height.
                res += leftMax - height[l];  // Add trapped water at the current left pointer.
            } else {
                r--;  // Otherwise, move the right pointer to the left.
                rightMax = max(rightMax, height[r]);  // Update the right maximum height.
                res += rightMax - height[r];  // Add trapped water at the current right pointer.
            }
        }

        // Return the total amount of trapped water.
        return res;
    }
};
