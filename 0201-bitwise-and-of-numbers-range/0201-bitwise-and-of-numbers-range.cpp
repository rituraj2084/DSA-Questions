class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int sft = 0;
        while(left != right){
            left = left>>1;
            right = right>>1;
            sft++;
        }
        return (left<<sft);
    }
};