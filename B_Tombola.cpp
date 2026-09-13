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
    ll g[n][m];
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>g[i][j];
    }
    set<ll>st;
    for(int i=0;i<k;i++){
        cin>>a;
        st.insert(a);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<m;j++){
            if(st.find(g[i][j])!=st.end())cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
    }