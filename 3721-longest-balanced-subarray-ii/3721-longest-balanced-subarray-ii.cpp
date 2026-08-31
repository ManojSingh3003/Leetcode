class Solution {
private:
    vector<int> segMin, segMax, lazy;
    int n;

    void propogate(int i,int l,int r){
        if(lazy[i]!=0){
            segMin[i]+=lazy[i];
            segMax[i]+=lazy[i];

            if(l!=r){
                lazy[2*i+1]+=lazy[i];
                lazy[2*i+2]+=lazy[i];
            }
            lazy[i]=0;
        }
    }

    void update(int i,int l,int r,int st,int ed,int val){
        propogate(i,l,r);

        if(st>r || l>ed) return;
        else if(st<=l && r<=ed){
            lazy[i]+=val;
            propogate(i,l,r);
            return;
        }else{
            int mid=(r-l)/2+l;
            update(2*i+1,l,mid,st,ed,val);
            update(2*i+2,mid+1,r,st,ed,val);

            segMin[i]=min(segMin[2*i+1],segMin[2*i+2]);
            segMax[i]=max(segMax[2*i+1],segMax[2*i+2]);
        }
    }

    int query(int i,int l,int r){
        propogate(i,l,r);

        if(segMin[i]>0 || segMax[i]<0)return -1;
        if(l==r)return l;
        
        int mid=(r-l)/2+l;
        int left=query(2*i+1,l,mid);
        if(left!=-1)return left;
        int right=query(2*i+2,mid+1,r);
        return right;
    }

public:
    int longestBalanced(vector<int>& nums) {
        n=nums.size();
        segMin.assign(4*n,0);
        segMax.assign(4*n,0);
        lazy.assign(4*n,0);
        

        map<int,int> mp;
        int res=0;

        for(int i=0;i<n;i++){
            int val=(nums[i]%2)? -1 : 1;

            int prev=-1;
            if(mp.count(nums[i])){
                prev=mp[nums[i]];
            }

            if(prev!=-1){
                //[0-prev] update -val
                update(0,0,n-1,0,prev,-val);
            }
            //[0-i] update val
            update(0,0,n-1,0,i,val);
            //[0-i] query 0;
            int ind=query(0,0,n-1);
            if(ind!=-1){
                res=max(res,i-ind+1);
            }

            mp[nums[i]]=i;
        }
        return res;
    }
};