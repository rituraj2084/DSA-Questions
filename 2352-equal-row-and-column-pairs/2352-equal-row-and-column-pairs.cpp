class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int>mp1, mp2;
        for(int i = 0; i < grid.size(); i++){
            vector<int>v;
            for(int j = 0; j < grid[0].size(); j++){
                v.push_back(grid[i][j]);
            }
            mp1[v]++;
        }
        for(int i = 0; i < grid[0].size(); i++){
            vector<int> v;
            for(int j = 0; j < grid.size(); j++){
                v.push_back(grid[j][i]);
            }
            mp2[v]++;
        }
        int ans = 0;
        for(auto it: mp1){
            ans += mp1[it.first]*mp2[it.first];
        }
        return ans;
    }
};