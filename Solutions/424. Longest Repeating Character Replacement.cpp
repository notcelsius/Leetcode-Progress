// Date Completed: 1/4/2025

// Leetcode Problem: https://leetcode.com/problems/longest-repeating-character-replacement/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);  // keeps track of count of each character
        int l = 0, longest = 0, maxCount = 0;
        // using sliding window technique
        for (int r = 0; r < s.size(); r++) {
            maxCount = max(maxCount, ++counts[s[r] - 'A']); // keeps track of count of most frequent character
                                                            // in the window, it makes sense to use the most frequent character for least amount of replacements
            // if the window becomes invalid
            while ((r - l + 1) - maxCount > k) {            // window - most frequent character = number of replacements needed
                counts[s[l] - 'A']--;                       // decrease count of character at l because l will move forward
                l++;                                        // move l forward
            }

            longest = max(longest, r - l + 1);              // compare the current longest to the new window size
            // if window is not invalid, then r will just move forward
        }

        return longest; // return longest window width
    }
};