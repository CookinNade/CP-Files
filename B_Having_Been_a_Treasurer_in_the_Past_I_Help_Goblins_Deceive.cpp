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
        cin>>n>>s;
        ll ucnt=0,bcnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='-')ucnt++;
            else bcnt++;
        }
        ll mul = ucnt/2;
        if(ucnt%2)mul=mul*(mul+1);
        else mul=mul*mul;
        cout<<mul*bcnt<<endl;
        
    }
    return 0;
    }