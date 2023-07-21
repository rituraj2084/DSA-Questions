class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> lengths(n, 1); // lengths[i] represents the length of LIS ending at index i
        vector<int> counts(n, 1);  // counts[i] represents the number of LIS ending at index i
        
        int max_len = 1; // Stores the length of the longest increasing subsequence found so far
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (lengths[i] == lengths[j] + 1) {
                        counts[i] += counts[j]; // If we find another LIS with the same length, increment the count
                    } else if (lengths[i] < lengths[j] + 1) {
                        lengths[i] = lengths[j] + 1; // Update the length of LIS
                        counts[i] = counts[j]; // Reset the count since we found a longer LIS
                    }
                }
            }
            max_len = max(max_len, lengths[i]);
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (lengths[i] == max_len) {
                result += counts[i]; // Count all LIS with the maximum length
            }
        }
        
        return result;
    }
};
