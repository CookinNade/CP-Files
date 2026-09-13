#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        if(n==10)cout<<-1<<'\n';
        else if(n%12==10)cout<<22<<" "<<n-22<<'\n';
        else{
            for(int i=0;i<12;i++){
                if(i==10)continue;
                else if((n-i)%12==0){
                    cout<<i<<" "<<n-i<<'\n';
                    break;
                }
            }
        }
    }
    return 0;
    }