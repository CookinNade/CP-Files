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
        ll orig[n];
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            orig[i]=arr[i];
        }
        ll ans=LLONG_MAX;
        bool fr = is_sorted(arr,arr+n);
        if(fr)cout<<-1<<endl;
        else{
            sort(orig,orig+n);
            ll mx=orig[n-1];
            ll mn=orig[0];
            for(int i=0;i<n;i++){
                if(arr[i]==orig[i])continue;
                else{
                    a=arr[i];
                    d = max(abs(mx-a),abs(mn-a));
                    ans=min(ans,d);
                }
            }
            cout<<ans<<endl;
        }
        
    }

    return 0;
    }