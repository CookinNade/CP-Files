#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        ll m;
        cin>>n>>m;
        ll g[n][m];
        ll vang[n];
        for(int i = 0;i<n;i++)cin>>vang[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[i][j];
            }
            sort(g[i],g[i]+m,greater<int>());
        }
        ll puran[m];
        ll notun[m];
        for(int i=0;i<m;i++){
            puran[i] = g[n-1][i];
            notun[i] = puran[i];
        }
        ll mx = m;
        ll sum = 0;
        for(int i=0;i<m;i++){
            if(sum<vang[n-1])sum+=notun[i];
            else {
                mx = i;
                break;
            }
        }
        for(int i = n-2;i>=0;i--){
            k = 0; int r = 0;
            for(int j=0;j<m;j++){
                if(g[i][r] > puran[k]){
                    notun[j] = g[i][r];
                    r++;
                }
                else{
                    notun[j] = puran[k];
                    k++;
                }
            }
            sum = 0;
            for(ll j=0;j<m;j++){
                if(sum < vang[i]) sum += notun[j];
                else{
                    mx = min(mx , j);
                    break;
                }
            }
            for(int j = 0;j<m;j++)puran[j] = notun[j];
        }
        cout<<mx<<'\n';
    }
    return 0;
    }