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
        cin>>l>>r;
        int mn = min(l,r);
        int mx= max(l,r);
        if(mx-mn>99){
            n = mn%100;
            // cout<<n<<endl;
            if(n<=90){
                cout<<mn-n+90<<endl;
            }
            else{
                cout<<mn+100-abs(90-n)<<endl;
            }
            
        }
        else{
            int num=-1; int diff=-1;
            for(;l<=r;l++){
                s = to_string(l);
                mx= -1; mn=1e9;
                for(int i=0;i<s.length();i++){
                    int dig = s[i]-'0';
                    mx=max(dig,mx);
                    mn =min(dig,mn);
                }
                // cout<<mx<<" "<<mn<<endl;
                if(mx-mn>diff){
                    diff=mx-mn;
                    num=l;
                }
            }
            cout<<num<<endl;
        }
    }
    return 0;
    }