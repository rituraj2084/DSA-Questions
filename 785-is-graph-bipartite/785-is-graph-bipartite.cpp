class Solution {
public:
    //DFS solution
    vector<int>vis,col;
    bool dfs(int v, int c, vector<vector<int>>& graph){
        vis[v]=1;
        col[v]=c;
        for(int child:graph[v]){
            if(vis[child]==0){
                // here c^1 is for flipping 1 by 0 or 0 by 1, that is flip the current color
                if(dfs(child,c^1,graph)==false) 
                    return false;
            }
            else{
                if(col[v]==col[child])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.resize(n);
        col.resize(n);

        for(int i=0;i<n;++i){
            if(vis[i]==0 && dfs(i,0,graph)==false){ 
                return false;
            }
        }
        
        return true;
    }
    /*
    //BFS Solution
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n); // 0: uncolored; 1: color A; -1: color B
        
        queue<int> q; // queue, resusable for BFS    
	
        for (int i = 0; i < n; i++) {
            if (color[i]) continue; // skip already colored nodes
      
            // BFS with seed node i to color neighbors with opposite color
             color[i] = 1; // color seed i to be A (doesn't matter A or B) 
            for (q.push(i); !q.empty(); q.pop()) {
                    int cur = q.front();
                    for (int neighbor : graph[cur]) {
                        if (!color[neighbor]){ // if uncolored, color with opposite color
                            color[neighbor] = -color[cur]; q.push(neighbor); 
                        } 
		  
                        else if (color[neighbor] == color[cur]) 
                    return false; // if already colored with same color, can't be bipartite!
                }        
            }
        }
    
        return true;
    }
    */
};