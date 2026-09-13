#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n+1];
        for(int i=1;i<=n;i++)cin>>arr[i];
        vector<int>v;
        v.push_back(1);
        int ans=1;
        if(n==1){
            cout<<1<<'\n';
            continue;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                v.push_back(i);
                if(i*i!=n)v.push_back(n/i);
            }
        }
        for(int i=0;i<v.size();i++){
            ll mg=0;
            a=v[i];
            for(int j=1;j<=a;j++){
                ll g=0;
                for(int k=a+j;k<=n;k=k+a){
                    // if(k+)
                    g=gcd(g,abs(arr[k]-arr[k-a]));
                }
                mg=gcd(g,mg);
            }
            if(mg!=1)ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
    }