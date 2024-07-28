class Solution {
public:
     int calculateSecondMinDistance(int n, vector<vector<int>> &adj) {
        vector<int> minDist(n+1, INT_MAX), secondMinDist(n+1, INT_MAX);
        queue<pair<int,int>> q;
        q.push({1, 0});
        minDist[1] = 0;
        while(!q.empty()) {
            auto [u, dist] = q.front();
            q.pop();
            for(int v: adj[u]) {
                int newDist = dist + 1;
                if(newDist < minDist[v]) {
                    secondMinDist[v] = minDist[v];
                    minDist[v] = newDist;
                    q.push({v, newDist});
                } else if(newDist > minDist[v] && newDist < secondMinDist[v]) {
                    secondMinDist[v] = newDist;
                    q.push({v, newDist});
                }
            }
        }
        return secondMinDist[n];
    }

    int calculateTime(int dist, int time, int change) {
        int totalTime = 0;
        for(int i=0; i<dist; i++) {
            int trafficWindow = totalTime / change;
            if(trafficWindow % 2 == 1) totalTime = (trafficWindow + 1) * change;
            totalTime += time;
        }
        return totalTime;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int secondMinDistance = calculateSecondMinDistance(n, adj);
        if(secondMinDistance == INT_MAX) return -1;
        return calculateTime(secondMinDistance, time, change);
    }
};