class Solution {
private:
    void update(int i,int l,int r,int ind,vector<int>& seg){
        if(l==r){
            seg[i]=1;
            return;
        }
        int mid=(r-l)/2+l;
        if(ind>mid){
            update(2*i+2,mid+1,r,ind,seg);
        }else{
            update(2*i+1,l,mid,ind,seg);
        }
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    int query(int i,int l,int r,int st,int ed,vector<int>&seg){
        if(r<st || l>ed) return 0;
        else if(l>=st && r<=ed) return seg[i];
        else{
            int mid=(r-l)/2+l;
            int left= query(2*i+1,l,mid,st,ed,seg);
            int right= query(2*i+2,mid+1,r,st,ed,seg);

            return left+right;
        }
    }
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();

        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }

        vector<int> seg(4*n);
        
        update(0,0,n-1,mp[nums1[0]],seg);

        long long ans=0;
        for(int i=1;i<n-1;i++){
            int common=query(0,0,n-1,0,mp[nums1[i]]-1,seg);
            int non_common=i-common;
            int right_common=(n-mp[nums1[i]]-1)-non_common;
            cout<<i<<" "<<common<<" "<<right_common<<endl;
            ans+=(1LL*common)*(1LL*right_common);

            update(0,0,n-1,mp[nums1[i]],seg);
        }
        return ans;
    }
};