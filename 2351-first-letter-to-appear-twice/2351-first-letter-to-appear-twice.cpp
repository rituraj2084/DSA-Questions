class Solution {
public:
    char repeatedCharacter(string s) {
        map<char, int>mp;
        int n = s.length();
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            for(auto it:mp){
                if(it.second == 2) return it.first;
            }
        }
        
        return s.back();
    }
};