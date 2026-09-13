#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll arr[n+1];
        for(int i=1;i<=n;i++)cin>>arr[i];
        ll f[n+1];
        for(int i=1;i<=n;i++)f[i]=arr[i];
        sort(f+1,f+n+1,greater<int>());
        ll l = f[2];
        // cout<<l<<endl;
        for(int i=1;i<=n;i++){
            if(l == arr[i]){
                k=i; break;
            }
        }
        // cout<<k<<endl;
        for(int i=1;i<=n;i++){
            cnt=arr[i];
            int j = i + 2;
            if(j>n) j = j - n;
            ll ans=arr[i];

            // cout<<j<<" "<<ans<<endl;
            if(i!=k) ans = ans + arr[k];
            // cout<<j<<" "<<ans<<endl;
            while (j!=k){
                if(j==i or j==k)break;
                int a = j;
                int b = j-1;
                if(b==0)b=n;
                ll temp = cnt;
                cnt = max(cnt,max(arr[a],arr[b]));
                if(cnt > f[2] and arr[b] != f[1]) cnt = temp;
                if(arr[b] == f[1]) cnt = f[2];
                ans = ans + cnt;
                // cout<<j<<" "<<cnt<<" "<<ans<<endl;
                j++;
                if(j>n)j=1;
            }
            // cout<<ans<<endl;
            j = i - 1;
            if(j<=0) j = n + j;
            // cout<<j<<endl;
            ans += arr[j];
            j = j - 1;
            if(j<=0) j = n + j;
            // cout<<j<<endl;
            while(j!=k){
                if(j==i or j==k)break;
                int a = j;
                int b = j-1;
                if(b==0)b=n;
                ll temp = cnt;
                cnt = max(cnt,max(arr[a],arr[b]));
                if(cnt > f[2] and arr[b] != f[1]) cnt = temp;
                if(arr[b] == f[1]) cnt = f[2];
                ans = ans + cnt;
                j--;
                if(j==k)break;
                if(j<=0)j=n;
                // cout<<j<<" "<<endl;
            }
            cout<<ans<<" ";
        }
        cout<<'\n';
    }
    return 0;
    }