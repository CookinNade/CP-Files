#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 3e6;
bool siv[N];
int dp[170];
int a,b;
int f(int c){
    if(a + c == b)return 0;
    if(dp[c]!=-1)return dp[c];
    int ans = 200;
    for(int i=1;i+c+a<=b;i++){
        if(gcd(a+c,i) == 1) ans = min(ans, 1+f(c+i));
    }
    // cout<<"dhukse "<<a+c<<" "<<c<<endl;
    return dp[c] = ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    vector<int>prime;
    prime.push_back(1);
    siv[1] = true;
    for(int i=2;i<3e6;i++){
        if(!siv[i]){
            // cout<<i<<" ";
            prime.push_back(i);
            for(int j=2*i;j<3e6;j+=i) siv[j] = true;
        }
    } 
    while (t--){
        int n;
        cin>>a>>b;
        if(a==b){
            cout<<"0\n";
            continue;
        }
        if(gcd(abs(b-a),a) == 1){
            cout<<"1\n";
            cout<<b-a<<'\n';
            continue;
        }
        auto it = upper_bound(prime.begin(),prime.end(),a);
        while((*it) <= b and b% (*it) == 0){
            ++it;
        }
        // cout<<gcd(2184,13)<<'\n';
        if((*it)<b and b%(*it)){
            cout<<2<<"\n";
            cout<<abs((*it) - a)<<" "<<abs(b-(*it))<<'\n';
            continue;
        }
        memset(dp,-1,sizeof dp);
        int yes = f(0);
        cout<<yes<<'\n';
        int c = 0;
        while(yes>0){
            for(int i=1;i+a+c<=b;i++){
                if(gcd(a+c,i) == 1 and yes - 1 == f(c+i)){
                    cout<<i<<" ";
                    c += i;
                    yes--;
                }
            }
        }   
        cout<<'\n'; 
    }
    return 0;
    }