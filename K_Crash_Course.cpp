#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,w; 
    cin>>t;
    string s;
    while (t--){
        cin>>l>>w>>x;
        ll cw,cl,tw,tl;
        cin>>cl>>cw>>tl>>tw;
        ll ans=0 , noer=0;
        if((abs(cw-tw))%x==0){
            //crista ronaldo
        }
        else if((tw)%x==0 or (w-tw)%x==0){
            ans++;
        }
        else{
            // cout<<"hello\n";
            noer++;
        }
        if(abs(cl-tl)%x==0){
            //crista ronaldo
        }
        else if((tl)%x==0 or (l-tl)%x==0){
            ans++;
        }
        else{
            // cout<<"hello\n";
            noer++;
        }
        cout<<(noer? -1 : ans)<<endl;


    }
    return 0;
    }