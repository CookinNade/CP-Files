#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,b,d,cnt,r,l,k,x; 
    cin>>t;
    string s,w;
    while (t--){
        cin>>s>>w;
        map<char,ll>mps;
        map<char,ll>mpw;
        char c;
        for(int i=0;i<s.size();i++)mps[s[i]]++;
        for(int i=0;i<w.size();i++)mpw[w[i]]++;
        int noer=0;
        for(auto it = mps.begin();it!=mps.end();++it){
            c=(*it).first;
            if(mpw.find(c)==mpw.end() or mpw[c]<mps[c]){
                noer++;
                break;
            }
        }
        if(noer)cout<<"Impossible\n";
        else{
            string ans = "";
            l=0;
            for(auto it = mpw.begin();it!=mpw.end();++it){
                c=(*it).first;
                for(;l<s.size();l++){
                    if(s[l]<=c)ans.push_back(s[l]);
                    else break;
                }
                for(int i=0;i<mpw[c]-mps[c];i++) ans.push_back(c);
            }
            cout<<ans<<endl;
        }

    }
    return 0;
    }