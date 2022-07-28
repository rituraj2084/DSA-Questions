class Solution {
public:
    int solveRec(int n){
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        return solveRec(n-1) + solveRec(n-2) + solveRec(n-3);
    }
    int solveMem(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = solveMem(n-1, dp) + solveMem(n-2, dp) + solveMem(n-3, dp);
        return dp[n];
    }
    int tribonacci(int n) {
        //Memoization
        vector<int> dp(n+1, -1);
        return solveMem(n, dp);
        
        // // recursive
        // return solveRec(n);
    }
};