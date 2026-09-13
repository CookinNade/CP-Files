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
        cin>>n>>m;
        vector <pair<int,int>> v; cnt=0;
        for(int i=0;i<n;i++){
            cin>>a;
            s = to_string(a);
            int take =0;
            for(int j = s.size()-1; s[j]=='0';j--){
                if(s[j]=='0')take++;
                else break;
            }
            if(take==0){
                cnt = cnt+s.size();
            }
            else {
                v.push_back({take,s.size()});
            }
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++){
            if(i%2==0) cnt = cnt+ v[i].second-v[i].first;
            else cnt = cnt + v[i].second;
        }
        cout<<(cnt>m?"Sasha\n":"Anna\n");
    }
    return 0;
}