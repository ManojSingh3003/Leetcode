class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k1;

    KthLargest(int k, vector<int>& nums) {
        k1=k;
        for(int i=0;i<nums.size();i++){
            if(pq.size()<k1){
            pq.push(nums[i]);
        }else{
            if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        }
    }
    
    int add(int val) {
        if(pq.size()<k1){
            pq.push(val);
        }else{
            if(pq.top()<val){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */