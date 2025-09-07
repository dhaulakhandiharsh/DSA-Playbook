class Solution {
public:
    vector<vector<int>>allSubsets;
    void backtrack(int index, vector<int> & nums, vector<int> & currentSubset){
        if(index == nums.size()){
            allSubsets.push_back(currentSubset);
            return;
        }
        currentSubset.push_back(nums[index]);
        backtrack(index+1, nums, currentSubset);
        currentSubset.pop_back();
        
        backtrack(index+1, nums, currentSubset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currentSubset;
        backtrack(0, nums, currentSubset);
        return allSubsets;
    }
};