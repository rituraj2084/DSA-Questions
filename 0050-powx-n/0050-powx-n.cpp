class Solution {
public:
    double myPow(double x, int n) {
        double ans = pow(x, n);
        return ans;
        
        // double ans = 1;
        // if(n>=0){
        //     for(int i = 0; i < n; i++){
        //         ans = ans*x; 
        //     }
        // }
        // else{
        //     n = -n;
        //     for(int i = 0; i < n; i++){
        //         ans = ans*x; 
        //     }
        //     ans = 1/ans;
        // }
        // return ans;
    }
};