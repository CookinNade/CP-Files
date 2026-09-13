#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        map<ll,ll>mp;
        ll q[n];
        ll r[n];
        for(int i=0;i<n;i++) cin>>q[i];
        for(int i=0;i<n;i++)cin>>r[i];
        for(int i=0;i<n;i++){
            d=(k-r[i]);
            d=d/(r[i]+1);
            mp[d]++;
            // cout<<d<<" ";
        }
        // cout<<endl;
        sort(q,q+n);
        cnt=0;
        for(int i=0;i<n;i++){
            auto it =mp.lower_bound(q[i]);
            if(it==mp.end())break;
            else{
                cnt++;
                mp[(*it).first]--;
                if(mp[(*it).first]==0)mp.erase((*it).first);
            }
        }
        cout<<cnt<<endl;

    }
    return 0;
    }