class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        sort(nums.begin(), nums.end());
        int ans = nums[n-1] - nums[0];
        for(int i = 0; i <= 3; i++){
            ans = min(ans, nums[n - (3-i) - 1] - nums[i]);
        }
        return ans;
    }
};