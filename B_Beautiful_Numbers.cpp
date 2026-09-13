#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>s;
        string e="";
        for(int i=1;i<s.length();i++){
            e.push_back(s[i]);
        }
        sort(e.begin(),e.end());
        ll ans=0; c=s[0]-'0';
        // cout<<cnt<<endl;
        // cout<<e<<endl;
        r=123123123;
        for(int i=1;i<=c;i++){
            ans=1;cnt=i;
            if(i==c)ans=0;
            for(int j=0;j<e.length();j++){
                cnt=cnt+e[j]-'0';
                if(cnt<10)continue;
                else ans++;
            }
            r=min(ans,r);
        }
        cout<<r<<endl;
    }
    return 0;
    }