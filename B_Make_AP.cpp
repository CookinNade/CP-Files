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
        cin>>a>>b>>c;
        int yesser=0;
        
        
            if((a+c)%2==0){
                if(((a+c)/2)%b==0)yesser++;
            }
            if(c>b){
                if((2*b-c)%a==0 and (2*b-c)>0)yesser++;
            }
            if(b>c){
                if((2*b-c)%a==0)yesser++;
            }
            if(b==c){
                if(c%a==0)yesser++;
            }
            if(a==b){
                if(b%c==0)yesser++;
            }
            if(a>b){
                if((2*b-a)%c==0 and (2*b-a)>0)yesser++;
            }
            if(b>a){
                if((2*b-a)%c==0)yesser++;
            }
        if(yesser>0 or b-a==c-b)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }