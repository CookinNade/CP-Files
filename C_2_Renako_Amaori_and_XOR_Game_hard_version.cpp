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
         cin>>n;
        ll a[n];
        ll b[n];
        ll acnt=0; ll bcnt=0; cnt=0;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int j=29;j>=0;j--){
            acnt=0;bcnt=0;cnt=0;
            for(int i=0;i<n;i++){
                if(i%2==0 and ((a[i]>>j)&1)!=((b[i]>>j)&1)){
                    acnt=1;bcnt=0; cnt++;
                }
                else if(i%2==1 and ((a[i]>>j)&1)!=((b[i]>>j)&1)){
                    cnt++;bcnt=1;acnt=0;
                }
            }
            // cout<<j<<endl;
            if(cnt%2==0)continue;
            else break;
        }
        if(cnt%2==0){
            cout<<"Tie\n";
        }
        else if(acnt)cout<<"Ajisai\n";
        else cout<<"Mai\n";
    }
    return 0;
    }