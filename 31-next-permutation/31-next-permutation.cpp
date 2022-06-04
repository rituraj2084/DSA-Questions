class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        next_permutation(nums.begin(), nums.end());
        /*
        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]);
        }
        return ans;
        */
    }
};