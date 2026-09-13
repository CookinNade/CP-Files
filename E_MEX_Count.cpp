#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll freq[n+1];
        fill(freq,freq+n+1,0);
        ll age[n+1];
        ll piche[n+1];
        for(int i=0;i<n;i++){
            cin>>a;
            freq[a]++;
        }
        d=n+2;
        for(int i=0;i<=n;i++){
            if(freq[i]==0){
                d=i;
                break;
            }
        }
        age[0]=freq[0]-1;
        piche[n]=freq[n];
        ll ans[n+3];
        fill(ans,ans+3+n,0);
        for(int i=1;i<=n;i++)age[i]=freq[i]+age[i-1]-1;
        for(int i=n-1;i>=0;i--)piche[i]=freq[i]+piche[i+1];
        for(int i=0;i<=n;i++){
            if(d<i)break;
            if(i==0){
                ans[piche[i]+1]--;
                ans[freq[0]]++;
                continue;
            }
            ans[freq[i]]++;
            ans[piche[i]+age[i-1]+1]--;
        }
        cout<<ans[0]<<" ";
        for(int i=1;i<=n;i++){
            ans[i]=ans[i]+ans[i-1];
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
    }