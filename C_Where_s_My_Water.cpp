#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        ll h;
        cin>>n>>h;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll ne[n];
        fill(ne,ne+n,0ll);
        vector<pair<int,int>>v;
        l=0;
        for(int i=0;i<n;i++){
            if(i==n-1){
                v.push_back({l,i});
                break;
            }
            if(arr[l]==h){
                if(l==i)continue;
                v.push_back({l,i-1});
                l=i+1;
            }
        }
        for(int i=0;i<v.size();i++){
            l=v[i].first;r=v[i].second;
            ll f=l;
            for(;l<=r;l++){
                ll ch=arr[l];
                for(int k=f;k<=r;k++){
                    
                    else ne
                }
            }
        }
    }
    return 0;
    }