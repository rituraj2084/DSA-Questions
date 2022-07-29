class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1)max_area = max(max_area, AreaOfIsland(grid, i, j));
        return max_area;
    }
    
    int dfs(vector<vector<int>> &grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0;
        int count = 1;
        count += dfs(grid, i-1, j);
        count += dfs(grid, i+1, j);
        count += dfs(grid, i, j-1);
        count += dfs(grid, i, j+1);
        return count;
    }
    
    int AreaOfIsland(vector<vector<int>>& grid, int i, int j){
        int maxi = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    maxi = max(maxi, dfs(grid, i, j));
                }
            }
        }
        return maxi;
        /*
        if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
            grid[i][j] = 0;
            return 1 + AreaOfIsland(grid, i+1, j) + AreaOfIsland(grid, i-1, j) + AreaOfIsland(grid, i, j-1) + AreaOfIsland(grid, i, j+1);
        }
        return 0;
        */
    }
};