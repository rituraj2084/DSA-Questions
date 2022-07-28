class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        for(auto i:count){
            if(i.second > 1){
                return 1;
                //break;
            }
        }
        return 0;
    }
};