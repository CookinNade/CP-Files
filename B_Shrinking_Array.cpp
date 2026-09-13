#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int ans=-1;
        auto asc =is_sorted(a,a+n);
        auto desc=is_sorted(a,a+n,greater<int>());
        for(int i=0;i<n-1;i++){
           if(a[i]+1==a[i+1] or a[i]-1==a[i+1] or a[i]==a[i+1]){
            ans=0;
            break;
           }
        }
        if(ans==0){
            cout<<ans<<endl;
        }
        else if(asc or desc){
            cout<<-1<<endl;
        }
        else cout<<1<<endl;
        
    }
    return 0;
    }