class Solution {
private:
    void build(int i,int l,int r,vector<int> &h,vector<int> &seg){
        if(l==r){
            seg[i]=l;
            return;
        }

        int mid=(r-l)/2+l;
        build(2*i+1,l,mid,h,seg);
        build(2*i+2,mid+1,r,h,seg);

        if( h[seg[2*i+1]]>h[seg[2*i+2]] ){
            seg[i]=seg[2*i+1];
        }else{
            seg[i]=seg[2*i+2];
        }
    }

    int query(int i,int l,int r,int st,int ed,vector<int>& h,vector<int>&seg){
        if(r<st || l>ed) return -1;
        else if(l>=st && r<=ed) return seg[i];
        else{
            int mid=(r-l)/2+l;
            int left= query(2*i+1,l,mid,st,ed,h,seg);
            int right= query(2*i+2,mid+1,r,st,ed,h,seg);

            if(left==-1)return right;
            if(right==-1)return left;
            if(h[left]>h[right])return left;
            else return right;
        }
    }
    void update(int i,int l,int r,int ind,vector<int>&h,vector<int> & seg){
        if(l==r){
            return;
        }
        int mid= (r-l)/2+l;
        if(ind>mid){
            update(2*i+2,mid+1,r,ind,h,seg);
        }else{
            update(2*i+1,l,mid,ind,h,seg);
        }

        if( h[seg[2*i+1]]>h[seg[2*i+2]] ){
            seg[i]=seg[2*i+1];
        }else{
            seg[i]=seg[2*i+2];
        }
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int> seg(4*n);
        build(0,0,n-1,baskets,seg);
        int res=n;
        for(int i=0;i<n;i++){
            int x=fruits[i];
            int ans=-1;
            int st=0,ed=n-1;
            while(st<=ed){
                int mid=(ed-st)/2+st;
                int ind=query(0,0,n-1,st,mid,baskets,seg);
                
                if(ind!=-1 && baskets[ind]>=x ){
                    ans=ind;
                    ed=mid-1;
                }else{
                    st=mid+1;
                }
            }
            cout<<i<<" "<<ans<<endl;
            if(ans!=-1){
                res--;
                baskets[ans]=0;
                update(0,0,n-1,ans,baskets,seg);
            }
        }
        return res;
    }
};