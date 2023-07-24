class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        double ans = 1.0;
        if(nn<0){
            nn *= -1;
        }
        while(nn > 0){
           if(nn % 2 == 0){
               x = x*x;
               nn /= 2;
           } 
            if(nn % 2 != 0){
                ans = ans * x;
                nn -= 1;
            }
        }
        if(n < 0){
            ans = 1 / ans;
        }
        return ans;
        // double ans = pow(x, n);
        // return ans;
        
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