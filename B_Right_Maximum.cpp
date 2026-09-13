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
        vector<ll>v[n+1];
        for(int i=0;i<n;i++){
            cin>>a;
            v[a].push_back(i);
        }
        c=n+1;
        cnt=0;
        for(int i=n;i>=1;i--){
            if(v[i].empty())continue;
            for(int j=v[i].size()-1;j<v[i].size();j--){
                if(c>v[i][j]){
                    c=v[i][j];
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
    }