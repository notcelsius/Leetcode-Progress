// Date Completed: 12/7/2024

// Leetcode Problem: https://leetcode.com/problems/valid-anagram/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { // anagrams have to be the same length
            return false;
        }
        int letters[26] = {0};  // Fixed-size array for letter counts
        // Count the frequency of each letter in s
        for (char letter: s) {
            letters[letter - 'a']++; // Adds 1 letter that can be used
        }
        // Check if t can be constructed from s
        for (char letter: t) {
            if (letters[letter - 'a'] == 0) {
                return false;
            }
            letters[letter - 'a']--; // Uses 1 letter from s
        }
        return true;    // if t can be constructed from s and there is no extra characters, then s and t are anagrams
    }
};
