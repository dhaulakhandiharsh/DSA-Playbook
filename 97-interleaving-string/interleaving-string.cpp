class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if ((int)s3.size() != m + n) return false;
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int j = 1; j <= n; ++j)
            dp[j] = dp[j-1] && (s2[j-1] == s3[j-1]);
        for (int i = 1; i <= m; ++i) {
            dp[0] = dp[0] && (s1[i-1] == s3[i-1]);
            for (int j = 1; j <= n; ++j) {
                bool fromS1 = dp[j] && (s1[i-1] == s3[i+j-1]);      // dp[j] currently holds dp[i-1][j]
                bool fromS2 = dp[j-1] && (s2[j-1] == s3[i+j-1]);   // dp[j-1] holds dp[i][j-1]
                dp[j] = fromS1 || fromS2;
            }
        }
        return dp[n];
    }
};