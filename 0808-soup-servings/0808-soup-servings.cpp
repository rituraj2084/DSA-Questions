class Solution {
public:
    double dp(int soupA, int soupB, unordered_map<int, unordered_map<int, double>>& memo) {
        if (soupA <= 0 && soupB <= 0) {
            // Both soup A and soup B are empty
            return 0.5;
        } else if (soupA <= 0) {
            // Soup A is empty, return 1 for the probability of emptying soup A first
            return 1.0;
        } else if (soupB <= 0) {
            // Soup B is empty, return 0 for the probability of emptying soup A first
            return 0.0;
        }

        // If we have already calculated this state, return the memoized result
        if (memo.count(soupA) && memo[soupA].count(soupB)) {
            return memo[soupA][soupB];
        }

        // Calculate the probabilities for each of the four operations
        double probA = 0.25 * (
            dp(soupA - 100, soupB, memo) +
            dp(soupA - 75, soupB - 25, memo) +
            dp(soupA - 50, soupB - 50, memo) +
            dp(soupA - 25, soupB - 75, memo)
        );

        // Memoize the result and return it
        memo[soupA][soupB] = probA;
        return probA;
    }
    
    double soupServings(int n) {
        if (n >= 5000) {
            // When n is too large, the probability is very close to 1, so return 1 directly
            return 1.0;
        }

        // Memoization table to store the results of already calculated states
        unordered_map<int, unordered_map<int, double>> memo;

        return dp(n, n, memo);
    }
};