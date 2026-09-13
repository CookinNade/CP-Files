#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,cnt,r,l,k,x,aa,bb; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        ll a[n];
        ll b[n];
        pair<ll,ll> pr[n];
        vector<ll>v; ll tot=0;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++){
            cin>>b[i];
            v.push_back(a[i]);v.push_back(b[i]);
            tot = tot+abs(a[i]-b[i]);
            ll mx = max(a[i],b[i]);
            ll mn = min(a[i],b[i]);
            pr[i]={mn,mx};
        }
        sort(v.begin(),v.end());
        int dir =0;
        for(int i=0;i<n;i++){
            auto it = lower_bound(v.begin(),v.end(),a[i]);
            auto nit = lower_bound(v.begin(),v.end(),b[i]);
            if(abs(it-nit)>1){
                dir++;break;
            }
        }
        if(dir)cout<<tot<<endl;
        else{
            ll diff = 1e15;
            sort(pr,pr+n);
            for(int i=0;i<n-1;i++){
                int arr[4]={pr[i].first,pr[i].second,pr[i+1].first,pr[i+1].second};
                sort(arr,arr+4);
                ll def = abs(pr[i].first-pr[i].second) + abs(pr[i+1].first-pr[i+1].second);
                ll real = abs(arr[3]-arr[0])+abs(arr[2]-arr[1]);
                diff = min(diff,real-def);
            }
            cout<<tot+diff<<endl;
            // cout<<"from here"<<endl;
        }

    }
    return 0;
    }