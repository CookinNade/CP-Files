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
        cin>>n;
        vector<int>g[501];
        pair<int,int> hi[n+1];
        for(int i=1;i<=n;i++){
            cout<<"? "<<i<<" "<<n<<" ";
            for(int j=1;j<=n;j++){
                cout<<j<<" ";
            }cout<<endl;
            cout.flush();
            cin>>x;
            hi[i].first=x; hi[i].second=i;
            g[x].push_back(i);
        }
        sort(hi+1,hi+n+1);
        int node=hi[n].second;
        int lvl=hi[n].first;
        vector<int>path;
        path.push_back(node);
        for(int i=1;i<=lvl-1;i++){
            int chk=lvl-i;
            for(auto y:g[chk]){
                int f=0;
                cout<<"? "<<node<<" "<<i+1<<" ";
                for(int j=0;j<path.size();j++){
                    cout<<path[j]<<" ";
                }
                cout<<y<<" ";
                cout<<endl;
                cout.flush();
                cin>>x;
                if(x==i+1){
                    path.push_back(y); f++;
                    break;
                }
                if(f)break;
            }
        }
        cout<<"! "<<path.size()<<" ";
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }cout<<endl; cout.flush();

    }
    return 0;
    }