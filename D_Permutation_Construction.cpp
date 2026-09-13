#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n];
        map<ll,vector<ll>>mp;
        map<ll,ll>ind;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]].push_back(i+1);
            ind[arr[i]]=0;
        }
        sort(arr,arr+n,greater<int>());
        vector<ll>ans;
        for(int i=0;i<n;i++){
            a=arr[i];
            ans.push_back(mp[a][ind[a]]);
            ind[a]++;
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
    }