class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currProd = 1;
        int maxProd = INT_MIN;
        for(int i = 0; i < n; i++){
            currProd = currProd * nums[i];
            if(currProd > maxProd) maxProd = currProd;
            if(currProd == 0) currProd = 1;
        }
        currProd = 1;
        for(int i = n-1; i >= 0; i--){
            currProd = currProd * nums[i];
            if(currProd > maxProd) maxProd = currProd;
            if(currProd == 0) currProd = 1;
        }
        return maxProd;
        /*
        int n = nums.size(), res = nums[0], l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            l =  (l ? l : 1) * nums[i];
            r =  (r ? r : 1) * nums[n - 1 - i];
            res = max(res, max(l, r));
        }
        return res;
        */
        /*
        // store the result that is the max we have found so far
    int r = nums[0];
        int n = nums.size();

    // imax/imin stores the max/min product of
    // subarray that ends with the current number nums[i]
    for (int i = 1, imax = r, imin = r; i < n; i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (nums[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(nums[i], imax * nums[i]);
        imin = min(nums[i], imin * nums[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
    */
    }
};