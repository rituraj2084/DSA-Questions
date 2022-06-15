class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {

        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;
        
        if(target < 0)
        {
            break;
        }

        while (front < back) {

            int sum = num[front] + num[back];

            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }

        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }

    return res;
        /*
        sort(nums.begin(), nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        for(int i = 0; i < nums.size() - 2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int low = i + 1, high = nums.size() - 1;
                while(low < high){
                    temp.clear();
                if(nums[i] + nums[low] + nums[high] == 0){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    ans.push_back(temp);
                    while((low < high && nums[low] == nums[low + 1])){
                        low++;
                    }
                    while((low < high && nums[high] == nums[high - 1])){
                    high--;
                    }
                    low++;
                    high--;
                }
                else if(nums[low] + nums[high] < nums[i]){
                    low++;
                }
                else{
                    high--;
                }
            }
        }  
        }
        return ans;
        */
        /*
        vector<int>temp;
        vector<vector<int>>ans;
        for(int i = 0; i < nums.size() - 2; i++){
            for(int j = i +1; j < nums.size() - 1; j++){
                for(int k = j + 1; k < nums.size(); k++){
                    temp.clear();
                    if(nums[i] + nums[j] + nums[k] == 0){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                    }
                    if(temp.size() != 0){
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
        */
    }
};