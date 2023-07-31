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
        int m = s1.length();
        int n = s2.length();

        // Create a 2D vector to store the minimum ASCII sum of deleted characters
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the first row and first column with cumulative ASCII sums of characters
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }

        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }

        // Fill the dp array to calculate the minimum ASCII sum of deleted characters
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }

        // Return the final result
        return dp[m][n];
        
        
        // unordered_map<string, int> memo;
        // return minimumDeleteSumHelperMemo(s1, s2, 0, 0, memo);
        
        // return minimumDeleteSumHelper(s1, s2, 0, 0);
    }
};
