class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& nums, int k) {
        priority_queue<pair<int,pair<int,int>>>maxHeap;
        vector<vector<int>>ans;
        for(int i = 0; i < nums.size(); i++){  
            int x = nums[i][0];
            int y = nums[i][1];
            maxHeap.push({(x*x)+(y*y), {x, y}});
            if(maxHeap.size() > k) maxHeap.pop();
        }
        while(!maxHeap.empty()){
            ans.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }
        return ans;
    }
};