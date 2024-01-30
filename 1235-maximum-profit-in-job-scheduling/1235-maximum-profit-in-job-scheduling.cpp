class Solution {
private:
    int nextJob(vector<pair<pair<int,int>,int>>& v,int i){
        int s = i , e=v.size()-1 , ans = -1 , endTime = v[i-1].second;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(v[mid].first.first >= endTime){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<int> d(n+1,0);
        vector<pair<pair<int,int>,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({{startTime[i],profit[i]},endTime[i]});
        }
        sort(v.begin(),v.end());
        for(int i=n-1;i>=0;i--){
            int nxt=nextJob(v,i+1);
            d[i] = d[i+1];
            if(nxt != -1) d[i]=max(d[i],v[i].first.second+d[nxt]);
            else d[i]=max(d[i],v[i].first.second);
        }
        return d[0];
    }
};