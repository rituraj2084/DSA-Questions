class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += (num%10);
            num = num/10;
        }
        //cout<<sum<<endl;
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        vector<pair<int,int>> v;
        int n = nums.size();
        int maxSum = -1;
        for(int i = 0;i < n; i++){
            v.push_back({digitSum(nums[i]), nums[i]});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n-1; i++){
            if(v[i].first == v[i+1].first){
                maxSum = max(maxSum, v[i].second + v[i+1].second);
            }
        }
        return maxSum;
        /*
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(v[i].second == v[j].second){
                    //cout<<v[i].first<<" "<<v[j].first<<endl;
                    maxSum = max(maxSum, v[i].first + v[j].first);
                }
            }
        }
        return maxSum;
        */
    }
};