#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll sum = n*(n+1) / 2;
    if(sum%2){
        cout<<"NO";
        return 0;
    }
    vector<int>n1;
    vector<int>n2;
    ll rem = sum / 2;
    for(int i=n;i>=1;i--){
        if(rem >= i){
            n1.push_back(i);
            rem -= i;
        }
        else n2.push_back(i);
    }
    cout<<"YES\n";
    cout<<(int)n1.size()<<'\n';
    for(auto x:n1)cout<<x<<" ";
    cout<<'\n';
    cout<<(int)n2.size()<<'\n';
    for(auto x:n2)cout<<x<<" ";
    return 0;
    }