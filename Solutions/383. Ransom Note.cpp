// Date Completed: 12/7/2024

// Leetcode Problem: https://leetcode.com/problems/ransom-note/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Fixed-size array for letter counts
        int availableLetters[26] = {0};
        
        // Count the frequency of each letter in the magazine
        for (char letter : magazine) {
            availableLetters[letter - 'a']++;   // Adds 1 letter that can be used
        }
        
        // Check if ransomNote can be constructed
        for (char letter : ransomNote) {
            if (availableLetters[letter - 'a'] == 0) {
                return false;
            }
            availableLetters[letter - 'a']--;   // Uses 1 letter for the ransom note
        }
        
        return true;
    }
};
