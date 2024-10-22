#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string t = preprocessString(s);
        int n = t.length();
        vector<int> p(n, 0); // array to store the palindrome lengths
        int center = 0, right = 0; // center and right boundary of the current palindrome
        int maxLen = 0, maxCenter = 0; // length and center of the longest palindrome found so far

        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i; // mirror position of i

            // Check if the current position is within the right boundary of the current palindrome
            if (i < right) {
                p[i] = min(right - i, p[mirror]);
            }

            // Expand around the current position to find the palindrome length
            while (i + 1 + p[i] < n && i - 1 - p[i] >= 0 && (i + 1 + p[i] < t.length()) && (i - 1 - p[i] >= 0) && t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
                p[i]++;
            }

            // Update the right boundary and center if the current palindrome extends beyond it
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            // Update the longest palindrome found so far
            if (p[i] > maxLen) {
                maxLen = p[i];
                maxCenter = i;
            }
        }

        // Extract the longest palindrome from the original string
        int start = (maxCenter - maxLen) / 2;
        return s.substr(start, maxLen);
    }

private:
    string preprocessString(string s) {
        string t;
        for (char c : s) {
            t += "#" + string(1, c);
        }
        t += "#"; // add a special character at the end
        return t;
    }
};
