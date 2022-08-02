class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //max heap
        priority_queue<int> pq;
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                pq.push(matrix[i][j]);
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }
        return pq.top();
        // //Brute force
        // int n = matrix.size();
        // vector<int> arr;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         arr.push_back(matrix[i][j]);
        //     }
        // }
        // sort(arr.begin(), arr.end());
        // return arr[k-1];
    }
};