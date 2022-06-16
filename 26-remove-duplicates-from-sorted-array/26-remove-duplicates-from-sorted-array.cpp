class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        int j = 0;
        int k = st.size();
        for(int x: st){
            nums[j++] = x;
        }
        return k;
    }
};