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
        cin>>n>>k;
        map<ll,ll>mp;
        for(int i=0;i<=k;i++){
            mp[i]=0;
        }
        for(int i=0;i<n;i++){
            cin>>a;
            mp[a]++;
        }
        cnt=0;
        for(int i=0;i<=k;i++){
            if(i==k){
                cnt=max(cnt,mp[i]);
            }
            
            else if(mp[i]==0 and i!=k)cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
    }