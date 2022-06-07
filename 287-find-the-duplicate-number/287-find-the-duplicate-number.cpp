class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
       int n = nums.size();
        vector<int>freq(n+1, 0);
        for(int i = 0; i < n+1; i++){
            if(freq[nums[i]] == 0){
                freq[nums[i]]++;
            }
            else{
                return nums[i];
            }
        }
        return 0;
        /* //brute force
        sort(nums.begin(), nums.end());
        int i;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] == nums[i+1]){
                break;
            }
        }
        return nums[i];
        */
        
    }
};