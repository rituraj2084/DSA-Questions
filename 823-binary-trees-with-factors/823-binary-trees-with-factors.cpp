class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        long res = 0, mod = pow(10, 9) + 7;
        sort(A.begin(), A.end());
        unordered_map<int, long> dp;
        for (int i = 0; i < A.size(); ++i) {
            dp[A[i]] = 1;
            for (int j = 0; j < i; ++j)
                if (A[i] % A[j] == 0)
                    dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
            res = (res + dp[A[i]]) % mod;
        }
        return res;
    }
    /*
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int, int>mp;
        int mod = 1000000007;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]] = 1;
        }
        
        for(int i = 1; i < arr.size(); i++){
            long long int count = 0;
            auto it = mp.find(arr[i]);
            for(int j = 0; j < i; j++){
                if(arr[i]%arr[j] == 0){
                    //int k = arr[i]/arr[j];
                    auto it2 = mp.find(arr[i]/arr[j]);
                    auto it3 = mp.find(arr[j]);
                    if(it2 != mp.end()){
                        
                        count += ((it2->second)* (it3->second));
                    }
                }
            }
            it->second += count;
        }
        
        long long int sum = 0;
        for(auto it: mp){
            sum += it.second;
        }
        return(sum%1000000007);
    }
    */
};