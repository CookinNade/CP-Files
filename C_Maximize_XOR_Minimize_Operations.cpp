#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        ll x,y;
        cin>>x>>y;
        ll z = x+y;
        cout<<z<<" ";
        ll arr[30];
        for(int i=0;i<=30;i++){
            if(z & (1ll<<i)) arr[i] = 1;
            else arr[i] = 0;
        }
        ll py = y;
        ll lz = 30;
        for(int i=30;i>=0;i--){
            if(y & (1ll<<i) and arr[i] == 0){
                y = y + (1ll<<lz);
                for(k = lz-1;k>=0;k--){
                    if(y & (1ll<<k)) y = y - (1ll<<k);
                }
                break;
            }
            if(!(y & (1ll<<i)) and arr[i]) lz = i;
        }
        ll cnt = y - py;
        cout<<cnt<<'\n';

    }
    return 0;
    }