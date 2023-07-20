class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> asteroidStack;

        for (int asteroid : asteroids) {
            // If asteroid is moving to the right or stack is empty, simply push it to the stack
            if (asteroid > 0 || asteroidStack.empty()) {
                asteroidStack.push(asteroid);
            } else {
                // Asteroid is moving to the left
                while (!asteroidStack.empty() && asteroidStack.top() > 0 && asteroidStack.top() < abs(asteroid)) {
                    // Explode the right-moving asteroid since it's smaller
                    asteroidStack.pop();
                }

                if (!asteroidStack.empty() && asteroidStack.top() > 0 && asteroidStack.top() == abs(asteroid)) {
                    // Both asteroids have the same size, explode both
                    asteroidStack.pop();
                } else if (asteroidStack.empty() || asteroidStack.top() < 0) {
                    // Either there is no right-moving asteroid to explode or the top asteroid in the stack is moving left
                    asteroidStack.push(asteroid);
                }
                // Otherwise, the current left-moving asteroid gets destroyed
            }
        }

        // Convert the stack to a vector and return the result
        vector<int> result(asteroidStack.size());
        for (int i = asteroidStack.size() - 1; i >= 0; --i) {
            result[i] = asteroidStack.top();
            asteroidStack.pop();
        }

        return result;
    }
};