#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll dp[5001][5002];
ll arr[5001];
ll n,m;
ll faul(int i, int u, int l, int s, int k){
    if(i>=n and k==i-1){
        // cout<<k<<" "<<i<<endl;
        return 0;
    }
    else if(i>=n)return -100000;
    else if(k!=-1 and dp[i][k]!=-1)return dp[i][k];
    ll ways=-10000;
    if(i-1==k){
        if(arr[i]==m){
            s++;
            if(i!=n-2) ways=1+faul(i+1,0,0,0,i);
            else if(i==n-2 and arr[i+1]==m){
                return 2;
            }
        }
        else if(arr[i]>m)u++;
        else l++;
        ways=max(ways,faul(i+2,u,l,s,k));
        if(k==-1)return dp[i][5001]=ways;
        return dp[i][k]=ways;
    }
    if(arr[i]==m)s++;
    else if(arr[i]>m)u++;
    else l++;
    if(arr[i-1]==m)s++;
    else if(arr[i-1]>m)u++;
    else l++;
    
    ll tot = s+u+l;
    ll cnt=tot;
    tot=tot/2 +1;
    if(tot>l and tot<cnt-u+1){
        ways=1+faul(i+1,0,0,0,i);
    }
    // if(i==3)cout<<k<<endl;
    ways=max(ways,faul(i+2,u,l,s,k));
    return dp[i][k]=ways;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    while (t--){
        cin>>n;
        ll orig[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            orig[i]=arr[i];
            for(int j=0;j<n;j++)dp[i][j]=-1;
        }
        sort(orig,orig+n);
        m=orig[n/2];
        // cout<<m<<endl;
        cout<<faul(0,0,0,0,-1)<<endl;
    }
    return 0;
    }