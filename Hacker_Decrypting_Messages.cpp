#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n>>m;
    string s;
    const ll N= 1e6+2;
    ll siv[N+1];
    fill(siv,siv+N,0);
    for(int i=2;i<=1e5;i++){
        if(siv[i])continue;
        for(int j=2*i;j<=N;j=j+i){
            siv[j]++;
        }
    }
    set<ll>st;
    for(int i=0;i<n;i++){
        cin>>a;
        if(st.find(a)!=st.end())continue;
        for(int j=a*2;j<=N;j=j+a){

        }
    }

    return 0;
    }