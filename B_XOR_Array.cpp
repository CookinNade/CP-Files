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
    vector<ll>ans;
    c=1;
    // for(int i=0;i<4e5+2;i++,c++) ans.push_back(c ^ (c-1));
    // for(int i=0;i<20;i++)cout<<ans[i]<<" ";
    cout<<endl;
    while (t--){
        cin>>n>>l>>r;
        ll arr[n+1];
        c=0;
        for(int i=0;i<=n;i++){
            if(i==r)arr[r]=arr[l-1];
            else arr[i]=i;    
        }
        
        for(int i=1;i<=n;i++){
            cout<<(arr[i]^arr[i-1])<<" ";
        }
        cout<<endl;
    }
    return 0;
    }