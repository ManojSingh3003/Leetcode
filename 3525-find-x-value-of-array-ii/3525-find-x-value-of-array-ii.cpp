class Solution {
private:
    struct Node{
        int cnt[5]={0};
        long long pro=0;
    };
    class SegmentTree {
        public:
            int n, k;
            vector<Node> segTree;

            SegmentTree (vector<int>& nums, int k){
                this->k =k;
                this->n=nums.size();
                segTree.resize(4*n,Node());
                build(0,0,n-1,nums);
            }

            void leafNode(int i, int val) {
                for (int x = 0; x < k; x++) {
                    segTree[i].cnt[x] = 0;
                }
                int r = val % k;
                segTree[i].cnt[r] = 1;
                segTree[i].pro = r;
            }

            Node mergeNode(Node& left,Node& right){
                Node res;
                res.pro =(left.pro * right.pro)%k;
                for(int r=0;r<k;r++){   
                    res.cnt[r]=left.cnt[r];
                }
                for(int r=0;r<k;r++){
                    int r1=(left.pro * r)%k;
                    res.cnt[r1] += right.cnt[r];
                }
                return res;
            }

            void build(int i,int l,int r,vector<int>& nums){
                if(l==r){
                    leafNode(i,nums[l]);
                    return;
                }
                int mid = l + (r-l)/2; 
                build(2*i+1,l,mid,nums);
                build(2*i+2,mid+1,r,nums);

                segTree[i]=mergeNode(segTree[2*i+1],segTree[2*i+2]);
            }

            void segTreeUpdate(int i,int l,int r,int ind,int val){
                if(l==r){
                    leafNode(i,val);
                    return;
                }
                int mid= l+(r-l)/2;
                if(ind<=mid){
                    segTreeUpdate(2*i+1,l,mid,ind,val);
                }else{
                    segTreeUpdate(2*i+2,mid+1,r,ind,val);
                }

                segTree[i]= mergeNode(segTree[2*i+1],segTree[2*i+2]);
            }

            void update(int ind,int val){
                segTreeUpdate(0,0,n-1,ind,val);
            }

            Node segTreeQuery(int st,int ed,int i,int l,int r){
                if(l>=st && r<=ed){
                    return segTree[i];
                }
                int mid =l+(r-l)/2;

                if(ed<=mid){
                    return segTreeQuery(st,ed,2*i+1,l,mid);
                }
                if(st>mid){
                    return segTreeQuery(st,ed,2*i+2,mid+1,r);
                }

                Node left=segTreeQuery(st,ed,2*i+1,l,mid);
                Node right=segTreeQuery(st,ed,2*i+2,mid+1,r);

                return mergeNode(left,right);
            }
            
            Node query(int st,int ed){
                return segTreeQuery(st,ed,0,0,n-1);
            }
    };
    



public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        vector<int> ans;

        int n=nums.size();
        SegmentTree segTree(nums,k);

        for(auto &q:queries){
            int ind=q[0];
            int val=q[1];
            int st=q[2];
            int x=q[3];

            segTree.update(ind,val);

            Node res=segTree.query(st,n-1);
            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};