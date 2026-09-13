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
        map<ll,ll>mp;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cnt=1;
        c=arr[0];
        mp[arr[0]]++;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1] and arr[i]-arr[i-1]>1){
                mp.clear();
                c=arr[i];
                mp[arr[i]]++;
                cnt++;
                // cout<<c<<endl;
            }
            else if(arr[i]<=arr[i-1]){
                if(mp.find(arr[i])!=mp.end() and c<arr[i])continue;
                else{
                    mp.clear();
                    c=arr[i];
                    mp[arr[i]]++;
                    cnt++;
                    // cout<<c<<" "<<i<<endl;
                }
            }
            else{
                mp[arr[i]]++;
            }
        }
        cout<<cnt<<endl;
        mp.clear();
    }

    return 0;
    }