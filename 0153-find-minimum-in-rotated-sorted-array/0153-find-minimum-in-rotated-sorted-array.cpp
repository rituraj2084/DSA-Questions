class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0; 
        int high = nums.size()-1;
        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[high]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
        
        // int minElement = INT_MAX;
        // for(int i = 0; i < nums.size(); i++){
        //     minElement = min(minElement, nums[i]);
        // }
        // return minElement;
    }
};