#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,y; 
    cin>>t;
    string s;
    while (t--){
        cin>>x>>y>>k;
        if(k<y){
            cout<<k<<endl;
            continue;
        }
        ll hi=1e12;
        ll lo=y,mid;
        while(hi-lo>1){
            mid=hi+lo;
            mid=mid/2;
            r=mid;
            cnt=0;
            ll tot=0;
            for(int i=0;i<x;i++){
                cnt=(mid-tot)/y;
                tot=cnt+tot;
                if(tot>mid-k)break;
            }
            if(tot>mid-k)lo=mid+1;
            else hi=mid;
        }
        cnt=0;
        ll tot=0;
        for(int i=0;i<x;i++){
            cnt=(lo-tot)/y;
            tot=cnt+tot;
            if(tot>lo-k)break;
        }

        if(tot>lo-k){   
            cnt=0;
            tot=0;
            for(int i=0;i<x;i++){
                cnt=(hi-tot)/y;
                tot=cnt+tot;
                if(tot>hi-k)break;
            }
            if(tot>hi-k)cout<<-1<<endl;
            else cout<<hi<<endl;
        }
        else cout<<lo<<endl;
    }
    return 0;
    }