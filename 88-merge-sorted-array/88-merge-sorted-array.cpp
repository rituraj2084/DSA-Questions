class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
        int i, k;
       for (i = 0; i < n; i++) {
    // take first element from arr1 
    // compare it with first element of second array
    // if condition match, then swap
    if (nums1[i] > nums2[0]) {
      int temp = nums1[i];
      nums1[i] = nums2[0];
      nums2[0] = temp;
    }

    // then sort the second array
    // put the element in its correct position
    // so that next cycle can swap elements correctly
    int first = nums2[0];
    // insertion sort is used here
    for (k = 1; k < m && nums2[k] < first; k++) {
      nums2[k - 1] = nums2[k];
    }
    nums2[k - 1] = first;
  }*/
        
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