#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n];
        ll suff[n];
        ll pref[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll mn=1e9+10;;
        for(int i=0;i<n;i++){
            mn=min(mn,arr[i]);
            pref[i]=mn;
        }
        mn=-1;
        for(int i=n-1;i>=0;i--){
            mn=max(mn,arr[i]);
            suff[i]=mn;
        }
        int no=0;
        for(int i=0;i<n-1;i++){
            if(pref[i]>suff[i+1])no++;
        }
        if(no)cout<<"No\n";
        else {
            cout<<"Yes\n";
            ll a[n+1];
            fill(a+1,a+1+n,0ll);
            ll mx=n; l=0; int f=0; mn =1e10;
            for(int i=0;i<n;i++){
                if(arr[i]==mx){
                    // cout<<"start of mx as "<<mx<<endl;
                    if(f){
                        cout<<mx<<" "<<mn<<endl;
                    }
                    a[mx]=1;
                    for(;l<i;l++){
                        mn=min(arr[l],mn);
                        cout<<mx<<" "<<arr[l]<<endl;;
                        a[arr[l]]=1;
                    }
                    
                    // cout<<"end of mx as "<<mx<<endl;
                    for(;;mx--){
                        if(mx==0)break;
                        if(a[mx]==0){
                            break;
                        }
                    }
                    f++;l++;
                }
                
            }
        }
    }
    return 0;
    }