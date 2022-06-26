class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if((i == j) || (i+j == grid.size() - 1)){
                    if(grid[i][j] == 0){
                        return false;
                    }
                }
                    else if(grid[i][j] > 0){
                        return false;
                    }
                }
        }
        return true;
        
        /*
        for (int i = 0; i < g.size(); ++i)
        for (int j = 0; j < g[i].size(); ++j) {
            if (i == j || i + j == g.size() - 1) {
                if (g[i][j] == 0)
                    return false;
            }
            else if (g[i][j] > 0)
                return false;
        }
    return true;
    */
    }
};