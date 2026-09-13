#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll a[n],b[n];
        for(int i=0;i<n;i++)cin>>a[i]>>b[i];
        ll hi=n,lo=0,mid;
        int j=0;
        while(hi-lo>1){
            mid=(hi+lo)/2;
            // cout<<mid<<endl;
            // cout<<"mid was "<<mid<<endl;
            cnt=0;
            for(int i=0;i<n;i++){
                if(mid<=cnt+1+a[i] and cnt<=b[i]){
                    // cout<<i<<" "<<a[i]<<" "<<b[i]<<" "<<cnt<<endl;
                    cnt++;
                }
                // else cout<<i<<" "<<a[i]<<" "<<b[i]<<" ni nai "<<cnt<<endl;
            }
            // cout<<endl;
            if(mid>cnt)hi=mid-1;
            else lo=mid;
            // j++;
            // cout<<mid<<endl;
            // if(j==3)break;
        }
        mid=hi;
        cnt=0;
        for(int i=0;i<n;i++){
            if(mid<=cnt+1+a[i] and cnt<=b[i])cnt++;
        }
        if(cnt>=hi)cout<<hi<<endl;
        else cout<<lo<<endl;
    }
    return 0;
    }