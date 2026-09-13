#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    n=0;
    // while(cin>>a){
    //     n++;
    // }
    // cout<<n<<endl;
    int out[166-1]; int in[166-1];
    for(int i=0;i<166-1;i++){
        cin>>out[i];
    }
    for(int i=0;i<166-1;i++){
        cin>>in[i];
    }
    int tot=0;
    for(int i=0;i<166-1;i++){
        if(out[i]!=in[i]){
            tot++;
            cout<<out[i]<<" "<<in[i]<<endl;
            cout<<i+1<<endl;
        }
    }
    cout<<tot<<endl;
    return 0;
    }