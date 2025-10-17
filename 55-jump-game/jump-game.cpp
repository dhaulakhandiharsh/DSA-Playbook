class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;
        priority_queue<pair<int,int>> pq;
        vector<char> vis(n, false);
        pq.push({0 + nums[0], 0});
        vis[0] = true;
        while (!pq.empty()) {
            auto [reach, idx] = pq.top();
            pq.pop();
            if (reach >= n - 1) return true;
            int limit = min(n - 1, reach);
            for (int next = idx + 1; next <= limit; ++next) {
                if (!vis[next]) {
                    vis[next] = true;
                    pq.push({next + nums[next], next});
                }
            }
        }
        return false;
    }
};