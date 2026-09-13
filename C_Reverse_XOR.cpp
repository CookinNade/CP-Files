#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        x=__builtin_popcount(n);
        if(x==1 or (((1<<x)-1)==n and x%2)){
            cout<<"NO\n";
            continue;
        }
        s="";
        a=0;
        for(int i=0;i<n;i++){
            if(a>=x)break;
            if(n&(1ll<<i)){
                a++;
                s.push_back('1');
            }
            else{
                s.push_back('0');
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')s.push_back('0');
            else break;
        }
        string d=s;
        reverse(s.begin(),s.end());
        // cout<<s<<endl<<d<<endl;
        if(s==d){
            ll sz=s.size();
            if(sz%2 and s[sz/2]=='1'){
                cout<<"NO\n";
            }
            else cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
    }