#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    // cin>>t;
    t = 1;
    while (t--){
        cin>>n;
        ll sum = 0;
        for(int i=1;i<=n;i++){
            cin>>k;
            if(i > n/2){
                sum+=k;
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
    }