class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        while(n-->1){
            cout<<s<<endl;
            string s1="";
            int c=1;
            for(int i=0;i<s.length()-1;i++){
                if(s[i]==s[i+1]){
                    c++;
                }else{
                    s1+=to_string(c);
                    s1+=s[i];
                    c=1;
                }
            }
            s1+=to_string(c);
            s1+=s[s.length()-1];
            s=s1;
        }
        return s;
    }
};