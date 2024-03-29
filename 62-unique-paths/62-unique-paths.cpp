class Solution {
public:
    int countPathsTab(int m, int n){
        vector<vector<int>>dp(m, vector<int>(n, 1));
        //dp[n-1][m-1] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int countPaths(int i,int j,int n,int m,vector<vector<int>>&dp)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
    }
    int uniquePaths(int m, int n) {
        return countPathsTab(m, n);
        /*
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
        int num = countPaths(0,0,m,n,dp);
        if(m == 1 && n == 1){
            return num;
        }
        return dp[0][0];
        */
        //return countPaths(0,0,m,n);
        
        /*//Most Efficient Solution
        int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
            */
    }
};