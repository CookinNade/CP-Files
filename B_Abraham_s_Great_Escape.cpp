#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        int tot = n*n;
        int rem = tot-k;
        char grid [n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]='0';
            }
        }
        if(rem==1)cout<<"NO\n"<<endl;
        else{
            cout<<"YES\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]=='D')continue;
                    if(k){
                        grid[i][j]='U';
                        k--;
                        if(k==0){
                            if(i!=n-1){
                                for(int o=j+1;o<n;o++){
                                    grid[i][o]='D';
                                }
                            }
                            else{
                            for(int o=j+1;o<n;o++){
                                if(o==n-1)grid[i][o]='L';
                                else grid[i][o]='R';
                            }
                            break;
                        }
                        }
                        
                    }
                    else{
                        if(j==0)grid[i][j]='R';
                        else grid[i][j]='L';
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<grid[i][j];
                }cout<<endl;
            }
        }

    }
    return 0;
    }