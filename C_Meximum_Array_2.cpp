#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,q; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k>>q;
        ll v1[n+1];
        ll v2[n+1];
        ll arr[n+1];
        fill(v1,v1+n+1,0ll);
        fill(v2,v2+n+1,0ll);
        fill(arr,arr+1+n,-1);
        for(int i=0;i<q;i++){
            cin>>a>>l>>r;
            if(a==1) for(int i=l;i<=r;i++)v1[i]++;
            if(a==2) for(int i=l;i<=r;i++)v2[i]++;    
            
        }
       
        for(int i=1;i<=n;i++){
            if(v2[i]==0)arr[i]=k;
            if(v2[i] and v1[i])arr[i]=k+1;
            // cout<<arr[i]<<" ";
        }
        // cout<<endl;
        cnt=0;
        for(int i=1;i<=n;i++){
            if(arr[i]==-1){
                arr[i]=cnt;
                cnt++;
                if(k==cnt)cnt=0;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
    }