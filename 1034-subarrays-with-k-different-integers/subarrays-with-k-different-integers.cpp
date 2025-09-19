class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int left = 0, ans = 0;
        for(int right = 0; right < n; right++) {
            if(mp[nums[right]] == 0) k--;
            mp[nums[right]]++;
            while(k < 0) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) k++;
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
