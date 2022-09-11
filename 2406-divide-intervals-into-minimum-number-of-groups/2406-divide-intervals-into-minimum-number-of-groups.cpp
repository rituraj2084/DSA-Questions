class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>>pq;
        int n = intervals.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(pq.empty() || pq.top() > s){
                count++;
            }
            else{
                pq.pop();
                
            }
            pq.push(e+1);
            
        }
        return count;
    }
};