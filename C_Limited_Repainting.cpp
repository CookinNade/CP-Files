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
        cin>>n>>k>>s;
        r=0; ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        
       
        ll hi = 1e15; ll lo=0,mid;
        while(hi-lo>1){
            mid = (hi+lo)/2;
            // cout<<"this mid "<<mid<<endl;
            cnt=0;
            r=1;b=0;
            for(int i=0;i<n;i++){
                if(s[i]=='B' and arr[i]>mid and r){
                    // cout<<mid<<" "<<i<<" "<<1<<endl;
                    r=0;
                    b=1;
                    cnt++;
                }
                if(s[i]=='R' and arr[i]>mid and b){
                    // cout<<"broken"<<endl;
                    r=1;b=0;
                }
            }
            if(cnt>k)lo=mid+1;
            else hi = mid;
        }
        cnt=0;
        mid=lo;
        r=1;b=0;
        for(int i=0;i<n;i++){
            if(s[i]=='B' and arr[i]>mid and r){
                r=0;
                b=1;
                cnt++;
            }
            if(s[i]=='R' and arr[i]>mid and b){
                r=1;b=0;
            }
        }
        // cout<<hi<<" "<<lo<<endl;
        if(cnt>k)cout<<hi<<endl;
        else cout<<lo<<endl;
    }
    return 0;
    }