class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(low < high){
            int mid = low + (high-low)/2;
            if(arr[low] <= arr[mid]){
                if(arr[mid] < arr[mid+1]){
                    low = mid+1;
                }
                else{
                    high = mid;
                }
            }
            else{
                high = mid;
            }
        }
        return high;
    }
};