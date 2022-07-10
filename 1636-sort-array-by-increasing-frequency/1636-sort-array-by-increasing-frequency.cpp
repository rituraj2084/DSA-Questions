class Solution {
public:
    bool static comp(pair<int,int> a,pair<int,int> b)
    {
        if(a.second==b.second)
        return a>b;   
        else
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
         unordered_map<int,int> mp;
         for(int i=0;i<nums.size();i++)
         {
             mp[nums[i]]++;
         }
         vector<pair<int,int> > vec;
         for(auto pr:mp)
         {
             vec.push_back(pr);
         }
         sort(vec.begin(),vec.end(),comp);
         
 vector<int> ans;
    for(int i=0;i<vec.size();i++)
    {
     while(vec[i].second>0)
     {
         ans.push_back(vec[i].first);
         vec[i].second--;
     }
    }
        return ans;
    }
    /*
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        //priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>>minHeap;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
           minHeap.push({it.second, it.first}); 
        }
        while(!minHeap.empty()){
            for(int i = 0; i < minHeap.top().first; i++){
                ans.push_back(minHeap.top().second);
            }
            minHeap.pop();
        }
        
        return ans;
    }
    */
};