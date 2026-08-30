class Solution {
private:
    void build(int i,int l,int r, vector <int>&nums,vector<int>&seg){
        if(l==r){seg[i]=nums[l];return;}
        
        int mid= (r-l)/2 +l;
        
        build(2*i+1,l,mid,nums,seg );
        build(2*i+2,mid+1,r,nums,seg);
        
        seg[i]=max(seg[2*i+1],seg[2*i+2]);
       
    }

    int query_update(int i,int l,int r,int x,vector<int>&seg){
        if(seg[i]<x)return -1;

        if(l==r){
            seg[i]=0;
            return l;
        }

        int mid=(r-l)/2+l;
        int ans=-1;
        if(seg[2*i+1]>=x){
            ans=query_update(2*i+1,l,mid,x,seg);
        }else{
            ans=query_update(2*i+2,mid+1,r,x,seg);
        }
        seg[i]=max(seg[2*i+1],seg[2*i+2]);

        return ans;
    }


public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int> seg(4*n);
        build(0,0,n-1,baskets,seg);
        int res=n;
        for(int i=0;i<n;i++){
            int x=fruits[i];
            if(query_update(0,0,n-1,x,seg)!=-1)res--;
        }
        return res;
    }
};