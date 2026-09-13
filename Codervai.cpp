#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,work; 
    // cin>>t;
    string s;
    // while (t--){
        cin>>n>>m;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        l = 1;
        r=1e18+11;
        while(r-l>1){
            ll mid = (r+l)/2;
            work = 0;
            for(int i=0;i<n;i++) work = work + mid/arr[i];
            if(work>=m) r=mid;
            else l = mid+1;
        }
        work=0;
        for(int i=0;i<n;i++) work = work + l/arr[i];
        if(work>=m)cout<<l<<endl;
        else cout<<r<<endl;
    // }
    return 0;
    }