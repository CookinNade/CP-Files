#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int g[100][100];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int cnt;
    cin>>cnt;
    if(cnt == 1){
        cout<<3<<" "<<3<<'\n';
        cout<<"O#.\n";
        cout<<"#.#\n";
        cout<<".#O\n";
        return 0;
    }
    for(int i=3;i<96;i++){
        for(int j=3;j<96;j++){
            if(cnt>0)g[i][j] = 1;
            cnt--;
        }
        if(cnt==0)break;
    }
    
    for(int i=3;i<96;i++){
        for(int j=3;j<96;j++){
            if(g[i][j+1] == 0 and g[i][j] == 1){
                g[i][j+1] = -2;
                g[i][j+2] = -1;
                g[i+1][j+1] = -1;
            }
            if(g[i-1][j] == 0 and g[i][j] == 1){
                g[i-1][j] = -2;
                g[i-1][j+1] = -1;
                g[i-2][j] = -1;
            }
            if(g[i][j-1] == 0 and g[i][j] == 1){
                g[i][j-2] = -1;
                g[i][j-1] = -2;
                g[i+1][j-1] = -1;
            }
            if(g[i+1][j] == 0 and g[i][j] == 1 and g[i][j+1] <= -1){
                // cout<<'dhukse\n';
                g[i+1][j] = -1;
                g[i+2][j+1] = -1;
                g[i+2][j] = -2;
            }
            else if(g[i+1][j] == 0 and g[i][j] == 1 and g[i][j+1] == 1){
                g[i+1][j] = -2;
                g[i+2][j] = -1;
                g[i+1][j+1] = -1;
            }
           
        }
    }
    cout<<100<<" "<<100<<'\n';
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(g[i][j] >=0 )cout<<'.';
            else if(g[i][j] == -1)cout<<'#';
            else cout<<'O';
        }
        cout<<endl;
    }
    
    return 0;
    }