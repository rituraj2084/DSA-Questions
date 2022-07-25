class Solution {
public:
    int leftPos(vector<int>&nums, int target){
        int s = 0, e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    int rightPos(vector<int>&nums, int target){
        int s = 0, e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == target){
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        vector<int> ans;
        int leftAns = leftPos(nums, target);
        int rightAns = rightPos(nums, target);
        ans.push_back(leftAns);
        ans.push_back(rightAns);
        return ans;
    }
};