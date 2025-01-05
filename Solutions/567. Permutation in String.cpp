// Date Completed: 1/4/2025

// Leetcode Problem: https://leetcode.com/problems/permutation-in-string/description/

// Time Complexity: O(m) where m is length of s2
// Space Complexity: O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) return false;

        vector<int> s1Counts(26, 0);
        vector<int> s2Counts(26, 0);

        // get frequency of first n1 characters for s1 and s2
        for (int i = 0; i < n1; i++) {
            s1Counts[s1[i] - 'a']++;
            s2Counts[s2[i] - 'a']++;
        }
        // if first n1 chars of s1 and s2 have same char freq then they are permutations
        if (s1Counts == s2Counts) return true;

        for (int i = n1; i < n2; i++) {
            s2Counts[s2[i] - 'a']++;    // window moves to the right, so add count up of that  right character
            s2Counts[s2[i - n1] - 'a']--;   // window moves to the left, so subtract count of the left character
            if (s1Counts == s2Counts) return true;  // if counts of window and s1 are equal then it is a permutation
        }

        return false;   // reached end of s2, and no permutations were found so it is false
    }
};