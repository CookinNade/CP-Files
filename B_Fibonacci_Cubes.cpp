#include<bits/stdc++.h>
 
using namespace std;
// typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m;
        int fibon[n];
        int dim[3];
        fibon[0]=1;fibon[1]=2;
        for(int i=2;i<n;i++){
            fibon[i] = fibon[i-1]+fibon[i-2];
        }
        while(m--){
            int he=0;int wi=0;
        for(int j=0;j<3;j++){
            cin>>dim[j];
        }
        sort(dim,dim+3);
        for(int i=0;i<n;i++){
            if(i==0){
                wi=fibon[n-1];
                he=fibon[n-1];
            }
            else {
                if(wi+fibon[n-1-i]<=dim[1]){
                    wi=wi+fibon[n-1-i]*fibon[n-1-i];
                }
                else{
                    he = he+fibon[n-1-i];
                    dim[1]=fibon[n-i]*fibon[n-i];
                    wi=fibon[n-1-i]*fibon[n-1-i];
                }
            }
            
        }

        if (fibon[n-1]>dim[0] or he>dim[2]){
            cout<<0;
        }
        else cout<<1;

    }
    cout<<endl;

        
    }
    return 0;
    }