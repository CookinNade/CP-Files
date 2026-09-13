#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m;
        ll g[n][m];
        ll cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[i][j];
                if(g[i][j])cnt++;
                // cout<<g[i][j]<<endl;
            }
        }
        ll ans[m];
        fill(ans,ans+m,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[j][i])ans[i]++;
            }
        }
        // cout<<cnt<<endl;
        a=cnt/2;
        if(cnt%2)a++;
        cnt=cnt/2;
        
        cout<<a*cnt<<endl;
        int yes=0;
        ll hobe=0;
        vector<char>v;
        for(int i=0;i<m;i++){
            hobe=hobe+ans[i];
            yes=i;
            if(hobe<=cnt)v.push_back('R');
            else {
                hobe=hobe-ans[i];
                break;
            }
        }
        // cout<<hobe<<endl;
        // cout<<cnt<<endl;
        if(hobe<cnt){
            ll lage = cnt-hobe;
            ll bad=ans[yes]-lage;
            // cout<<bad<<" siuu"<<endl;
            d=0;
            int hoise=0;
            for(int i=0;i<n;i++){
                if(hoise)v.push_back('D');
                else{
                    if(d<bad){
                        v.push_back('D');
                        if(g[i][yes])d++;
                        // cout<<d<<" "<<i<<endl;
                        if(d==bad){
                            v.push_back('R');
                            hoise++;
                        }
                    }
                }
            }
            for(int i=0;i<m;i++)v.push_back('R');
            for(int i=0;i<n+m;i++)cout<<v[i];
            cout<<endl;
        }
        else{
            for(int i=0;i<n;i++)v.push_back('D');
            for(int i=0;i<m;i++)v.push_back('R');
            for(int i=0;i<n+m;i++)cout<<v[i];
            cout<<endl;
        }
        // for(auto y:ans)cout<<y<<" ";
        
    }
    return 0;
    }