class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (index[s[i]] > start) {
                start = index[s[i]];
            }
            index[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};