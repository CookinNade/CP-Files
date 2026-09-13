#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            cin>>a;
            mp[a]++;
        }
        if(mp.find(0)==mp.end())cout<<"NO\n";
        else if(mp[0]==1)cout<<"YES\n";
        else{
            if(mp.find(1)==mp.end())cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
    return 0;
    }