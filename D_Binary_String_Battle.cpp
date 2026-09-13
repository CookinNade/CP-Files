#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k>>s;
        int cnt1=0,cnt0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt1++;
            else cnt0++;
        }
        if(cnt1<=k)cout<<"Alice\n";
        else if(k>n/2)cout<<"Alice\n";
        else cout<<"Bob\n";
    }
    return 0;
    }