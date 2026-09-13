#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        vector<pair<int,int>>vs;
        vector<pair<int,int>>vt;
        for(int i=0;i<n;i++){
            cin>>a;
            l = a%k;
            r = abs(l-k);
            int mn = min(l,r);
            int mx = max(l,r);
            vs.push_back({mn,mx});
        }
        for(int i=0;i<n;i++){
            cin>>a;
            l = a%k;
            r = abs(l-k);
            int mn = min(l,r);
            int mx = max(l,r);
            vt.push_back({mn,mx});
        }
        sort(vs.begin(),vs.end());
        sort(vt.begin(),vt.end());
        cout<<(vs==vt ? "YES\n":"NO\n");
    }
    return 0;
}