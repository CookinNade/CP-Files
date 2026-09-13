#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n>>m>>k;
    ll head[n];
    map<ll,ll>mp;
    for(int i=0;i<n;i++)cin>>head[i];
    for(int i=0;i<m;i++){
        cin>>a;
        mp[a]++;
    }
    sort(head,head+n);
    cnt=0;
    for(int i=0;i<n;i++){
        auto it = mp.lower_bound(head[i]);
        if(it==mp.end()){
            break;
        }
        else{
            mp[(*it).first]--;
            cnt++;
            if(mp[(*it).first]<=0){
                mp.erase((*it).first);
            }
        }
    }
    if(cnt>=k)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
    }