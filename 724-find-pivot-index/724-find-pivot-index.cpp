class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int leftSum = 0, rightSum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i != 0){
               leftSum += nums[i-1]; 
            }
            for(int j = i+1; j < n; j++){
                rightSum += nums[j];
            }
            
            if(leftSum == rightSum) return i;
            rightSum = 0;
        }
        return -1;
    }
};