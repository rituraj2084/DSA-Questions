class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2) return findMedianSortedArrays(nums2, nums1);	// Make sure A2 is the shorter one.
    
    int lo = 0, hi = N2 * 2;
    while (lo <= hi) {
        int mid2 = (lo + hi) / 2;   // Try Cut 2 
        int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly
        
        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];	// Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];
        
        if (L1 > R2) lo = mid2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1) hi = mid2 - 1;	// A2's lower half too big; need to move C2 left.
        else return (max(L1,L2) + min(R1, R2)) / 2;	// Otherwise, that's the right cut.
    }
    return -1;
        /*
        int m = nums1.size(), n = nums2.size();
        if(m > n){
            
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0, high = m, medianPos = ((m+n)+1)/2;
        while(low <= high){
            int cut1 = (low+high)/2;
            int cut2 = medianPos - cut1;
            int l1 = (cut1 ==0)?INT_MIN:nums1[cut1 - 1];
            int l2 = (cut2 == 0)?INT_MIN:nums2[cut2-1];
            int r1 = (cut1 == m)?INT_MAX:nums1[cut1];
            int r2 = (cut2 == n)?INT_MAX:nums2[cut2];
            if(l1<r2 && l2<r1){
                if((m+n)%2 != 0){
                    return max(l1,l2);
                }
                else{
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }
            }
            else if(l1>r2) high = cut1-1;
            else low = cut1 + 1;
        }
        return 0.0;
        */
        /*
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
        */
    }
};