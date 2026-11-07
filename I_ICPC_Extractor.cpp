#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
struct icpc{
    int i;
    int c1;
    int p;
    int c2;
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        int n = (int)s.size();
        set<ll>g[3];
        for(int i=0;i<n;i++){
            if(s[i] == 'I')g[0].insert(-i-1);
            if(s[i] == 'C')g[1].insert(-i-1);
            if(s[i] == 'P')g[2].insert(-i-1);
        }
        cout<<n<<endl;
        vector<icpc>ans;
        while(true){
            if(g[0].empty() or g[1].size() <=1 or g[2].empty())break;
            // last c
            auto it = g[1].begin();
            int c2 = (*it);
            //p er jonno 
            it = g[2].lower_bound(c2);
            if(it == g[2].end())break;
            int p = (*it);
            // first c
            it = g[1].lower_bound(p);
            if(it == g[1].end())break;
            int c1 = (*it);
            // i er jonno
            it = g[0].lower_bound(c1);
            if(it == g[0].end())break;
            int i = (*it);
            icpc h;
            h.i = i; g[0].erase(i);
            h.c1 = c1; g[1].erase(c1);
            h.p = p; g[2].erase(p);
            h.c2 = c2; g[1].erase(c2);
            ans.push_back(h);
        }
        cout<<(int)ans.size()<<'\n';
        for(int j=0;j<(int)ans.size();j++){
            cout<<-ans[j].i<<" "<<-ans[j].c1<<" "<<-ans[j].p<<" "<<-ans[j].c2<<'\n';
        }
    }
    return 0;
    }