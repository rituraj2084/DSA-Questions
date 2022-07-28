class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> mp;
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
            if(mp[s[i]]%2==0) {
                count += mp[s[i]];
                mp[s[i]] = 0;
            }
        }
        for(auto it: mp) {
            if(it.second==1) {
              count++;
              break;
            }  
        }
        return count;
    }
};