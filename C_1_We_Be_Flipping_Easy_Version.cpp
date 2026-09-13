#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n+1];
        vector<int>v;
        for(int i=1;i<=n;i++)cin>>arr[i];
        for(int i=1;i<=n;i++){
            pair<int,int>p;
            p.first=1e7;
            if(arr[i]>0){
                if(i!=1)p.first=i-1;
                if(i==n){
                    
                    p.second=i;
                    v.push_back(i); 
                    v.push_back(i-1);
                    break;
                }
                for(int j=i+1;j<=n;j++){
                    if(arr[j]<0) {
                        p.second=j-1;
                        i=j; break;
                    }
                    else if(arr[j]>0 and j==n){
                        p.second=j;
                        i=j+5; break;
                    }
                }
                v.push_back(p.second);
                if(p.first<=n)v.push_back(p.first);
            }
        }
        cout<<v.size()<<'\n';
        for(auto x:v)cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
    }