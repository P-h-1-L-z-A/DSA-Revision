#include <string>
#include <algorithm>

class Solution {
private:
    // Helper function to expand outward from a center point
    int expand(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Formula returns the exact length of the valid palindrome found
        return right - left - 1;
    }

public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Case 1: Odd length palindromes (e.g., "aba", center is 'b')
            int len1 = expand(s, i, i);
            
            // Case 2: Even length palindromes (e.g., "abba", center is between 'b' and 'b')
            int len2 = expand(s, i, i + 1);

            int currentMax = std::max(len1, len2);

            // If a longer palindrome is discovered, update coordinates
            if (currentMax > maxLength) {
                maxLength = currentMax;
                // Derives the correct starting index based on center and length
                start = i - (currentMax - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};
