#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,k,c;
        cin>>n>>k;
        ll a[n],d[n],b[k];
        map<ll,ll>mp;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>d[i];
        for(int i=0;i<k;i++)cin>>b[i];
        ll curr=0;
        for(int i=0;i<n;i++){
            mp[a[i]]=mp[a[i]]+d[i];
            curr=d[i]+curr;
        }
        for(int i=0;i<k;i++){
            ll th=curr-b[i];
            curr=b[i];
            if(i%2==0){
                ll m=0;
                while(m<th){
                    auto it = mp.begin();
                    ll x=(*it).first;
                    ll y=(*it).second;
                    if(y>th-m){
                        y=y-(th-m);
                        mp[x]=y;
                        m=th;
                    }
                    else{
                        m=m+y;
                        mp.erase(x);
                    }
                }
            }
            else{
                ll m=0;
                while(m<th){
                    auto it = --mp.end();
                    ll x=(*it).first;
                    ll y=(*it).second;
                    if(y>th-m){
                        y=y-(th-m);
                        mp[x]=y;
                        m=th;
                    }
                    else{
                        m=m+y;
                        mp.erase(x);
                    }
                }
            }
        }

        ll sum=0;
        for(auto it = mp.begin();it!=mp.end();++it){
            ll x=(*it).first;
            ll y=(*it).second;
            sum = sum + x*y;
        }
        cout<<sum<<endl;
    }
    return 0;
    }