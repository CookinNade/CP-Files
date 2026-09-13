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
        vector<ll>damage(n);
        d=0;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++){
            cin>>a;
            d=d+a;
            damage[i]=d;
        }
        sort(arr,arr+n);
        ll ans = LLONG_MIN;
        for(int i=0;i<n;i++){
            c=arr[i];
            
            a=n-i;
            auto it = lower_bound(damage.begin(),damage.end(),a);
            if((it)==damage.end()){
                ans=max(ans,n*c);
            }
            else if((it)==damage.begin()){
                if(damage[0]>(a)){
                    ans=max(ans,0ll);
                }
                else {
                    ans=max(ans,c);
                }
            }
            else{
                if((*it)>a){
                    --it;
                    ans=max(ans,(it-damage.begin()+1)*c);
                }
                else {
                    ans=max(ans,((it-damage.begin()+1)*c));
                }
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
    }