class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>>minHeap;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            //cout<<it.first<<":"<<it.second<<endl;
            minHeap.push({it.second, it.first});
            if(k < minHeap.size()) minHeap.pop();
        }
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};