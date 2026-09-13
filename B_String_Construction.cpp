#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n>>k;
        int f1 = k / 2;
        if(k%2)f1++;
        f1++;
        int f2 = k / 2;
        f2++;
        if(f1 + f2 > n){
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<f2;i++)cout<<0;
        for(int i=0;i<f1;i++)cout<<1;
        for(int i=0;i<n-f1-f2;i++){
            if(i%2)cout<<1;
            else cout<<0;
        }
        cout<<'\n';

    }
    return 0;
    }