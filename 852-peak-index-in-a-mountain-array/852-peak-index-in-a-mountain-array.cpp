class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return max_element(arr.begin(), arr.end()) - arr.begin();
        /*
        int i;
       for(i = 0; i < arr.size(); i++){
           if(arr[i] > arr[i + 1]){
               break;
           }
       }
        return i;
        */
    }
};