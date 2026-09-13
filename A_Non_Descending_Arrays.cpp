#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 998244353;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll a[n];
        ll b[n];
        ll ans =2;
        
        cnt=0;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++){
            if(b[i]>a[i])swap(a[i],b[i]);
        }
        if(n==1){
            cout<<ans<<endl;
            continue;
        }
        for(int i=0;i<n-1;i++){
            if(a[i]<=b[i+1]){
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++)ans=(ans*2ll)%M;
        cout<<ans<<endl;

    }
    return 0;
    }