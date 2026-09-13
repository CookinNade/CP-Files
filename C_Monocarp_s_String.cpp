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
    string s; int tot=0;
    char c;
    while (t--){
        cin>>n>>s;
        ll acnt=0,bcnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a')acnt++;
            else bcnt++;
        }
        if(acnt==bcnt){
            cout<<0<<endl;
        }
        else{
            map<ll,vector<ll>>mp;
            ll bog,smol;
            if(acnt>bcnt){
                c='a';
                d=acnt-bcnt;
                bog=acnt;
                smol=bcnt;
            }
            else{
                c='b';
                d=bcnt-acnt;
                bog=bcnt;
                smol=acnt;
            }
            cnt=0;
            ll ans = LLONG_MAX;
            for(int i=0;i<n;i++){
                if(s[i]==c)cnt++;
                else cnt--;
                mp[cnt].push_back(i);
                // cout<<cnt<<" ";
            }
            // cout<<endl;
            cnt=0;
            for(int i=0;i<n;i++){
                if(s[i]==c)cnt++;
                else cnt--;
                ll req;
                if(s[i]==c)req= cnt+d-1;
                else req=cnt+d+1;
                // cout<<req<<endl;
                if(mp.find(req)!=mp.end()){
                    auto it = lower_bound(mp[req].begin(),mp[req].end(),i);
                    if(it==mp[req].end())continue;
                    else{
                        // for(int j=0;j<mp[req].size();j++)cout<<mp[req][j]<<" ";
                        // cout<<endl;
                        ans= min(ans,(*it)-i+1ll);
                        // cout<<ans<<" "<<req<<endl;
                    }
                }
            }
            if(ans==n)cout<<-1<<endl;
            else cout<<ans<<endl;
        }
    }
    return 0;
    }