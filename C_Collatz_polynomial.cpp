#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    ll pol[100];
    fill(pol,pol+100,0);
    for(int i=n;i>=0;i--){
        cin>>a;
        pol[i]=a;
    }
    ll ans=0;
    bool yes=false;
    // k=0;
    while(true){
        for(int i=99;i>=0;i--){
            if(pol[i]){
                if(i==0){
                    yes=true;
                }
                break;
            }
        }
        if(yes)break;
       

        if(pol[0]){
            ans++;
            
            for(int i=98;i>=0;i--){
                pol[i+1]=pol[i]+pol[i+1];
            }
            // for(int j=5;j>=0;j--)cout<<pol[j]<<" ";
    
            for(int i=99;i>=1;i--){
                if(pol[i]==2)pol[i]=0;
            }
            pol[0]=0;
        }
        else{
            ans++;
            for(int i=0;i<98;i++){
                pol[i]=pol[i+1];
            }
        }
        // k++;
        // cout<<"step"<<" "<<k<<endl;
        // for(int j=5;j>=0;j--)cout<<pol[j]<<" ";
        // cout<<endl;
    }
    cout<<ans<<'\n';
    return 0;
    }