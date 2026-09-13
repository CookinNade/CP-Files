#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n+1];
        ll g[n+1];
        for(int i=1;i<=n;i++)cin>>arr[i];
        g[0]=0ll;
        for(int i=1;i<=n;i++){
            if(arr[i]<0)g[i]=g[i-1]+abs(arr[i]);
            else g[i]=g[i-1];
        }
        ll ans=0;
        ll ind=-1;
        for(int i=1;i<=n;i++){
            // cout<<i<<" "<<g[i]<<" "<<arr[i]<<" "<<g[i]-arr[i]<<endl;
            if(arr[i]>0 and g[i]-arr[i]>ans){
                ans=g[i]-arr[i];
                ind=i;
            }
        }
        if(ans==0 or ind ==-1){
            cout<<0<<'\n'<<'\n';
        }
        else{
            vector<ll>v;
            cnt=0;
            for(ll i=ind-1;i>=1;i--){
                if(cnt%2==0 and arr[i]>0){
                    cnt++;
                    v.push_back(i);
                }
                else if(cnt%2 and arr[i]<0){
                    cnt++;
                    v.push_back(i);
                }
            }
            v.push_back(ind);
            cout<<v.size()<<'\n';
            for(auto x:v)cout<<x<<" ";
            cout<<'\n';
        }
    }
    return 0;
    }