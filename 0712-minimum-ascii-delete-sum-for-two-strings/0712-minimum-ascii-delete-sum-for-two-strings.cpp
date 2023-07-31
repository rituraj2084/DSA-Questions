class Solution {
public:
    int minimumDeleteSumHelper(const string& s1, const string& s2, int i, int j) {
        if (i == s1.length() && j == s2.length()) {
            return 0;
        }
        
        if (i == s1.length()) {
            return s2[j] + minimumDeleteSumHelper(s1, s2, i, j + 1);
        }
        
        if (j == s2.length()) {
            return s1[i] + minimumDeleteSumHelper(s1, s2, i + 1, j);
        }
        
        if (s1[i] == s2[j]) {
            return minimumDeleteSumHelper(s1, s2, i + 1, j + 1);
        }
        
        return min(s1[i] + minimumDeleteSumHelper(s1, s2, i + 1, j), s2[j] + minimumDeleteSumHelper(s1, s2, i, j + 1));
    }
    
    int minimumDeleteSumHelperMemo(const string& s1, const string& s2, int i, int j, unordered_map<string, int>& memo) {
        string key = to_string(i) + "-" + to_string(j);
        if (memo.count(key)) {
            return memo[key];
        }
        
        if (i == s1.length() && j == s2.length()) {
            return 0;
        }
        
        if (i == s1.length()) {
            return s2[j] + minimumDeleteSumHelperMemo(s1, s2, i, j + 1, memo);
        }
        
        if (j == s2.length()) {
            return s1[i] + minimumDeleteSumHelperMemo(s1, s2, i + 1, j, memo);
        }
        
        if (s1[i] == s2[j]) {
            memo[key] = minimumDeleteSumHelperMemo(s1, s2, i + 1, j + 1, memo);
        } else {
            memo[key] = min(s1[i] + minimumDeleteSumHelperMemo(s1, s2, i + 1, j, memo), s2[j] + minimumDeleteSumHelperMemo(s1, s2, i, j + 1, memo));
        }
        
        return memo[key];
    }
    int minimumDeleteSum(string s1, string s2) {
        unordered_map<string, int> memo;
        return minimumDeleteSumHelperMemo(s1, s2, 0, 0, memo);
        
        // return minimumDeleteSumHelper(s1, s2, 0, 0);
    }
};
