class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        string tmp = "";
        for (int i=0; i<s.length(); i++)
        {
            if(s[i] == '1')
                ans += s[i];
            else
                tmp += s[i];
        }
        tmp += '1';
        if (tmp.length() == s.length())
            return tmp;
        return ans.erase(1,1) + tmp;
    }
};