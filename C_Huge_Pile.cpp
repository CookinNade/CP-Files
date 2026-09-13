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
        cin>>n>>k;
        if(k>n)cout<<-1<<endl;
        else{
            vector<ll>v1;
            vector<ll>v2;
            if(k==1){
                cnt=0;
                while(true){
                    if(k>=n){
                        cout<<cnt<<endl;
                        break;
                    }
                    k=k*2+1;
                    cnt++;    
                }
                continue;
            }
            v1.push_back(k);
            v2.push_back(k);
            a=k;
            while(true){
                a=a*2 +1;
                v1.push_back(a);
                if(a>n)break;
            }
            a=k;
            ll ans=-1;
            while(true){
                a=a*2 -1;
                v2.push_back(a);
                if(a>n)break;
            }
            int yes=0;
            for(int i=0;i<v1.size();i++){
                if(n<=v1[i] and n>=v2[i]){
                    yes++;
                    ans=i;
                    break;
                }
            }
            if(yes)cout<<ans<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
    }