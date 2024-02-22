class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<int> trustCount(n + 1, 0); // Count of people trusting each person
        unordered_set<int> trustedSet; // Set of people being trusted
    
        for (const auto& relation : trust) {
            int trustor = relation[0];
            int trustee = relation[1];

            trustCount[trustee]++;
            trustedSet.insert(trustor);
        }

        for (int i = 1; i <= n; ++i) {
            if (trustCount[i] == n - 1 && trustedSet.find(i) == trustedSet.end()) {
                return i; // Found the judge
            }
        }

        return -1; // No judge found 
    }
};