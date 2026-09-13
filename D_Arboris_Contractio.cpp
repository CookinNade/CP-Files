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
        vector<int> v[n+1];
        pair<int,int> arr[n+1];
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=1;i<=n;i++) arr[i]={0,i};
        int zeroer=0; cnt=0;
        for(int i=1;i<=n;i++){
            if(v[i].size()==1) arr[v[i][0]].first++;
        }
        sort(arr+1,arr+n+1);
        int nod = arr[n].second;
        for(auto &vs:v){
            if(vs.size()==1){
                if(vs[0]==nod)continue;
                else cnt++;
            }
            else if(vs.size()==n-1){
                zeroer++;break;
            }
        }
        if(zeroer or n==2) cout<<0<<endl;
        else cout<<cnt<<endl;
    }
    return 0;
    }