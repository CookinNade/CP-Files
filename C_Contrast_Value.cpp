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
        pair<ll,ll> arr[n];
        ll contr=0;
        for(int i=0;i<n;i++){
            cin>>arr[i].first;
            arr[i].second=1;
            if(i==0)continue;
            else contr=contr+ abs(arr[i].first-arr[i-1].first);
        }
        m=1;l=0;r=2; cnt=0;
        
        for(int i=0;i<n-2;i++){
            if(abs(arr[m].first-arr[l].first)+abs(arr[m].first-arr[r].first)==abs(arr[l].first-arr[r].first)){
                cnt++;
                m++; r++;
                arr[m].second=0;
            }
            else{
                m++;r++;l=m-1;
                // if(arr[l].second==0){
                //     for(int j=l;j<m;j++){
                //         if(arr[j].second==1){
                //             l=j;break;
                //         }
                //     }
                // }
            }
        }
        if(contr==0)cout<<1<<endl;
        else{
            cout<<n-cnt<<endl;
        }
        
    }
    return 0;
    }