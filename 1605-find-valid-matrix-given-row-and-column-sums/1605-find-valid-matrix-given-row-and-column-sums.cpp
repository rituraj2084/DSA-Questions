class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r=rowSum.size();
        int c=colSum.size();
         vector<vector<int>> ans(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               ans[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i]=rowSum[i]-ans[i][j];
                colSum[j]=colSum[j]-ans[i][j];
            }
        }
        return ans;
    }
};