#define ll long long
class Solution {
private:

    class LazySGT{
    private:
        int n;
        ll MOD=1e9+7;
        vector<ll> sum_c,sum_sq,lazy;

        void push_down(int node,int l,int r){
            if(lazy[node]!=0){
                int mid=l+(r-l)/2;
                ll x=lazy[node];
                //left
                int left_len=mid-l+1;
                lazy[2*node]=(lazy[2*node]+x)%MOD;
                sum_sq[2*node]=(sum_sq[2*node] + (2*x*sum_c[2*node])%MOD + (((x*x)%MOD)*left_len)%MOD  )%MOD;
                sum_c[2*node]=(sum_c[2*node] + (x*(left_len)%MOD) )%MOD;
                //right
                int right_len=r-mid;
                lazy[2*node+1]=(lazy[2*node+1]+x)%MOD;
                sum_sq[2*node+1]=(sum_sq[2*node+1] + (2*x*sum_c[2*node+1])%MOD + (((x*x)%MOD)*right_len)%MOD  )%MOD;
                sum_c[2*node+1]=(sum_c[2*node+1] + ((x*right_len)%MOD) )%MOD;

                lazy[node]=0;
            }
        }
        void update(int node,int l,int r,int ql,int qr,ll x){
            if(qr<l || ql>r)return;
            if(ql<=l && r<=qr){
                int len=r-l+1;
                lazy[node]=(lazy[node]+x)%MOD;
                sum_sq[node]=(sum_sq[node] + (2*x*sum_c[node])%MOD + (((x*x)%MOD)*len)%MOD  )%MOD;
                sum_c[node]=(sum_c[node] + ((x*len)%MOD) )%MOD;
                return;
            }
            push_down(node,l,r);
            int mid=l+(r-l)/2;
            update(2*node,l,mid,ql,qr,x);
            update(2*node+1,mid+1,r,ql,qr,x);

            sum_c[node]=(sum_c[2*node] + sum_c[2*node+1])%MOD;
            sum_sq[node]=(sum_sq[2*node] + sum_sq[2*node+1])%MOD;
        }

    public:
        LazySGT(int size){
            n=size;
            sum_c.resize(4*n,0);
            sum_sq.resize(4*n,0);
            lazy.assign(4*n,0);
        }
        void add(int l,int r,ll x){
            update(1,0,n-1,l,r,x);
        }
        ll get_ans(){
            return sum_sq[1];
        }
    };
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        ll MOD=1e9+7;
        
        LazySGT tree(n);
        unordered_map<int,int> last_occ;
        ll ans=0;

        for(int i=0;i<n;i++){
            int prev=-1;
            if(last_occ.count(nums[i]))prev=last_occ[nums[i]];
            tree.add(prev+1,i,1);
            ans=(ans + tree.get_ans())%MOD;
            last_occ[nums[i]]=i;
        }

        return ans;
    }
};