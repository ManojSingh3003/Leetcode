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

public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        int n=h.size();
        vector<int> seg(4*n);
        build(0,0,n-1,h,seg);
        vector<int> res(q.size());

        for(int j=0;j<q.size();j++){
    
            int u=min(q[j][0],q[j][1]);
            int v=max(q[j][0],q[j][1]);
            int a=h[u];
            int b=h[v];

            if (u==v || h[u]<h[v]) {
                res[j]=v;
                continue;
            }

            int ans=-1;
            int st=v+1,ed=n-1;
            while(st<=ed){
                int mid=(ed-st)/2+st;
                int ind=query(0,0,n-1,v+1,mid,h,seg);
                
                if(ind!=-1 && h[ind]>b && h[ind]>a){
                    ans=ind;
                    ed=mid-1;
                }else{
                    st=mid+1;
                }
            }
            res[j]=ans;
        }
        return res;
    }
};