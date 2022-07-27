class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while(s <= e){
            int mid = (s+e)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        // Built-in function
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        // brute force
        // int ans = search(nums, target);
        // if(ans == -1){
        //     for(int i = 0; i < nums.size(); i++){
        //         if(target < nums[i]){
        //             ans = i;
        //             break;
        //         }
        //     }
        // }
        // if(ans == -1){
        //     ans = nums.size();
        // }
        // return ans;
    }
};