#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=205;

int dp[N][200*50+5];
bool match(ll n, ll sum, vector<int> &price){
    // cout<<n<<" "<<sum<<endl;
    if(sum==0)return true;
    if(n<0)return false;
    if(dp[n][sum]!=-1)return dp[n][sum];
    bool ans=false;
    ans = match(n-1,sum,price);
    ans |= match(n-1,sum-price[n],price);
    return dp[n][sum] =ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,k,x; 
    cin>>n;
    vector<int>price;
    memset(dp,-1,sizeof(dp));
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a;
        sum=sum+a;
        price.push_back(a);
    }
    // cout<<sum<<endl;
    if(sum%2)cout<<"NO\n";
    else {
        if(match(n-1,sum/2,price)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }