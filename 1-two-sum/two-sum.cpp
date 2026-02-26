class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // value -> index
        
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement already exists
            if(mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            
            // Store current number with index
            mp[nums[i]] = i;
        }
        
        return {};  // Not needed (problem guarantees one solution)
    }
};
