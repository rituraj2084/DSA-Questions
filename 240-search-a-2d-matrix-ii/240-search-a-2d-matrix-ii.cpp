class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //efficient 
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while(i < m && j >= 0){
            if(matrix[i][j] == target) {
                return true;
            }
            if(matrix[i][j] < target){ 
                i++;
            }
            else {
                j--;
            }
        }
        return false;
        
        // //brute force
        // int row = matrix.size();
        // int col = matrix[0].size();
        // for(int i = 0; i < row; i++){
        //     for(int j = 0; j < col; j++){
        //         if(matrix[i][j] == target){
        //             return true;
        //         }
        //     }
        // }
        // return false;
    }
};