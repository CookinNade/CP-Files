#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    // cin>>t;
    t = 1;
    while (t--){
        ll q,v;
        cin>>q>>v;
        priority_queue<int>p;
        // p.push(5);
        while(q--){
            int op;
            cin>>op;
            if(op==1){
                ll tt, w;
                cin>>tt>>w;
                w = w - tt;
                p.push(w);
            }
            else{
                ll tt;
                cin>>tt;
                if(p.empty()){
                    cout<<-1<<"\n";
                    continue;
                }
                else cout<<min(v,p.top()+tt)<<"\n";
                p.pop();
            }
        }

    }
    return 0;
    }