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
        ll arr[2*n];
        for(int i=0;i<2*n;i++){
            cin>>arr[i];
        }
        vector<ll>v;
        vector<ll>smol;
        sort(arr,arr+2*n,greater<int>());
        ll sum=0;
        for(int i=0;i<n+1;i++) {
            v.push_back(arr[i]);
            sum=sum+arr[i];
        }
        ll sum2=0;
        for(int i=2*n-1;i>=n+1;i--){
            smol.push_back(arr[i]);
            sum2=sum2+arr[i];
        }
        x= sum-sum2;
        // cout<<x<<endl;
        l=0;r=0;
        for(int i=0;i<2*n+1;i++){
            if(i%2){
                if(l==n-1)cout<<x<<" ";
                else {
                    cout<<smol[l]<<" ";
                    l++;
                }
            }
            else{
                cout<<v[r]<<" ";
                r++;
            }
        }
        cout<<endl;
        // for(auto x:v)cout<<x<<" ";
        // cout<<endl;
        // for(auto x:smol)cout<<x<<" ";
        // cout<<endl;
    }
    return 0;
    }