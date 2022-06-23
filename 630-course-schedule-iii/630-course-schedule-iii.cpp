   struct comp{
    bool operator()(const vector<int> &v1, const vector<int> &v2){
        return v1[1] < v2[1];
    }
};
class Solution {
 
public:
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp());
        int time=0,n=courses.size();
        priority_queue<int> pq;
        for(int i=0;i<n;++i){
            time+=courses[i][0];
            pq.push(courses[i][0]);
            if(time>courses[i][1]){
                time-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
        /*
        sort(courses.begin(), courses.end());
        int duration = 0, lastDay = 0;
        int count  = 0;
        for(int i = 0; i <= courses.size(); i++){
            duration += courses[i][0];
            lastDay = max(lastDay, courses[i][1]);
            if(courses[i][0] == courses[i+1][0] && courses[i][1] == courses[i+1][1]) continue;
            if(duration <= lastDay) count++;
        }
        return count;
        */
    }
};