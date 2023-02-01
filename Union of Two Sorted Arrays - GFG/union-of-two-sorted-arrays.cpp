//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    #include<bits/stdc++.h>
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int>arr3;
        set<int>s;
        int a = min(n, m);
        int i = 0, j = 0;
        while(i<a && j < a){
            if(arr1[i] < arr2[j]){
                s.insert(arr1[i]);
                i++;
            }
            else if(arr1[i] > arr2[j]){
                s.insert(arr2[j]);
                j++;
            }
            else{
                s.insert(arr1[i]);
                i++; 
                j++;
            }
        }
        while(i<n){
            s.insert(arr1[i]);
            i++;
        }
        while(j<m){
            s.insert(arr2[j]);
            j++;
        }
        for(auto it: s){
            arr3.push_back(it);
        }
        return arr3;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends