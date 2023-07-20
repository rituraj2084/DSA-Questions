class Solution {
public:
    int firstPos(vector<int>& nums, int n, int target){
        int s= 0, e = n-1;
        int ans = -1;
        while(s <= e){
            int mid = s + ((e-s)/2);
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
    int lastPos(vector<int>& nums, int n, int target){
        int s= 0, e = n-1;
        int ans = -1;
        while(s <= e){
            int mid = s + ((e-s)/2);
            if(nums[mid] == target){
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       int n =  nums.size();
        int first = firstPos(nums, n, target);
        int last = lastPos(nums, n, target);
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};