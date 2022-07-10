class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //using max heap
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
        /*
        //using min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
        */
        /*
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-k];
        */
    }
};