#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
// #define int long long
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m>>l;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll rem=n+1;
        vector<ll>v;
        for(int i=0;i<rem and i<m;i++){
            v.push_back(0);
        }
        r=0;
        for(int i=0;i<l;i++){
            sort(v.begin(),v.end());
            v[0]++;
            if(arr[r]==i+1){
                // cout<<"dhukse\n";
                sort(v.begin(),v.end());
                if((int)v.size()>n-r){
                    v.pop_back();
                }
                else v[v.size()-1]=0;
                r++;
            }
        }
        cout<<v[0]<<endl;
    }
    return 0;
    }