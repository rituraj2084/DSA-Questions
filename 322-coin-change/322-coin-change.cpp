class Solution {
public:
    int solveRec(vector<int>&coins, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int ans = solveRec(coins, amount - coins[i]);
            if(ans != INT_MAX) mini = min(mini, ans+1);
        }
        return mini;
    }
     int solveMem(vector<int>& coins, int amount, vector<int>&dp){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        int mini = INT_MAX;
        if(dp[amount] != -1) return dp[amount];
        for(int i = 0; i < coins.size(); i++){
            int ans = solveMem(coins, amount - coins[i], dp);
            if(ans != INT_MAX) mini = min(mini, ans+1);
        }
        dp[amount] = mini;
        return dp[amount];
        //return mini;
    }
    int solveTab(vector<int>&coins, int amount){
        vector<int>dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        //tabulation
        return solveTab(coins, amount);
        
        //memoization
        // vector<int>dp(amount+1, -1);
        // int ans = solveMem(coins, amount, dp);
        // if(ans == INT_MAX) return -1;
        // return ans;
        
        //recursive
        // int ans = solveRec(coins, amount);
        // if(ans == INT_MAX) return -1;
        // return ans;
        /*
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
        */
    }
};