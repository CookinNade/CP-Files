#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>n;
    ll ans1 =0;
    ll ans10 =0;
    ll ans100 =0;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        a = a%1000;
        if(a==0)continue;
        a = 1000-a;
        ans100 = ans100 + a/100;
        a %= 100;
        ans10 = ans10 + a/10;
        a %= 10;
        ans1 = ans1 + a/1;
    }
    cout<<ans1<<" "<<ans10<<" "<<ans100<<'\n';
    return 0;
    }