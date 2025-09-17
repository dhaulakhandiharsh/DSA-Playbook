class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int mn = nums[i], mx = nums[i];
            for (int j = i + 1; j < n; j++) {
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
                res += mx - mn;
            }
        }
        return res;
    }
};