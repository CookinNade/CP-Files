#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll n;
ll checker(vector<ll>&v1, vector<ll>&v2){
    ll ans=0;
    for(int i=1;i<=n;i++){
        int noer=0;
        for(int j=0;j<n;j++){
            ll k = (j+i)%n;
            if(v1[j]>=v2[k]){
                noer++;
                break;
            }
        }
        if(noer==0)ans++;
    }
    return ans;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,m,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        vector<ll>a;
        vector<ll>b;
        vector<ll>c;
        for(int i=0;i<n;i++){
            cin>>r;
            a.push_back(r);
        }
        for(int i=0;i<n;i++){
            cin>>r;
            b.push_back(r);
        }
        for(int i=0;i<n;i++){
            cin>>r;
            c.push_back(r);
        }
        // cout<<checker(b,c)<<endl;
        cout<<checker(a,b)*checker(b,c)*n<<endl;
    }
    return 0;
    }