class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
         long long n=tasks.size();
        map<long long,long long>mp;
        
        long long ans=n;
        vector<long long >dp(n);
        long long curr=0;
        
        
        for(int i=0;i<n;i++){
            if(mp.find(tasks[i])==mp.end()){
                mp[tasks[i]]=i;
                curr++;
                dp[i]=curr;
            }
            else{
                curr++;
                
                long long time=curr-dp[mp[tasks[i]]]-1;
                
                long long req=max(0LL,space-time);
                curr+=req;
                
                dp[i]=curr;
                mp[tasks[i]]=i;
                
            }
        }
        return dp[n-1];
    }
};