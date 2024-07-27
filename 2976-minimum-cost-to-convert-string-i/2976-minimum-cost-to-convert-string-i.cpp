class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long sum = 0;
        vector<vector<long long>> mat(26,vector<long long>(26,INT_MAX));
        int n = cost.size();
        for(int i = 0;i<26;i++){
            mat[i][i] = 0;
        }
        for(int i = 0;i<n;i++){
            if(cost[i] < mat[original[i] - 'a'][changed[i] - 'a']){
                mat[original[i] - 'a'][changed[i] - 'a'] = cost[i];
            }
        }

        for(int k = 0;k<26;k++){
            for(int i = 0;i<26;i++){
                for(int j = 0;j<26;j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        for(int i = 0;i<source.size();i++){
            if(mat[source[i] - 'a'][target[i] - 'a'] == INT_MAX) return -1;
            sum += mat[source[i] - 'a'][target[i] - 'a'];
        }

        return sum;
    }
};