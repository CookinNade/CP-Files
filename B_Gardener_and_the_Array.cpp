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
        vector<int>v;
        vector<int>kk;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>k; kk.push_back(k);
            for(int j=0;j<k;j++){
                cin>>a;
                v.push_back(a);
                mp[a]++;
            }
        }
        int j=0; int yes=0;
        for(int i=0;i<kk.size();i++){
            l=j;cnt=0;
            for(;j<l+kk[i];j++){
                if(mp[v[j]]==1){
                    continue;
                }
                else cnt++;
            }
            if(cnt==kk[i]){
                yes++;break;
            }
        }
        cout<<(yes>0?"Yes\n":"No\n");
    }
    return 0;
    }