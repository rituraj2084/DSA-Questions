class Solution {
public:
    bool wordBreakRecursive(string& s, vector<string>& wordDict, int start) {
        if (start == s.length()) {
            return true;
        }
        
        for (const string& word : wordDict) {
            int len = word.length();
            if (start + len <= s.length() && s.substr(start, len) == word) {
                if (wordBreakRecursive(s, wordDict, start + len)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool wordBreakMemo(string& s, vector<string>& wordDict, int start, unordered_map<int, bool>& memo) {
        if (start == s.length()) {
            return true;
        }
        
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }
        
        for (const string& word : wordDict) {
            int len = word.length();
            if (start + len <= s.length() && s.substr(start, len) == word) {
                if (wordBreakMemo(s, wordDict, start + len, memo)) {
                    memo[start] = true;
                    return true;
                }
            }
        }
        
        memo[start] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; ++i) {
            for (const string& word : wordDict) {
                int len = word.length();
                if (len <= i && dp[i - len] && s.substr(i - len, len) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
        
        // unordered_map<int, bool> memo; // Memoization       
        // return wordBreakMemo(s, wordDict, 0, memo);
        
       // return wordBreakRecursive(s, wordDict, 0);
    }
};

