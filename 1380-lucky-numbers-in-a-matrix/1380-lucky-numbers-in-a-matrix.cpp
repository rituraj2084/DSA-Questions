class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        vector<int> ans;
        for(int i = 0; i<matrix.size(); i++)
        {
            int minElement = matrix[i][0];
            int minCol = 0;
            for(int j = 1; j<n; j++)
            {
                if(matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                    minCol = j;
                }
            }
            bool isMax = true;
            for(int k = 0; k<matrix.size(); k++)
            {
                if(matrix[k][minCol] > minElement)
                {
                    isMax = false;
                    break;
                }
            }
            if(isMax)
                ans.push_back(minElement);
        }
        return ans;
    }
};