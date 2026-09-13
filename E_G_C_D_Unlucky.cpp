#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,zeroer; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        vector<ll>v; ll srt[n];
        for(int i=0;i<n;i++) cin>>srt[i];
        sort(srt,srt+n);
        for(int i=1;i<n;i++) v.push_back(srt[i]-srt[i-1]);
        sort(v.begin(),v.end());
        zeroer=0;
        if(k>2)cout<<0<<endl;
        else if(k==1) cout<<v[0]<<endl;
        else{
            for(int i=0;i<n-1;i++){
                ll chk = srt[i]+srt[i+1];
                auto it= lower_bound(srt,srt+n,chk);
                if(it!=srt+n and *it==chk) {
                    // cout<<"reached here when it was "<<i<<endl;
                    // cout<<chk<<endl;
                    zeroer++;break;
                }
            }
            if(zeroer)cout<<0<<endl;
            else{
                ll mn = v[0];
                for(int i=0;i<v.size();i++){
                    ll fr = abs(v[i]-srt[i]);
                    ll sr = abs(v[i]-srt[i+1]);
                    ll srr = min(fr,sr);
                    mn = min(mn,srr);
                }
                cout<<mn<<endl;
            }
        }
    }
    return 0;
    }