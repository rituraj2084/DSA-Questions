class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int n = nums.size();
        k = k % n;
        int j = 0;
        vector<int> dummy(n);
        for(int i = k; i < n; i++){
            dummy[i] = nums[j++];
        }
        for(int i = 0; i < k; i++){
            dummy[i] = nums[j++];
        }
        nums = dummy;
    }
};