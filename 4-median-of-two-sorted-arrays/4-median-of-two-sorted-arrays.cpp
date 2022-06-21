class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int arr[m+n];
       int i = 0, j = 0, k = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]) arr[k++] = nums1[i++];
            else arr[k++] = nums2[j++];
        }
        while(i < m) arr[k++] = nums1[i++];
        while(j < n) arr[k++] = nums2[j++];
        n = n+m;
        if(n%2 == 1) {
            return (double) (arr[(n+1)/2 - 1]);
        }
        else{
            return (((double) arr[(n/2) - 1] + (double) arr[n/2])/ 2);
        }
    }
};