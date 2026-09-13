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
        cin>>n;
        int arr[n+1]; int pref[n+1];
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int sum=0;
        for(int i=n;i>=1;i--){
            sum=arr[i]+sum;
            pref[i]=sum;
        }
        // for(int i=1;i<=n;i++){
        //     cout<<pref[i]<<" ";
        // }cout<<endl;
        int hi=n; int lo=1; int mid;
        while(hi-lo>1){
            mid = (hi+lo)/2;
            cout<<"? "<<n-mid+1<<" ";
            for(int i=mid;i<=n;i++){
                cout<<i<<" ";
            }cout<<endl;
            cout.flush();
            cin>>x;
            if(x>pref[mid]){
                lo=mid;
            }
            else{
                hi=mid-1;
            }
        }
        cout<<"? "<<n-hi+1<<" ";
        for(int i=hi;i<=n;i++){
            cout<<i<<" ";
        }cout<<endl;
        cout.flush();
        cin>>x;
        if(x>pref[hi])cout<<"! "<<hi<<endl;
        else cout<<"! "<<lo<<endl;
        cout.flush();
        
    }
    return 0;
    }