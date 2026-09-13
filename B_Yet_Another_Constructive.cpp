#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        ll m;
        cin>>n>>k>>m;
        if(k > m)cout<<"NO\n";
        else{
            cout<<"YES\n";
            vector<int>v;
            for(int i=0;i<k-1;i++){
                v.push_back(1);
            }
            ll sum = k-1;
            v.push_back(m-sum);
            int tim = n / k;
            for(int i=0;i<tim;i++) {
                for(auto x:v)cout<<x<<" ";
            }
            int rem = n%k;
            for(int i=0;i<rem;i++)cout<<v[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
    }