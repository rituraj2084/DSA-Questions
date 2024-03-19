class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> arr(26,0);
        for(auto it:tasks)
        {
            arr[it-'A']++;
        }
        sort(arr.begin(),arr.end());

        int batchCount=arr[25];
        int idleSlot=(--batchCount)*n;

        for(int i=0;i<25;i++)
        {
            idleSlot-=min(arr[i],batchCount);
        }

        if(idleSlot>0)
        return idleSlot+tasks.size();
        else
        return tasks.size(); 
    }
};