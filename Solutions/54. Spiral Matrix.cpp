// Date Completed: 12/7/2024

// Leetcode Problem: https://leetcode.com/problems/spiral-matrix/

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result; // stores the numbers traversed in the matrix
        int top = 0;    // keeps track of the top of the matrix
        int bottom = matrix.size() - 1; // keeps track of the bottom of the matrix
        int left = 0; // keeps track of the left of the matrix
        int right = matrix[0].size() - 1; // keeps track of the right of the matrix
        int numbers = matrix.size() * matrix[0].size(); // number of squares in the matrix which is how many traversals need to be done
        while (numbers > 0) {   // while there are still numbers that have not been traversed
        // general pattern of traversal will be left, down, right, up
            // go right on the top row until hit the right column
            for (int c = left; c <= right && numbers > 0; c++) {
                result.push_back(matrix[top][c]);   // get the number and push it down
                numbers--;  // decrement the amount of numbers left there are
            }
            top++; // move the top row down one
            // go down on the right column until hit bottom row
            for (int r = top; r <= bottom && numbers > 0; r++) {
                result.push_back(matrix[r][right]);
                numbers--;
            }
            right--;    // move right row left one
            // go left on the bottom row until hit left column
            for (int c = right; c >= left && numbers > 0; c--) {
                result.push_back(matrix[bottom][c]);
                numbers--;
            }
            bottom--; // move bottom up one
            // go up on left column until hit top row
            for (int r = bottom; r >= top && numbers > 0; r--) {
                result.push_back(matrix[r][left]);
                numbers--;
            }
            left++; // move left column right one
        }
        return result;
        
    }
};