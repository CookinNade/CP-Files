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
        cin>>n;
        vector<pair<ll,ll>>v;
        m=n;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                cnt=0;
                while(n%i==0){
                    cnt++; 
                    n=n/i;
                }
                v.push_back({i,cnt});
            }
        }
        if(n!=1)v.push_back({n,1});
        ll ans=1;
        for(int i=0;i<v.size();i++){
            ll hi=v[i].second;
            ll lo=1,mid;
            while(hi-lo>1){
                mid=hi+lo;
                mid=mid/2;
                if(mid*m>=v[i].second)hi=mid;
                else lo=mid+1;
            }
            if(lo*m>=v[i].second){
                for(int j=0;j<lo;j++)ans=ans*v[i].first;
            }
            else for(int j=0;j<hi;j++)ans=ans*v[i].first;
        }
        cout<<ans<<endl;
    }
    return 0;
    }