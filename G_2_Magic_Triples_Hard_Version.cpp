#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e6+1;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n];
        set<int>st;
        map<ll,ll>cnt;
        for(int i=0;i<n;i++){
            cin>>a;
            arr[i]=a;
            cnt[a]++;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            if(st.find(arr[i])!=st.end())continue;
            a=arr[i];
            if(a<=1e6){
                m=cnt[a];
                ans=ans + (m*(m-1)*(m-2));
                if(a!=1){
                    if(cnt.find(1)!=cnt.end() and cnt.find(a*a)!=cnt.end())
                    ans=ans+ cnt[1]*m*cnt[a*a];
                    // if(cnt[1]*m*cnt[a*a])cout<<a<<endl;
                }
                for(ll j = 2; j*j<=a;j++){
                    if(a%j==0){
                        if(cnt.find(a/j)!=cnt.end() and cnt.find(j*a)!=cnt.end())
                        ans=ans+ cnt[a/j]*m*cnt[a*j];
                        ll tmp=a/j;
                        if(tmp==j)continue;
                        swap(tmp,j);
                        if(cnt.find(a/j)!=cnt.end() and cnt.find(j*a)!=cnt.end())
                        ans=ans+ cnt[a/j]*m*cnt[a*j];
                        swap(tmp,j);
                    }
                }
            }
            else{
                m=cnt[a];
                ans=ans + (m*(m-1)*(m-2));
                for(ll j=2;j*a<=1e9;j++){
                    if(a%j==0){
                        if(cnt.find(a/j)!=cnt.end() and cnt.find(j*a)!=cnt.end())
                        ans=ans+ cnt[a/j]*m*cnt[a*j];
                        ll tmp=a/j;
                        swap(tmp,j);
                        if(cnt.find(a/j)!=cnt.end() and cnt.find(j*a)!=cnt.end())
                        ans=ans+ cnt[a/j]*m*cnt[a*j];
                        swap(tmp,j);
                    }
                }
            }
            st.insert(a);
        }
        cout<<ans<<endl;
    }
    return 0;
    }