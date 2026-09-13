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
        cin>>n>>k;
        ll ar[n];
        // vector<ll>v;
        cnt=0;
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        for(int j=0;k>=0 and j<63;j++){
            for(int i=0;i<n;i++){
                if( (((ar[i]>>j)&1LL)==1) ){
                    continue;
                }
                else if((k-(1LL<<(j)))>=0){
                    k=k-(1LL<<(j));
                    cnt++;
                    continue;

                }
                else {
                    break;
                }
            }
            if((k-(1LL<<(j)))<0) break;
        }
        for(int i=0;i<n;i++){

            for(int j=0; ar[i] >= (1LL<<(j)); j++){
                if((((ar[i]>>j)&1LL)==1)){
                    cnt++;
                }
                else continue;
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        cout<<cnt<<endl;
    }

    return 0;
    }