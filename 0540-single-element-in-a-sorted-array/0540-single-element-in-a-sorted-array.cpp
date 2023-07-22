class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            bool evenPairs = (right - mid) % 2 == 0;

            if (nums[mid] == nums[mid + 1]) {
                if (evenPairs) {
                    left = mid + 2; // Single element lies on the right side
                } else {
                    right = mid - 1; // Single element lies on the left side
                }
            } else if (nums[mid] == nums[mid - 1]) {
                if (evenPairs) {
                    right = mid - 2; // Single element lies on the left side
                } else {
                    left = mid + 1; // Single element lies on the right side
                }
            } else {
                // nums[mid] is the single element
                return nums[mid];
            }
        }

        // At this point, left and right will be pointing to the single element
        return nums[left];
        
        // int ans = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     ans = ans^nums[i];
        // }
        // return ans;
    }
};