// Date Completed: 12/30/2024

// Leetcode Problem: https://leetcode.com/problems/valid-perfect-square/

// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1;
        long r = num;
        while (l <= r) {
            long mid = l + (r - l)/2;   // use long to not run into mid * mid overflow errors
            if ((mid * mid) == num) {
                return true;
            }
            if ((mid * mid) > num) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return false;
    }
};