class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] == nums[i+1]){
                break;
            }
        }
        return nums[i];
        /*
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = ans^nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            ans = ans^i;
        }
        return ans;
        */
    }
};