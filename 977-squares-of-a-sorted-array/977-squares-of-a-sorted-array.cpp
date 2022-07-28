class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // two-pointer
        int n = nums.size();
        vector<int>ans(n);
        int l = 0, r = n-1;
        int k = r;
        while(l <= r){
            if(abs(nums[l]) > abs(nums[r])){
                ans[k] = nums[l]*nums[l];
                l++;
                k--;
            }
            else{
                ans[k] = nums[r]*nums[r];
                k--;
                r--;
            }
        }
        return ans;
        
        // //brute force
        // vector<int> ans;
        // for(int i = 0; i < nums.size(); i++){
        //     ans.push_back(nums[i]*nums[i]);
        // }
        // sort(ans.begin(), ans.end());
        // return ans;
    }
};