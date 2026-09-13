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
        ll tea[n+1]; tea[0]=0;
        for(int i=1;i<=n;i++)cin>>tea[i];
        ll test[n+1];
        for(int i=1;i<=n;i++)cin>>test[i];
        vector<ll>v; v.push_back(0);
        ll sum=0;
        for(int i=1;i<=n;i++){
            sum=sum+test[i];
            v.push_back(sum);
        }
        ll ans[n+1];
        ll full[n+1];
        fill(full,full+n+1,0ll);
        fill(ans,ans+1+n,0ll);
        for(int i=1;i<=n;i++){
            a=tea[i]+v[i-1];
            auto it = lower_bound(v.begin(),v.end(),a);
            if(it==v.end())full[i]++;
            else if((*it)==a){
                int ind = it - v.begin();
                full[ind+1]--; full[i]++;
            }
            else{
                int ind = it - v.begin();
                ans[ind]=ans[ind]+a-v[ind-1];
                full[ind]--; full[i]++;
            }
        }
        for(int i=1;i<=n;i++)full[i]=full[i-1]+full[i];
        for(int i=1;i<=n;i++)cout<<full[i]*test[i] + ans[i]<<" ";
        cout<<endl;
    }
    return 0;
    }