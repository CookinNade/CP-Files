#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n; int a[n]; int b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        int ans =1;
        for(int i=0;i<n;i++){
            if(a[i]>b[i]){
                ans = ans+a[i]-b[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }