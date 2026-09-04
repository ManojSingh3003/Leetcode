class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n=a.size(),m=b.size();
        int x=(m+n-1)/n;
        
        string z="";
        for(int i=0;i<x;i++)z+=a;

        if(z.find(b)!=string::npos){
            return x;
        }
        z+=a;
        if(z.find(b)!=string::npos){
            return x+1;
        }

        return -1;
    }
};