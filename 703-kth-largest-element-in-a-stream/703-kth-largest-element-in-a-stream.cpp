class KthLargest {
public:
    /*
        why min heap? bcuz kth largest elem in max-heap(n size)=to elem of k size min heap
         1.create a min heap and initially insert k elem from vector to heap
         2. pop top elem whenever requires
    */
    //min heap
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        //maintaining k size min-heap
        for(int i=0;i<nums.size();i++){
            while(pq.size()>=k and pq.top()<nums[i])
                pq.pop();
            
            if(pq.size()<k)
                pq.push(nums[i]);
        }
    }
    
    int add(int val) {
    //1. when new comer elem is lesser than top elem of heap then just return top elem
    //2. if new comer is greater then it may be our ans so pop the top and push into heap
        
        if(pq.size()<k){
            pq.push(val);
        }else if(pq.top()<val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */