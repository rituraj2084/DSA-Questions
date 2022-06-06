class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(output.back()[1] >= intervals[i][0]) 
                output.back()[1] = max(output.back()[1] , intervals[i][1]);
            else output.push_back(intervals[i]); 
        }
        return output;
        /*
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(int i = 0; i < intervals.size(); i++){
            if(merged.empty() || merged.back()[1] < intervals[i][0]){
                vector<int> v = {
                    intervals[i][0],
                    intervals[i][1]
                };
                merged.push_back(v);
            }
            else{
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
        }
        return merged;
        */
    }
};