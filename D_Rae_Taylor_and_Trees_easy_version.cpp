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
        ll arr[n];
        ll suff[n];
        ll pref[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll mn=1e9+10;;
        for(int i=0;i<n;i++){
            mn=min(mn,arr[i]);
            pref[i]=mn;
        }
        mn=-1;
        for(int i=n-1;i>=0;i--){
            mn=max(mn,arr[i]);
            suff[i]=mn;
        }
        int no=0;
        for(int i=0;i<n-1;i++){
            if(pref[i]>suff[i+1])no++;
        }
        // for(int i=0;i<n;i++){
        //     cout<<pref[i]<<" ";
        // }cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<suff[i]<<" ";
        // }cout<<endl;
        if(no)cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
    }