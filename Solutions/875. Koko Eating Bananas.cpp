// Date Completed: 1/2/2025

// Leetcode Problem: https://leetcode.com/problems/koko-eating-bananas/description/

// Time Complexity: O(n * logm) where m is the maximum number of bananas in a pile and n is the length of the input array
// Space Complexity: O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // the min speed k is going to be between l and r, where r is the biggest pile of bananas
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        // use binary search to find the minimum eating speed required
        while (l <= r) {
            int k = (l + r) / 2;

            long long totalTime = 0;
            for (int p : piles) {
                totalTime += ceil(static_cast<double>(p) / k);  // pile divided by k gives how long it takes to eat pile and need to round up
            }
            if (totalTime <= h) {   // koko ate all the bananas within the time allowed
                res = k;    // set result to k
                r = k - 1;  // we want to find a smaller number k so set r to k - 1
            } else {    // koko did not eat fast enough, so k needs to be larger
                l = k + 1;  // move k to k + 1 to find larger number
            }
        }
        return res; // return what k should be
    }
};