#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e5+5;
bool vis[N]; 
ll p[N+1];
ll arr[N+1];
ll cnt=0;
void hoilo(int n){
    if(vis[n])return;
    cnt++;
    vis[n]=true;
    hoilo(p[n]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        fill(vis,vis+1+n,false);

        for(int i=1;i<=n;i++)cin>>p[i];
        for(int i=1;i<=n;i++)cin>>arr[i];
        cnt=0;
        for(int i=1;i<=n;i++){
            a=arr[i];
            hoilo(a);
            cout<<cnt<<" ";
        }
        cout<<endl;
    }
    return 0;
    }