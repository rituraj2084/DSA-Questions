class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] <= nums[mid]) {
                // Left part of the array is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Target lies in the left part
                } else {
                    left = mid + 1; // Target lies in the right part
                }
            } else {
                // Right part of the array is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // Target lies in the right part
                } else {
                    right = mid - 1; // Target lies in the left part
                }
            }
        }

        return -1; // Target not found
        
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] == target) return i;
        // }
        // return -1;
    }
};