class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> maxcount;
        int maxfreq=0; 
        for(int i=0;i<nums.size();i++)
        { 
            maxcount[nums[i]]++; 

            if(maxcount[nums[i]] > maxfreq){
                maxfreq = maxcount[nums[i]]; 
            }
        }
        
        int finalfreq=0;
        for(auto it:maxcount){
           if(it.second == maxfreq)
           {
              finalfreq += it.second;
           }
        }
        return finalfreq;
    }
};