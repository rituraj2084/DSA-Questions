class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        map<char,int>mps;
        map<char,int>mpt;
        for(int i=0;i<n;i++){
            if(mps.find(s[i])==mps.end()){
                mps[s[i]]=i;
            }
            if(mpt.find(t[i])==mpt.end()){
                mpt[t[i]]=i;
            }
        }
        for(int i=0;i<n;i++){
            if(mps[s[i]]!=mpt[t[i]])return false;
        }
        return true;
        /*
        map<char, char>mp;
        for(int i = 0; i < s.length(); i++){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] != t[i]) return false;
            }
            else mp[s[i]] = t[i];
        }
        return true;
        */
    }
};