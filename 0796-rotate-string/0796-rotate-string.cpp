class Solution {
public:
    string rotate(string &s){
        int n = s.length();
        char c = s[0];
        for(int i = 0; i < n-1; i++){
            s[i] = s[i+1];
        }
        s[n-1] = c;
        return s;
    }
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int n = s.length();
        for(int i = 0; i < n; i++){
            string newStr = rotate(s);
            // cout<<newStr<<" ";
            if(newStr == goal) return true;
        }
        
        return false;
    }
};