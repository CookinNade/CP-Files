#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
vector<ll>v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
       cin>>n;
       ll arr[n];
       for(int i=0;i<n;i++)cin>>arr[i];
       int ans[n];
       fill(ans,ans+n,0);
       cnt=0;
       for(int i=0;i<n;i++){
            if(arr[i]==0){
                cnt=0;
                ans[i]=0;
            }
            else if(arr[i]==-1){
                cnt=-cnt;
                ans[i]=cnt;
            }
            else if(arr[i]==-2){
                if(cnt<0){
                    cnt=-cnt;
                    cnt++;
                }
                else{
                    cnt=-cnt;
                    cnt--;
                }
                ans[i]=cnt;
            }
            else if(arr[i]==2){
                // cnt++;
                if(cnt<0)cnt--;
                else cnt++;
                ans[i]=cnt;
            }
            else ans[i]=cnt;
       }
       int ind=-1;
       int l=0,r=0;
       cnt=0;
       for(int i=0;i<n;i++){
            if(cnt<ans[i]){
                cnt=ans[i];
                ind=i;
            }
       }
    //    cout<<ind<<endl;
       for(int i=ind;i>=0;i--){
            if(ans[i]==1 or ans[i]==-1){
                l=i;
                break;
            }
       }
       for(auto o:ans)cout<<o<<" ";
       cout<<endl;
       cout<<l<<" "<<n-ind-1<<endl;
    }
    return 0;
    }