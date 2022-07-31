class Solution {
public:
    void bfs(int src, vector<int> &dist,vector<int>& edge,int n){
    queue<int> q;
    q.push(src);
    dist[src]=0;
    vector<bool> vis(n);
    vis[src]=true;
    while(q.size()>0){
        auto p= q.front(); q.pop();
        if(edge[p]!=-1 and !vis[edge[p]]){
            q.push(edge[p]);  
            dist[edge[p]]= dist[p]+1; 
            vis[edge[p]]=true;
        }
    }
}

int closestMeetingNode(vector<int>& e, int n1, int n2) {
    int n= e.size();
    vector<int> A(n,INT_MAX), B(n,INT_MAX);
    bfs(n1,A,e,n);   
    bfs(n2,B,e,n);
    int res= INT_MAX, node=-1;
    for(int i=0;i<n;i++){
        if(A[i]==INT_MAX or B[i]==INT_MAX) continue;
        if(res>max(A[i],B[i])) node=i,res= max(A[i],B[i]);
    }
    return res==INT_MAX? -1 : node;
}
    /*
    int closestMeetingNode(vector<int>& e, int node1, int node2) {
        
    int n=e.size();
        vector<int> adj[n];
        for(int i=0;i<e.size();i++){
            if(e[i]!=-1){
                adj[i].push_back(e[i]);
            }
        }
        vector<int> x(n,1e8),y(n,1e8);
        queue<int> q;
        q.push(node1);
        
       x[node1]=0;
        while(!q.empty()){
    
            int sq=q.size();
            for(int i=0;i<q.size();i++){
                auto it=q.front();
                q.pop();
                for(auto itr:adj[it]){
                    if(x[itr]==1e8){
                        x[itr]=x[it]+1;
                        q.push(itr);
                    }
                }
            }
        }
          q.push(node2);
        
       y[node2]=0;
        while(!q.empty()){
    
            int sq=q.size();
            for(int i=0;i<q.size();i++){
                auto it=q.front();
                q.pop();
                for(auto itr:adj[it]){
                    if(y[itr]==1e8){
                        y[itr]=y[it]+1;
                        q.push(itr);
                    }
                }
            }
        }
        int w=INT_MAX;
        int z=-1;
        for(int i=0;i<n;i++){
            if(x[i]!=1e8&&y[i]!=1e8){
                int p=max(x[i],y[i]);
                if(w>p){
                    w=p;
                    z=i;
                }
            }
        }
        return z;
    }
    */
};