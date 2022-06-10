class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.empty()){
            return ans;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int target3 = target - nums[i];
            for(int j = i+1; j < n; j++){
                int target2 = target3 - nums[j];
                int front  = j + 1;
                int back = n - 1;
                while(front < back){
                    int twoSum = nums[front] + nums[back];
                    if(twoSum < target2){
                        front++;
                    }
                    else if(twoSum > target2){
                        back--;
                    }
                    else{
                        vector<int>quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        ans.push_back(quadruplet);
                        while(front < back && nums[front] == quadruplet[2]){
                            front++;
                        }
                        while(front < back && nums[back] == quadruplet[3]){
                            back--;
                        }
                    }
                }
                while(j + 1 < n && nums[j+1] == nums[j]){
                        j++;
                }
            }
            while(i + 1 < n && nums[i+1] == nums[i]){
                        i++;
            }
        }
        return ans;
        /*
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>>sv;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    int x = (long long)target - ((long long) nums[i] + (long long)nums[j] + 
                                                (long long)nums[k]);
                    if(binary_search(nums.begin()+k+1, nums.end(), x)){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(x);
                        sort(v.begin(), v.end());
                        sv.insert(v);
                    }
                 }
            }
        }
        vector<vector<int>>ans(sv.begin(),sv.end());
        return ans;
        */
    }
};