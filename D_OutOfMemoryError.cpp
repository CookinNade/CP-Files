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
        cin>>n>>m>>k;
        ll arr[n+1];
        ll orig[n+1];
        ll res[n+1];
        for(int i=1;i<=n;i++){
            cin>>a;
            arr[i]=a; orig[i]=a;
        }
        for(int i=1;i<=n;i++)res[i]=0;
        r=0;
        while(m--){
            cin>>a>>b;
            if(res[a]<r){
                arr[a]=orig[a];
                res[a]=r;
            }
            arr[a]=arr[a]+b;
            if(arr[a]>k){
                r++;
                arr[a]=orig[a];
                res[a]=r;
            }
        }
        for(int i=1;i<=n;i++){
            if(res[i]<r)arr[i]=orig[i];
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
    }