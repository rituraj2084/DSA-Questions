class Solution {
public:
    int mySqrt(int x) {
        int ans;
        long long l = 0, r = x;
        while(l <= r){
            long long mid = l + (r-l)/2;
            if(mid*mid == x) return mid;
            else if(mid*mid < x){
                l = mid+1;
                ans = mid;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};