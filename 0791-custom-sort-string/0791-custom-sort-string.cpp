class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int>mp;
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }

        for(int i = 0; i < order.size(); i++){
            if(mp.find(order[i]) != mp.end()){
                while(mp[order[i]] > 0){
                    ans += order[i];
                    mp[order[i]]--;
                }

                if(mp[order[i]] == 0) mp.erase(order[i]);
            }
        }

        for(auto [k, v]: mp){
            while(v--){
                ans += k;
            }
        }

        return ans;
    }
};