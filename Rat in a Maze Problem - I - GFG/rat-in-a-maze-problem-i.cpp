// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void sol(vector<string>&vec,vector<vector<int>> &m,int n,int i,int j,string s)
    {
        if(i<0||j<0||i>=n||j>=n||m[i][j]<=0)
        return;
        if(i==n-1&&j==n-1)
        {
            vec.push_back(s);
            return ;
        }
        
        m[i][j]=-1;
        
        sol(vec,m,n,i+1,j,s+"D");
        
        sol(vec,m,n,i,j+1,s+"R");
        
        sol(vec,m,n,i-1,j,s+"U");
        
        sol(vec,m,n,i,j-1,s+"L");
        
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>vec;
        if (m[0][0]==0)
        return {};
        // string s="";
        sol(vec,m,n,0,0,"");
        return vec;
    }
    
    /*
    void solve(int i, int j, vector<vector<int>>&a, int n, vector<string>&ans, string move, vector<vector<int>>&vis){
        if(i == n-1 && j== n-1) {
            ans.push_back(move);
            return;
        }
        //Downward
        if(i+1 < n && !vis[i][j] && a[i+1][j] == 1){
            vis[i][j] = 1;
            solve(i+1, j, a, n, ans, move+'D', vis);
            vis[i][j] = 0;
        }
        //Leftward
        if(j-1 >= 0 && !vis[i][j] && a[i][j-1] == 1){
            vis[i][j] = 1;
            solve(i, j-1, a, n, ans, move+'L', vis);
            vis[i][j] = 1;
        }
        //rightward
                //Leftward
        if(j+1 < n && !vis[i][j] && a[i][j+1] == 1){
            vis[i][j] = 1;
            solve(i, j+1, a, n, ans, move+'R', vis);
            vis[i][j] = 1;
        }
        //upward
        if(i-1 >= 0 && !vis[i][j] && a[i-1][j] == 1){
            vis[i][j] = 1;
            solve(i-1, j, a, n, ans, move+'U', vis);
            vis[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0] == 1) solve(0, 0, m, n, ans, "", vis);
        return ans;
    }
    */
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends