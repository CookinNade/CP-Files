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
        cin>>n>>m;
        int mx=0;
        cnt=0;
        int N =1e5;
        int cntc[N+1]={0};
        int cntr[N+1]={0};
        int grd[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a;
                grd[i][j]=a;
                mx=max(mx,a);
                // if(mx==a){
                //     cnt++;
                // }
                // else if(a>mx){
                //     cnt=1;
                //     mx=a;
                // }
                // else if(mx>a){
                //     continue;
                // }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grd[i][j]==mx){
                    if(cntc[j]==0){
                        cntc[j]++;
                        // cout<<"eikhane dhukse";
                    }
                    if(cntr[i]==0){
                        cntr[i]++;
                        // cout<<"eikhane dhukse";
                    }
                    // cout<<"this is my i "<<i<<endl;
                    // cout<<"this is my j "<<j<<endl;
                }
            }
        }
        ll ctc = accumulate(cntc,cntc+N+1,0ll);
        ll ctr = accumulate(cntr,cntr+N+1,0ll);
        // cout<<"this is ctc "<<ctc<<endl;
        // cout<<"this is ctr "<<ctr<<endl;
        if(ctc>2 and ctr>2 and ctc!=ctr){
            cout<<mx<<endl;
        }
        else cout<<mx-1<<endl;

    }
    return 0;
    }