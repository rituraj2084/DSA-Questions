class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while(low < high){
            int mid = low + (high-low)/2;
            if(arr[mid] < arr[mid+1]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
        
        // return max_element(arr.begin(), arr.end()) - arr.begin();
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