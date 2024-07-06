class Solution {
public:
    int passThePillow(int n, int time) {
        
        int traverse = n -1; 

        int round = time / traverse;

        int res = (time % traverse);

        int ans = n - res;

        if(round % 2 == 0) return res +1;

        return ans;
    }
};