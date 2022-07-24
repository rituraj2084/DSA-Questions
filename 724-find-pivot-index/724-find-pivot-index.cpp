class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) 
            sum += nums[i];
        int leftSum = 0, rightSum = sum;
        for(int i = 0; i < nums.size(); i++){
            if(i != 0){
                leftSum += nums[i-1];
            }
            rightSum -= nums[i];
            if(leftSum == rightSum) return i;
        }
        return -1;
        
//         //brute force
//        int leftSum = 0, rightSum = 0;
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             if(i != 0){
//                leftSum += nums[i-1]; 
//             }
//             for(int j = i+1; j < n; j++){
//                 rightSum += nums[j];
//             }
            
//             if(leftSum == rightSum) return i;
//             rightSum = 0;
//         }
//         return -1;
    }
};