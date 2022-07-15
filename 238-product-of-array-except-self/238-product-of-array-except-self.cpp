class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int>lp(n, 1);
        vector<int>rp(n, 1);
        for(int i = 1; i < n; i++){
           lp[i] = lp[i-1] *  nums[i-1];
        }
        for(int i = n-2; i >= 0; i--){
            rp[i] = rp[i+1] * nums[i+1];
        }
        for(int i = 0; i < n; i++){
            ans[i] = lp[i] * rp[i];
        }
        return ans;
        /*
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int prod = 1;
            for(int j = 0; j < n; j++){
                if(i != j) {
                    prod = prod * nums[j];
                }
            }
            ans.push_back(prod);
        }
        return ans;
        */
    }
};