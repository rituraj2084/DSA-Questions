class Solution {
public:
    bool isOnBoard(int x, int y, int n) {
        return (x >= 0 && y >= 0 && x < n && y < n);
    }
    
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        dp[row][col] = 1.0;

        // Possible moves for the knight
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        for (int step = 0; step < k; step++) {
            vector<vector<double>> next_dp(n, vector<double>(n, 0.0));
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    for (int i = 0; i < 8; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (isOnBoard(nx, ny, n)) {
                            next_dp[nx][ny] += dp[x][y] / 8.0;
                        }
                    }
                }
            }
            dp = next_dp;
        }

        // Sum up the probabilities of being on the board after k moves
        double probability = 0.0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                probability += dp[x][y];
            }
        }

        return probability;
    }
};