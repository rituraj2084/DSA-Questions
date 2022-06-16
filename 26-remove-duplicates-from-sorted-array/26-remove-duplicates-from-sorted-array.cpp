class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
        /*
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
        */
    }
};