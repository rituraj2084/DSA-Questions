class Solution {
public:
    int solve(vector<vector<int>>& events, vector<vector<int>>&dp, int position, int n, int k){
        if(position >= n || k == 0) return 0;
        if(dp[position][k] != -1) return dp[position][k];
        int i;
        for(i = position + 1; i < n; i++){
            if(events[i][0] > events[position][1]){
                break;
            }
        }
        return dp[position][k] = max(solve(events, dp, position+1, n, k), events[position][2]+solve(events, dp, i, n, k-1));
        
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return solve(events, dp, 0, n, k);
    }
};