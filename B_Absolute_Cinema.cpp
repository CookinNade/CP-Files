#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
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
        ll mx[n];
        ll mn[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++)mx[i]=max(a[i],b[i]);
        for(int i=0;i<n;i++)mn[i]=min(a[i],b[i]);
        cout<<accumulate(mx,mx+n,0ll)+*max_element(mn,mn+n)<<endl;
    }
    return 0;
    }