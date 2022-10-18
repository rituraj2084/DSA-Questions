class Solution {
public:
    string say(string s){
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            int count = 1;
            while(i+1 < s.size() && s[i] == s[i+1]){
                i++;
                count++;
            }
            ans+=(to_string(count)+s[i]);
        }
        return ans;
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        return say(countAndSay(n-1));
        /*
      string res = "1";
    for (int i=1;i<n;i++)
    {
        string temp = "";
        int ct = 1;
        for (int j=0; j<res.length()-1;j++)
        {
            if (res[j] == res[j+1])
                ct++;
            else
            {
                temp += (to_string(ct) + res[j]);
                ct = 1;
            }
        }
       temp += to_string(ct) + res[res.length()-1];
       res = temp;
    }
    return res; 
    */
    }
};