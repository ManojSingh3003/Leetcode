class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.length();
        vector<int> l(26,n),r(26,-1);

        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            l[c]=min(l[c],i);
            r[c]=i;
        }

        vector<string> ans;
        vector<pair<int,int>> x;

        for(int c=0;c<26;c++){
            if(l[c]==n)continue;

            int l1=l[c];
            int r1=r[c];
            bool q=true;

            for(int i=l1;i<=r1;i++){
                int c1=s[i]-'a';
                if(l[c1]<l1){
                    q=false;
                    break;
                }
                r1=max(r1,r[c1]);
            }
            if(q){
                x.push_back({l1,r1});
            }
        }
        sort(x.begin(),x.end(),[](auto& a,auto& b){return a.second<b.second;} );

        int last=-1;
        for(auto &it:x){
            if(it.first >last){
                ans.push_back(s.substr(it.first , it.second-it.first+1));
                last=it.second;
            }
        }

        return ans;
    }
};