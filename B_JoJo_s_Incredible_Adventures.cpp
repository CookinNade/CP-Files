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
        cin>>s;
        n=s.size();
        int cntf=0;int cntl=0;
        for(int i=0;i<n;i++){
            if (s[i]=='1')cntf++;
            else break;
        }
        for(int i=n-1;i>=0;i--){
            if (s[i]=='1')cntl++;
            else break;
        }
        int fstreak=cntf+cntl;
        int streak=-1;
        cnt=0;
        streak=max(streak,fstreak);
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt++;
            else {
                streak=max(cnt,streak);
                cnt=0;
            }
        }
        streak=max(cnt,streak);
        ll aa=1ll*((streak+1)/2);
        ll bb=1ll*((streak+1)/2);
        if(streak%2==0){
            bb++;
        }
        if(streak==2*n){
            cout<<1ll*n*n<<endl;
        }
        else if(streak==0){
            cout<<0<<endl;
        }
        else if(streak==1){
            cout<<1<<endl;
        }
        else cout<<aa*bb<<endl;
    }
    return 0;
    }