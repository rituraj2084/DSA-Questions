class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prefix[n];
        int suffix[n];
        prefix[0] = height[0], suffix[n - 1] = height[n - 1];
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i - 1], height[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = max(suffix[i + 1], height[i]);
        }
        int waterTrapped = 0;
        for(int i = 0; i < n; i++){
            waterTrapped += min(suffix[i], prefix[i]) - height[i];
        }
        return waterTrapped;
        /*
      int n = height.size();
        int waterTrapped = 0;
        for(int i = 0; i < n; i++){
            int leftMax = 0, rightMax = 0;
            int j = i;
            while(j >= 0){
                leftMax = max(leftMax, height[j]);
                j--;
            }
            j = i;
            while(j < n){
                rightMax = max(rightMax, height[j]);
                j++;
            }
            waterTrapped += min(leftMax, rightMax) - height[i];
        }
        return waterTrapped;
        */
    }
};