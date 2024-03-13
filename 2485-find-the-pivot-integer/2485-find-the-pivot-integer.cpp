class Solution {
public:
    int pivotInteger(int n) {
       if(n==1)return 1;
        int sum=n*(n+1)/2;
        int left_sum=0;
        for(int i=1;i<n;i++){
            
            if(left_sum==sum-left_sum-i){
                return i;
            }
            left_sum+=i;
        }
        return -1; 
    }
};