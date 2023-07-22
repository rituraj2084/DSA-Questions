class Solution {
public:
    int findMin(vector<int>& nums) {
        int minElement = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            minElement = min(minElement, nums[i]);
        }
        return minElement;
    }
};