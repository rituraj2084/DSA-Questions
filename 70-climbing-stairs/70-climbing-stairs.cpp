class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1;
        int prev = 1;
  
        for(int i=2; i<=n; i++){
            int cur_i = prev2+ prev;
            prev2 = prev;
            prev= cur_i;
        }
        return prev;
        /*
        vector<int> dp(n+1, -1);
        dp[0] = 0, dp[1] = 1, dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        */
        /*
        //recursive
        if(n <= 2) return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
        */
    }
};