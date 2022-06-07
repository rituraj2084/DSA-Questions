// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int mergeCount(long long arr[],long long low,long long mid,long long high){
       long long  n1=mid-low+1;
       long long n2=high-mid;
       long long lft[n1];
       long long rht[n2];
       for(int i=0;i<n1;i++){
           lft[i]=arr[low+i];
       }
       for(int i=0;i<n2;i++){
           rht[i]=arr[mid+1+i];
       }
       long long i=0;
       long long j=0;
       long long k=low;
       long long int ans=0;
       while(i<n1&&j<n2){
           if(lft[i]<=rht[j]){
               arr[k]=lft[i];
               i++;
           }
           else{
           arr[k]=rht[j];
           j++;
           ans+=(n1-i);
           }
           k++;
       }
       while(i<n1){
           arr[k++]=lft[i++];
       }
       while(j<n2){
           arr[k++]=rht[j++];
       }
       return ans;
   }
   long long int inverse(long long arr[],long long low,long long high){
       long long ans=0;
       if(low<high){
           long long mid=low+(high-low)/2;
           ans+=inverse(arr,low,mid);
           ans+=inverse(arr,mid+1,high);
           ans+=mergeCount(arr,low,mid,high);
       }
       return ans;
   }

    long long int inversionCount(long long arr[], long long N)
    {
        return inverse(arr,0,N-1);
        
        /*
        long long int count = 0;
        for(long long int i = 0; i < N; i++){
            for(long long int j = i+1; j<N ; j++){
                if(arr[i] > arr[j]){
                    count++;
                }
            }
        }
        return count;
        */
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends