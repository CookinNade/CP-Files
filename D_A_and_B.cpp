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
        ll acnt=0; ll bcnt=0;
        ll aleft[n]={0};ll bleft[n]={0}; ll aright[n]={0};ll bright[n]={0};
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                acnt++;
                if(i==0){
                    aleft[i]=0; 
                }
                else {
                    aleft[i]=aleft[i-1];
                }
            }
            else{
                if(i==0)continue;
                aleft[i]=aleft[i-1]+acnt;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                bcnt++;
                if(i==0){
                    bleft[i]=0; 
                }
                else {
                    bleft[i]=bleft[i-1];
                }
            }
            else{
                if(i==0)continue;
                bleft[i]=bleft[i-1]+bcnt;
            }
        }
        acnt=0; bcnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                acnt++;
                if(i==n-1){
                    aright[i]=0;
                }
                else{
                    aright[i]=aright[i+1];
                }
            }
            else{
                if(i==n-1)continue;
                else{
                    aright[i]=aright[i+1]+acnt;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='b'){
                bcnt++;
                if(i==n-1){
                    bright[i]=0;
                }
                else{
                    bright[i]=bright[i+1];
                }
            }
            else{
                if(i==n-1)continue;
                else{
                    bright[i]=bright[i+1]+bcnt;
                }
            }
        }
        ll aans=1e17+10;
        for(int i=0;i<n;i++){
            ll mn = min(aright[i]+aleft[i],bright[i]+bleft[i]);
            aans = min(aans,mn);
        }
        cout<<aans<<endl;
        // for(auto x:bright){
        //     cout<<x<<" ";
        // }
    }
    return 0;
    }