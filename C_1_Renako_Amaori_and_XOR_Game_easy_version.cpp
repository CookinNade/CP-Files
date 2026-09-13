#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll a[n];
        ll b[n];
        ll acnt=0; ll bcnt=0; cnt=0;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++){
            if(a[i]!=b[i])cnt++;
        }
        for(int i=0;i<n;i++){
            if(i%2==0 and a[i]!=b[i]){
                acnt=1;bcnt=0;
            }
            else if(i%2==1 and a[i]!=b[i]){
                bcnt=1;acnt=0;
            }
        }
        if(cnt%2==0){
            cout<<"Tie\n";
        }
        else if(acnt)cout<<"Ajisai\n";
        else cout<<"Mai\n";
        
    }
    return 0;
    }