class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int count = 1;
        int size = grades.size();
        while(count < size){
            size = size - count;
            if(count < size) count++;
        }
        return count;
    }
};