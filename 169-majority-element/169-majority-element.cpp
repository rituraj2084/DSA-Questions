class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }
    for(auto x:mp){
        if(x.second>n/2)
            return x.first;
    }
    return -1;
        /*
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if(num==candidate) count += 1; 
            else count -= 1; 
        }

        return candidate;
        */
    }
};