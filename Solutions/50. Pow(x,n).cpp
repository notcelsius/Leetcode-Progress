// Date Completed: 12/22/2024

// Leetcode Problem: https://leetcode.com/problems/powx-n/

// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        else if (n == INT_MIN) {
            if (x < 0) {
                return (-1/myPow(x,INT_MAX));
            }
            return (1/myPow(x,INT_MAX));
        }
        else if (n < 0) {
            return (1/myPow(x, -n));
        }
        else if (n % 2 == 1) {
            return x * myPow(x, n-1);
        }
        else {
            return myPow(x * x, n/2);
        }
        return 0;
    }
};