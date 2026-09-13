#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[n];ll b[m];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    ll cnt=0;
    vector<ll>va;
    vector<ll>vb;
    for(int i=0;i<n;i++){
        if(a[i]){
            cnt++;
            if(i==n-1)va.push_back(cnt);
        }
        else{
            if(cnt)va.push_back(cnt);
            cnt=0;
        }
    }
    cnt=0;
    for(int i=0;i<m;i++){
        if(b[i]){
            cnt++;
            if(i==m-1)vb.push_back(cnt);
        }
        else{
            if(cnt)vb.push_back(cnt);
            cnt=0;
        }
    }
    ll ans=0;
    for(int i=1;i*i<=k;i++){
        if(k%i==0){
            int j=k/i;
            ll cnta=0;
            ll cntb=0;
            for(int x=0;x<va.size();x++){
                if(va[x]>=i){
                    cnta=va[x]-i+1+cnta;
                }
            }
            for(int x=0;x<vb.size();x++){
                if(vb[x]>=j){
                    cntb=vb[x]-j+1+cntb;
                }
            }
            ans=ans+cnta*cntb;
            if(i==j)continue;
            cnta=0;
            cntb=0;
            for(int x=0;x<va.size();x++){
                if(va[x]>=j){
                    cnta=va[x]-j+1+cnta;
                }
            }
            for(int x=0;x<vb.size();x++){
                if(vb[x]>=i){
                    cntb=vb[x]-i+1+cntb;
                }
            }
            ans=ans+cnta*cntb;
        }
    }
    cout<<ans<<endl;
    // for(auto x:va)cout<<x<<" ";
    // cout<<endl;
    // for(auto x:vb)cout<<x<<" ";
    return 0;
    }