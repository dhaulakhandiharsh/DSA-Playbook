class Solution {
public:
    string longestPalindrome(string s) {
        // Transform string: add '#' between characters
        string t = "#";
        for (char c : s) {
            t += c;
            t += "#";
        }

        int n = t.size();
        vector<int> P(n, 0); // radius array
        int C = 0, R = 0;    // center and right boundary
        int maxLen = 0, centerIndex = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * C - i;

            if (i < R)
                P[i] = min(R - i, P[mirror]);

            // Try to expand
            int a = i + 1 + P[i];
            int b = i - 1 - P[i];
            while (a < n && b >= 0 && t[a] == t[b]) {
                P[i]++;
                a++;
                b--;
            }

            // Update center and right boundary
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }

            // Track longest palindrome
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }

        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};