#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e6;
ll vis[N];
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        vector<vector<int>> v(n);
        vector<ll>uniq;
        for(int i=0;i<n;i++){
            cin>>b;
            for(int j=0;j<b;j++){
                cin>>a;
                v[i].push_back(a);
                uniq.push_back(a);
            }
        }

        for(int i=0;i<n;i++){
            reverse(v[i].begin(),v[i].end());
        }
        vector<vector<ll>>p;
        for(int i=0;i<n;i++){
            p.clear();
            for(int j=0;j<n;j++){
                vector<ll>q;
                q.clear();
                set<ll>st;
                st.clear();
                for(int k=0;k<v[j].size();k++){
                    if(vis[v[j][k]] or st.find(v[j][k])!=st.end())continue;
                    else {
                        q.push_back(v[j][k]);
                        st.insert(v[j][k]);
                    }
                }   
                if(q.empty())continue;
                p.push_back(q);
            }
            if(p.empty())break;
            sort(p.begin(),p.end());
            for(int j=0;j<p[0].size();j++){
                if(vis[p[0][j]])continue;
                cout<<p[0][j]<<" ";
                vis[p[0][j]]=1;
            }
        }
        cout<<endl;
        for(int i=0;i<uniq.size();i++)vis[uniq[i]]=0;
        uniq.clear();
    }
    return 0;
    }