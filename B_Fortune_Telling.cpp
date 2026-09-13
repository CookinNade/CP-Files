#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>a>>k;
        cnt=0;
        for(int i=0;i<n;i++){
            cin>>b;
            if(b%2)cnt++;
        }
        if(cnt%2){
            if(k%2 != a%2)cout<<"Alice\n";
            else cout<<"Bob\n";
        }
        else{
            if(k%2 == a%2)cout<<"Alice\n";
            else cout<<"Bob\n";
        }
    }
    return 0;
    }