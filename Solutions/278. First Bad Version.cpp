// Date Completed: 12/30/2024

// Leetcode Problem: https://leetcode.com/problems/first-bad-version/description/

// Time Complexity: O(logn)
// Space Complexity: O(1)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // versions 1 - n
        int l = 1;
        int r = n;
        int first = 1;
        while (l <= r) {    // binary search
            int mid = l + (r - l)/2;    // do this so there is no integer overflow
            if (isBadVersion(mid)) {    // if is bad version, start looking for an earlier bad version
                first = mid;
                r = mid - 1;
            }
            else {                      // first bad version occurs later
                l = mid + 1;
            }
        }
        return first;
    }
};