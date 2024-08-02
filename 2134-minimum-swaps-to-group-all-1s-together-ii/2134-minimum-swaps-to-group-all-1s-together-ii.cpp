class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one = accumulate(nums.begin(), nums.end(), 0);
        vector<int> arr(n + one);
        copy(nums.begin(), nums.end(), arr.begin());
        int active_zero = 0;
        for (int i = 0; i < one; i++) {
            arr[i + n] = nums[i];
            active_zero += nums[i] == 0 ? 1 : 0;
        }

        int count = active_zero;

        for (int i = one; i < arr.size(); i++) {
            active_zero -= arr[i - one] == 0 ? 1 : 0;
            active_zero += arr[i] == 0 ? 1 : 0;
            count = min(count, active_zero);
        }

        return count;
    }
};