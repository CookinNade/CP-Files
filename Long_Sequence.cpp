#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n>>k;
    vector<ll>g[n];
    for(int i=0;i<n;i++){
        cin>>l;
        for(int j=0;j<l;j++){
            cin>>a;
            g[i].push_back(a);
        }
    }
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        a=arr[i];
        if(arr[i]*(ll)g[i].size()>=k){
            k=k%(ll)g[i].size();
            if(k==0)cout<<g[i][g[i].size()-1]<<endl;
            else cout<<g[i][k-1]<<endl;
            break;
        }
        else k=k-arr[i]*(ll)g[i].size();
    }
    return 0;
    }