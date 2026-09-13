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
        cnt=0;
        ll cnt0=0;
        vector<ll>v1;
        vector<ll>v2;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
                v1.push_back(i+1);
            }
            else {
                cnt0++;
                v2.push_back(i+1);
            }
        }
        if(cnt==0){
            cout<<0<<endl;
            continue;
        }
        int j=0;
        ll orig1=cnt; ll orig0=cnt0; 
        int no=0;
        while(true){
            j++;
            if(j%2){
                d=cnt0;
                cnt0=cnt+1;
                cnt=d-1;
            }
            else{
                d=cnt;
                cnt=cnt0+1;
                cnt0=d-1;
            }
            if(cnt==0 or cnt0==0 or cnt<0 or cnt0<0)break;
        }
        if(cnt==0 and j<=v2.size()){
            cout<<v2.size()<<endl;
            for(int i=0;i<v2.size();i++){
                cout<<v2[i]<<" ";
            }
            cout<<endl;
        }
        else{
            j=1;
            cnt=orig1;cnt0=orig0;
            while(true){
                j++;
                if(j%2){
                    d=cnt0;
                    cnt0=cnt+1;
                    cnt=d-1;
                }
                else{
                    d=cnt;
                    cnt=cnt0+1;
                    cnt0=d-1;
                }
                if(cnt<=0 or cnt0<=0)break;
            }
            if(cnt==0 and j-1<=v1.size()){
                cout<<v1.size()<<endl;
                for(int i=0;i<v1.size();i++){
                    cout<<v1[i]<<" ";
                }
                cout<<endl;
            }
            else cout<<-1<<endl;
        }

    }
    return 0;
    }