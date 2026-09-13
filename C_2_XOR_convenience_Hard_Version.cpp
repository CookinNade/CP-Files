#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll sum = (n*(n+1))/2;
        ll arr[n];
        if(__builtin_popcount(n)==1){
            cout<<-1<<endl;
        }
        else{
            if(n%2){
                ll sum = (n*(n+1))/2;
                ll arr[n];
                // cout<<sum<<endl;
                arr[n-1]=1;
                for(int i=2;i<=n-1;i++){
                    arr[i-1]=i ^ 1;
                    sum=sum-arr[i-1];
                }
                arr[0]=sum-1;
                for(ll i=0;i<n;i++)cout<<arr[i]<<" ";
                cout<<endl;
            }
            else{
                a=1;
                int bits=0;
                while(a<n){
                    a=a*2;
                    bits++;
                }
                ll r= n - a/2;
                cout<<(r^1)<<" ";
                for(ll i=2;i<=n-1;i++){
                    if(i==r){
                        cout<<n<<" ";
                        continue;
                    }
                    d= i ^ 1;
                    cout<< d <<" ";
                }
                cout<<1<<endl;
            }
        }
    }
    return 0;
    }