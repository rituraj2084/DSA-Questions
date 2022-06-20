class Solution {
public:
    void solve(string &s, int ind, vector<string> &ans){
        if(ind == s.size()){
            ans.push_back(s);
            return;
        }
        for(int i = ind; i < s.size(); i++){
            swap(s[i], s[ind]);
            solve(s, ind+1, ans);
            swap(s[i], s[ind]);
        }
        
    }
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for(int i = 1; i < n; i++){
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k = k -1;
        
        while(true){
            ans = ans+ to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size() == 0) break;
            k = k% fact;
            fact = fact/numbers.size();
            }
        return ans;
        /*
        string s;
        vector<string> ans;
        for(int i = 1; i <= n; i++){
            s.push_back(i + '0');
        }
        solve(s, 0, ans);
        sort(ans.begin(), ans.end());
        auto it = ans.begin() + (k-1);
        return *it;
        */
    }
};