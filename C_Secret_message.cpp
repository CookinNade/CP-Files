#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        bool ase[26][n];
        for(int i=0;i<26;i++){
            for(int j=0;j<n;j++){
                ase[i][j]=false;
            }
        }
        for(int i=0;i<k;i++){
            cin>>s;
            for(int j=0;j<n;j++){
                ase[s[j]-'a'][j]=true;
            }
        }
        vector<ll>v;
        v.push_back(1);
        int ans[n];
        int len=n+5;
        for(int i=2;i<=n/2;i++)if(n%i==0)v.push_back(i);
        for(int i=0;i<v.size();i++){
            ll f = v[i];
            bool paisi=false;
            cnt=0;
            for(int j=0;j<f;j++){
                for(l=0;l<26;l++){
                    bool hobe=true;
                    for(r=j;r<n;r=r+f){
                        if(!ase[l][r]){
                            hobe=false;
                            break;
                        }
                    }
                    if(hobe){
                        cnt++;
                        ans[j]=l;
                        break;
                    }
                }
                if(cnt==f){
                    paisi=true;
                    len=f;
                    break;
                }
            }
            if(paisi)break;
        }
        string ss="";
        if(len>n)cout<<s<<endl;
        else{
            for(;ss.length()<n;){
                for(int i=0;i<len;i++){
                    char c = ans[i]+'a';
                    ss.push_back(c);
                }
            }
            cout<<ss<<endl;
        }
    }
    return 0;
    }