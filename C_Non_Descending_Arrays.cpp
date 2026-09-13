#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll a[n]; ll b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        set<ll>must;
        set<ll>opt;
        for(int i=1;i<n;i++){
            if(i==n-1){
                if(a[i]<b[i-1] or b[i]<a[i-1]){
                    must.insert(n-1);
                    must.insert(n-2);
                }
            }
            if(a[i]==b[i])opt.insert(i);
            if(a[i]>b[i+1] or b[i]>a[i+1]){
                must.insert(i);
                must.insert(i+1);
            }
            if(a[i]<b[i-1] or b[i]<a[i-1]){
                must.insert(i);
                must.insert(i+1);
            }
            if(must.find(i)==must.end())opt.insert(i);
        }
    }
    return 0;
    }