class Solution {
public:
    int solveRecursive(int n){
       if(n == 0) return 1;
       int count = 0;
        for(int i = 1; i <= n; i++){
          count += solveRecursive(i-1) * solveRecursive(n-i);  
        }
        return count; 
    }
    int solveMemo(int n, vector<int>&dp){
        if(n == 0) return 1;
       int count = 0;
        if(dp[n] != -1) return dp[n];
        for(int i = 1; i <= n; i++){
          count += solveMemo(i-1, dp) * solveMemo(n-i, dp);  
        }
        dp[n] = count;
        return dp[n]; 
    }
    int numTrees(int n) {
        vector<int>dp(n+1, -1);
        return solveMemo(n, dp);
        //return solveRecursive(n);
    }
};