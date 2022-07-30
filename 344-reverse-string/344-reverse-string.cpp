class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size()-1;
        while(l <= r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
        
        // built-in function
        // reverse(s.begin(), s.end());
    }
};