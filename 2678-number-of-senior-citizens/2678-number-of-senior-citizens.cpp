class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto detail: details){
            if((detail[11]-'0')*10 + (detail[12]-'0') > 60) count++;
        }
        return count;
    }
};