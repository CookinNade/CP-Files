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
        cin>>a>>b>>c;
        ll arr[31];
        fill(arr,arr+31,0ll);
        for(int i=0;i<=30;i++){
            if((a>>i)&1)arr[i]++;
            if((b>>i)&1)arr[i]++;
            if((c>>i)&1)arr[i]++;
        }
        int noer=0;
        for(int i=0;i<=30;i++){
            if(arr[i]==2 or arr[i]>3){
                noer++;
                break;
            }
        }
        if(noer)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
    }