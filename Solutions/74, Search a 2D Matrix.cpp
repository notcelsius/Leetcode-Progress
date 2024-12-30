// Date Completed: 12/30/2024

// Leetcode Problem: https://leetcode.com/problems/search-a-2d-matrix/

// Time Complexity: O(logn + logm)
// Space Complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0;
        int r = rows - 1;
        int row = -1;
        // do binary search to find the right row
        while (l <= r) {
            int mid = (l + r)/2;
            if (target >= matrix[mid][0] && target <= matrix[mid][cols - 1]) {
                row = mid;
                break;
            }
            if (target < matrix[mid][0]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (row == -1) {
            return false;
        }
        l = 0;
        r = cols - 1;
        // once in the right row, do binary search on that row
        while (l <= r) {
            int mid = (l + r)/2;
            if (target == matrix[row][mid]) {
                return true;
            }
            if (target > matrix[row][mid]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return false;
    }
};