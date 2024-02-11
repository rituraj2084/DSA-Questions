class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Create a 2D DP array to store the maximum cherries collected at each position for both robots
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // Set the initial value for the top row, representing the starting point for both robots
        dp[0][m - 1] = grid[0][0] + grid[0][m - 1];

        // Iterate through each row starting from the second row
        for (int i = 1; i < n; ++i) {
            // Create a temporary DP array to store the updated values for the current row
            vector<vector<int>> tempDP(m, vector<int>(m, 0));

            // Iterate through each column for robot 1
            for (int j = 0; j < m; ++j) {
                // Iterate through each column for robot 2
                for (int k = 0; k < m; ++k) {
                    // Skip invalid states:
                    // - Both robots in the same row (j > i)
                    // - Robot 2 left of robot 1 (k < m - i - 1)
                    // - Robot 1 further right than robot 2 (j > k)
                    if (j > i || k < m - i - 1 || j > k) continue;

                    // Calculate the cherries collected by both robots in the current cell
                    int move1 = grid[i][j];
                    if (j != k) move1 += grid[i][k];
                    int maxMove1 = 0;

                    // Explore moves for robot 1:
                    for (int p = j - 1; p <= j + 1; ++p) {
                        for (int q = k - 1; q <= k + 1; ++q) {
                            if (p >= 0 && p < m && q >= 0 && q < m) {
                                maxMove1 = max(maxMove1, dp[p][q]);
                            }
                        }
                    }

                    // Update the temporary DP array for the current cell
                    tempDP[j][k] = maxMove1 + move1;
                }
            }

            // Update the DP array with the values from the temporary array for the current row
            dp = tempDP;
        }

        // Find the maximum cherries collected in the last row
        int maxCherries = 0;
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < m; ++k) {
                maxCherries = max(maxCherries, dp[j][k]);
            }
        }

        // Return the maximum cherries collected
        return maxCherries;
    }
};