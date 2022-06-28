class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        if(s.length() != t.length()) return false;
        unordered_map<char,int>counts;
        for(int i = 0; i < n; i++){
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for(auto count:counts)
            if(count.second) return false;
        return true;
        /*
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);
        */
    }
};