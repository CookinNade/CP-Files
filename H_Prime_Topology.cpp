#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 104206969ll;
const ll N = 1e7;
bool isnotprime[N+1];
ll pn[N+1];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    vector<ll>v;
    ll last;
    for(ll i = 2; i*i<=N; i++){
        last = i;
        if(isnotprime[i])continue;
        else{
            v.push_back(i);
            for(ll j = 2*i; j<=N; j = j + i){
                isnotprime[j] = true;
            }
        }
    }
    for(ll i = last + 1; i <= N; i++){
        if(!isnotprime[i]) v.push_back(i);
    }
    vector<ll>sum;
    vector<ll>tprime;
    vector<ll>tsum;
    for(ll i = 2; i+2 <= N; i++){
        if(!isnotprime[i] and !isnotprime[i+2]){
            // if(i<100)cout<<i<<" ";
            
            tprime.push_back(i);
        }
    }
    ll val = 0;
    tsum.push_back(0);
    for(int i=0;i<tprime.size();i++){
        val = (val + tprime[i]) % M;
        tsum.push_back(val);
    }
    sum.push_back(0);
    val = 0;
    for(int i=0;i<v.size();i++){
        val = (val + v[i]) % M;
        sum.push_back(val);
    }
    cin>>t;
    while (t--){
        cin>>n>>k;
        if(k>=5)cout<<0<<endl;
        else if(k==4){
            if(n - 7 > 0)cout<<n - 7<<endl;
            else cout<<0<<endl;
        }
        else if(k==3){
            auto it = lower_bound(tprime.begin(),tprime.end(),n-2);
            if(it != tprime.begin()){
                ll p = it - tprime.begin();
                ll f = ((n-2) * p) % M;
                f = (f - tsum[p] + M ) % M;
                cout<<max(0ll, (f * 2ll) % M)<<endl;
            }   
            else cout<<0<<endl;
        }
        else if(k==2){
            auto it = lower_bound(v.begin(),v.end(),n);
            if(it != v.begin()){
                ll p = it - v.begin();
                ll f = (n * p) % M;
                f = (f - sum[p] + M ) % M;
                cout<<max(0ll,f)<<endl;
            }   
            else cout<<0<<endl;
        }
        else cout<<n<<endl;
        
    }
    return 0;
    }