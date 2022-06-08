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
        
        /* //using recursion
        if(n>=0){
            if(n == 0){
            return 1;
            }
            return x*myPow(x, n-1);
        }
        else{
            n *= -1;
            double ans = x*myPow(x, n-1);
            ans = 1/ans;
            return ans;
        }
        */
        
        /*
        //using in-built function
        double ans = pow(x, n);
        return ans;
        */
    }
};