class Solution {
private:
    int countTurnsRecursive(const string& s, int i, int j) {
        if (i > j) return 0;
        int turns = countTurnsRecursive(s, i, j - 1) + 1; // Try printing the last character separately
        for (int k = i; k < j; k++) {
            if (s[k] == s[j])
                turns = min(turns, countTurnsRecursive(s, i, k) + countTurnsRecursive(s, k + 1, j - 1));
        }
        return turns;
    }
    int countTurnsMemoized(const string& s, int i, int j, vector<vector<int>>& memo) {
        if (i > j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        int turns = countTurnsMemoized(s, i, j - 1, memo) + 1;
        for (int k = i; k < j; k++) {
            if (s[k] == s[j])
                turns = min(turns, countTurnsMemoized(s, i, k, memo) + countTurnsMemoized(s, k + 1, j - 1, memo));
        }
        return memo[i][j] = turns;
    }
public:
    int strangePrinter(string s) {
        
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return countTurnsMemoized(s, 0, n - 1, memo);
        
        // return countTurnsRecursive(s, 0, s.length() - 1);
    }
};

