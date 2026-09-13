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
        int arr[n+1];
        for(int i=1;i<=n;i++)cin>>arr[i];
        vector<pair<int,int>>v;
        for(int i=1;i<=n;i++){
            v.push_back({i*(arr[i]+1)-1,i*(arr[i])});
        }
        sort(v.rbegin(),v.rend());
        bool ase[n];
        fill(ase,ase+n,true);
        for(int i=0;i<(int)v.size();i++){
            if(i==0)for(int j=v[i].first;j>=v[i].second;j--)ase[j] = false;
            else{
                for(int j = min(v[i-1].second, v[i].first); j>=v[i].second ; j--){
                    ase[j] = false;
                }
            }
        }
        cnt = 0;
        for(int i=0;i<n;i++)if(ase[i])cnt++;
        cout<<cnt<<'\n';
        for(int i=0;i<n;i++)if(ase[i])cout<<i<<" ";
        cout<<'\n';
        
    }
    return 0;
    }