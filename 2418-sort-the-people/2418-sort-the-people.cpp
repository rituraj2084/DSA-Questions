class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        map<int, string>mp;
        for(int i = 0; i < n; i++){
            mp[heights[i]] = names[i];
        }
        vector<string>ans;
        for(auto it = mp.rbegin(); it != mp.rend(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};