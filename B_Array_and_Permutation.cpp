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
        ll ind[n+1];
        for(int i=0;i<n;i++){
            cin>>a;
            ind[a]=i+1;
        }
        ll arr[n];
        int no=0;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n-1;i++){
            if(ind[arr[i]]>ind[arr[i+1]]){
                no++;
                break;
            }
        }
        if(no)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
    }