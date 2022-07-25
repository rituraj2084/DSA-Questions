class Solution {
public:
    int solveRec(string &s, string &t, int i, int j){
        if(i == 0 || j == 0){
            return 0;
        }
        if(s[i-1] == t[j-1]){
            return 1 + solveRec(s, t, i-1, j-1);
        }
        else{
            return solveRec(s, t, i, j-1);
        }
    }
    int solveMem(string &s, string &t, int i, int j, vector<vector<int>>&dp){
        if(i == 0 || j == 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i-1] == t[j-1]){
            dp[i][j] = 1+solveMem(s, t, i-1, j-1, dp);
        }
        else{
            dp[i][j] = solveMem(s, t, i, j-1, dp);
        }
        return dp[i][j];
    }
    bool isSubsequence(string s, string t) {
         int m = s.length(), n = t.length();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
       
        int ans = solveMem(s, t, m, n, dp);
        return (ans == m);
        
        // //recursive
        // int m = s.length(), n = t.length();
        // int ans = solveRec(s, t, m, n);
        // return (ans == m);
        
      //   // two-pointer approach
      // if(s.length() > t.length()) 
      //     return false;
      //   int i = 0, j = 0;
      //   while(i < s.length() && j < t.length()){
      //       if(s[i] == t[j]){
      //           i++;
      //           j++;
      //       }
      //       else{
      //           j++;
      //       }
      //   }
      //   if(i == s.length()) return true;
      //   return false;
    }
};