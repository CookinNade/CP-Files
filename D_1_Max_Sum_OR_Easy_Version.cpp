#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>l>>r;
        ll bit=0;
        for(int i=0;i<=30;i++)if(r&(1ll<<i))bit=i;
        // cout<<bit<<" ";
        bit++;
        ll num = (1ll<<bit); num--;
        ll ans[r+1];
        bool hoise[r+1];
        for(int i=0;i<=r;i++)hoise[i]=false;
        fill(ans,ans+r+1,-1);
        for(int i=r;i>=0;i--){
            int last=0;
            if(hoise[i])continue;
            else{
                for(int j=0;j<=30;j++)if(i&(1ll<<j))last=j;
                ll add=0;
                for(int j=0;j<last;j++){
                    if(i&(1ll<<j))continue;
                    else add=add+(1ll<<j);
                }
                ans[i]=add;
                ans[add]=i;
                hoise[i]=true;
                hoise[add]=true;
            }
        }
        ll sum=0;
        for(int i=0;i<=r;i++){
            sum=sum + (i|ans[i]);
        }
        cout<<sum<<endl;
        for(int i=0;i<=r;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
    }