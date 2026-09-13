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
        m=n;
        ll ans[n+1];
        fill(ans+1,ans+n+1,12000);
        
        for(int i=0;i<n;i++){
            cin>>a;
            ans[a]=1;
        }
        // cout<<n<<endl;
        for(ll i=1;i<=n;i++){
            
            if(ans[i]==12000)ans[i]=-1;
            else{
                if(i==1)continue;
                for(ll j=2;j<i and j*i<=n;j++){
                    if(ans[j]!=-1){
                        ans[j*i]=min(ans[j*i],ans[j]+ans[i]);
                    }
                }
                a=i*i;
                cnt=2*ans[i];
                // cout<<a<<" "<<i<<endl;
                while(a<=n){
                    // cout<<a<<" "<<i<<endl;
                    ans[a]=min(ans[a],cnt);
                    cnt=cnt+ans[i];
                    a=a*i;
                    if(a>n)break;
                }
            }
        }
        // cout<<n<<endl;
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }cout<<endl;

    }
    return 0;
    }