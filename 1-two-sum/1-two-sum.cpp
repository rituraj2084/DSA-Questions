class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> dummy;
        dummy = nums;
        sort(dummy.begin(), dummy.end());
        int l = 0, h = nums.size()-1;
        int n1,n2;
        vector<int> ans;
        while(l<h){
            if(dummy[l] + dummy[h] == target){
                n1 = dummy[l];
                n2 = dummy[h];
                break;
            }
            else if(dummy[l] + dummy[h] > target){
                h--;
            }
            else{
                l++;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == n1){
                ans.push_back(i);
            }
             else if(nums[i] == n2){
                ans.push_back(i);
            }
        }
        return ans;
        /*
        //brute force
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
        */
    }
};