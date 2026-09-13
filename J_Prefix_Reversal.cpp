#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll sum = 0;
        vector<pair<ll,int>>v;
        ll add[n];
        for(int i=n-1;i>=0;i--){
            if(i==n-1) add[i] = (i+1) * arr[i];
            else add[i] = add[i+1] + (i+1) * arr[i];
        }
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(i==0){
                v.push_back({arr[i] + add[i + 1],0});
                continue;
            }
            if(i == n-1){
                ll b = v[v.size()-1].first - add[i];
                v.push_back({b+sum , i});
                break;
            }
            else{
                ll b = v[v.size()-1].first - add[i];
                v.push_back({b+sum+add[i + 1] , i});
            }
        }
        sort(v.begin(),v.end());
        for(auto x:v)cout<<x.second + 1<<" ";
        cout<<'\n';
    }
    return 0;
    }