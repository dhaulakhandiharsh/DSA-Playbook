class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> need, window;
        for(char c : t) need[c]++;

        int left = 0, right = 0, valid = 0;
        int minLen = INT_MAX, start = 0;

        while(right < s.size()) {
            char c = s[right];
            right++;
            if(need.count(c)) {
                window[c]++;
                if(window[c] == need[c]) valid++;
            }

            while(valid == need.size()) {
                if(right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                char d = s[left];
                left++;
                if(need.count(d)) {
                    if(window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};