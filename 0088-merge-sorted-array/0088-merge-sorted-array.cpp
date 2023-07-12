class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int arr[m+n];
        int k = 0;
        for(int i = 0; i < m; i++){
            arr[k++] = nums1[i];
        }
        for(int i = 0; i < n; i++){
            arr[k++] = nums2[i];
        }
        sort(arr, arr+n+m);
        k = 0;
        for(int i = 0; i < m; i++){
            nums1[i] = arr[k++];
        }
        for(int i = m; i < m+n; i++){
            nums1[i] = arr[k++];
        }
    }
};