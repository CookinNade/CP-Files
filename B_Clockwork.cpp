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
        for(int i=0;i<n;i++)cin>>arr[i];
        int noer=0;
        // cout<<n<<endl;
        for(ll i=0;i<n;i++){
            ll big = max(i,n-1-i);
            // cout<<"this is big "<<big<<" for i #"<<i<<endl;
            if(arr[i]>2*big)continue;
            else{
                noer++;
                break;
            }
        }
        if(noer)cout<<"NO"<<endl;
        else cout<<"YES\n";
    }
    return 0;
    }