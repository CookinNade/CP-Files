#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,d,cnt,r,l,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        m=2;
        ll k[n];
        fill(k,k+n,0);
        l=-1;
        ll ans[n];
        fill(ans,ans+n,0);
        for(int i=0;i<n;i++){
            m=2;
            if(arr[i]==1){
                l=i;
                if(i==n-1)ans[i]=1;
                for(int j=i+1;j<n;j++){
                    if(arr[j]==1){
                        k[l]=j;
                        m=2;
                        l=j;
                    }
                    else if(arr[j]>m){
                        ans[l]=j-l;
                        m=2;
                        j=i;
                        break;
                    }
                    else if(m==arr[j]){
                        m++;
                        // cout<<"dhukse\n";
                    }
                    else if(m<arr[j])continue;
                    if(j==n-1){
                        ans[l]=j-l+1;i=j;
                    }
                }
            }
        }
        // for(auto c:k)cout<<c<<" ";
        // cout<<endl;
        for(int i=n-1;i>=0;i--){
            if(k[i]){
                ans[i]=ans[k[i]]+k[i]-i;
            }
        }
        // for(auto c:ans)cout<<c<<" ";
        // cout<<endl;
        cout<<accumulate(ans,ans+n,0ll)<<endl;
    }
    return 0;
    }