class Solution {
public:
    int partitionString(string s) {
        int i = 0;
        unordered_map<int, int>mp;
        int count = 0;
        while(i < s.length()){
            if(mp[s[i]] == 0){
                mp[s[i]]++;
                i++;
            }
            else{
                count++;
                mp.clear();
            }
        }
        return count+1;
    }
};