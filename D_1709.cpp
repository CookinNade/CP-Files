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
        int cntcmax[m]={0};
        int cntrmax[n]={0};
        int grd[n][m];
        
        for(int i=0;i<n;i++){                   //T.C: 2.10^5
            for(int j=0;j<m;j++){
                cin>>a;
                grd[i][j]=a;
                mx=max(mx,a);
            }
        }
        for(int i=0;i<n;i++){                   //T.C: 2.10^5
            for(int j=0;j<m;j++){
                if(grd[i][j]==mx){
                    cnt++; 
                    cntcmax[j]++;
                    cntrmax[i]++;
                }
            }
        }
        int maxrcnt=0; int maxccnt=0; int ir,ic;
        // maxrcnt=cntrmax[0];
        // maxccnt=cntcmax[0];
        // if(m>=n){
            for(int i=0;i<n;i++){               //T.C: 1.4.10^2.5
                if(maxrcnt<cntrmax[i]){
                    ir=i;
                    maxrcnt=cntrmax[i];
                }
            }
        // }
        // else {
            for(int i=0;i<m;i++){               //T.C: 1.4.10^2.5
                if(maxccnt<cntcmax[i]){
                    ic=i;
                    maxccnt=cntcmax[i];
                }
            }
        // }      
        
        l=0;
        if(maxccnt + maxrcnt == cnt+1){
            cout<<mx-1<<endl;
        }
        else if(maxccnt>=maxrcnt){
            for(int i=0;i<n;i++){
                if(grd[i][ic]==mx){
                    continue;
                }
                else if(maxccnt + cntrmax[i]==cnt){
                    l++;
                    break;
                }
                else if(maxccnt + cntrmax[i]<cnt){
                    continue;
                }
            }
            if(l>0){
                cout<<mx-1<<endl;
            }
            else cout<<mx<<endl;
        }
        else if(maxccnt<maxrcnt){
            for(int i=0;i<m;i++){
                // cout<<maxrcnt + cntcmax[i]<<endl;
                // cout<<"this is maxrcnt "<< maxrcnt << " this is cntcmax[i] "<<cntcmax[i]<<endl;
                // cout<<"this is ir "<<ir<<endl;
                if(grd[ir][i]==mx){
                    continue;
                }
                else if(maxrcnt + cntcmax[i]==cnt){
                    l++;
                    break;
                }
                else if(maxrcnt + cntcmax[i]<cnt){
                    continue;
                }
            }
            if(l>0){
                cout<<mx-1<<endl;
            }
            else cout<<mx<<endl;
        }
    }
    return 0;
    }