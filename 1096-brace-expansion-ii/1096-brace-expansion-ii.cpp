class Solution {
public:
    string s;
    int n,ind;

    //cartesian product
    set<string> prod(set<string>& a,set<string>& b){
        set<string> res;
        for(auto& x:a){
            for(auto& y:b){
                res.insert(x+y);
            }
        }
        return res;
    }
    //add
    set<string> add(){
        set<string> res=parse();
        while(ind<n && s[ind]==','){
            ind++;
            set<string> next=parse();
            res.insert(next.begin(),next.end());
        }
        return res;
    }
    //parse;
    set<string> parse(){
        set<string> res={""};
        while(ind<n && s[ind]!='}' && s[ind]!=','){
            set<string> cur;
            if(s[ind]=='{'){
                ind++;
                cur=add();
                ind++;
            }else{
                cur.insert(string(1,s[ind]));
                ind++;
            }
            res=prod(res,cur);
        }
        return res;
    }

    vector<string> braceExpansionII(string exp) {
        s=exp;
        n=s.size();
        ind=0;
        set<string> ans=add();
        return vector<string>(ans.begin(),ans.end());
    }
};
