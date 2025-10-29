class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return dfs(s, 0, dict, memo);
    }

private:
    vector<string> dfs(const string &s, int start,
                       unordered_set<string> &dict,
                       unordered_map<int, vector<string>> &memo) {
        if (start == (int)s.size()) return {""}; // one valid decomposition (empty tail)

        if (memo.count(start)) return memo[start];

        vector<string> res;
        // Try every end position from start+1..n
        for (int end = start + 1; end <= (int)s.size(); ++end) {
            string word = s.substr(start, end - start);
            if (!dict.count(word)) continue;

            vector<string> tails = dfs(s, end, dict, memo);
            for (const string &t : tails) {
                if (t.empty()) res.push_back(word);
                else res.push_back(word + " " + t);
            }
        }

        memo[start] = res;
        return res;
    }
};
