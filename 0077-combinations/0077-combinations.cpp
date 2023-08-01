class Solution {
private:
    void backtrack(vector<vector<int>>& result, vector<int>& current_combination, int n, int k, int start) {
        if (current_combination.size() == k) {
            result.push_back(current_combination);
            return;
        }

        for (int i = start; i <= n; i++) {
            current_combination.push_back(i);
            backtrack(result, current_combination, n, k, i + 1);
            current_combination.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current_combination;
        backtrack(result, current_combination, n, k, 1);
        return result;
    }
};
