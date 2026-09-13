#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e5 + 1;
ll a[N];
ll b[N];
int used[N];
int n,m,x,y;
ll val(int cn, int cm, ll sum1){
    ll nibox = 0; ll niboy = 0;
        int r = cn;
        int d = cm;
        for(int i=0;i<cm and i<y;i++){
            if(used[b[i]] == 1){
                if(nibox == 0){
                    for(;r<x;r++){
                        if(used[a[r]] == 0){
                            nibox = a[r];
                            r++;
                            break;
                        }
                    }
                }
                if(niboy == 0){
                    for(;d<y;d++){
                        if(used[b[d]] == 0){
                            niboy = b[d];
                            d++;
                            break;
                        }
                    }
                }
                if(nibox >= niboy){
                    sum1 += nibox;
                    used[nibox] = 1;
                    if(nibox == niboy) niboy = 0;
                    nibox = 0;
                    continue;
                }
                else{
                    sum1+=niboy;
                    used[niboy] = 1;
                    niboy = 0;
                }

            }
            else {
                sum1 +=b[i];
            }
        }
        return sum1;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n>>m>>x>>y;
        for(int i=0;i<x;i++){
            cin>>a[i];
        }
        for(int i=0;i<y;i++){
            cin>>b[i];
        }
        reverse(a,a+x);
        reverse(b,b+y);
        fill(used,used+n+m+1,0);
        int cn = min(n,x);
        int cm = min(m-1,y);
        for(int i=0;i<cn;i++)used[a[i]]++;
        ll sum1 = accumulate(a,a+cn,0ll);
        sum1 = val(cn,cm,sum1);
        

        cn = min(n-1,x);
        cm = min(y,m);

        fill(used,used+n+m+1,0);
        for(int i=0;i<cn;i++)used[a[i]]++;
        ll sum2 = accumulate(a,a+cn,0ll);
        sum2 = val(cn,cm,sum2);
        

        // cout<<sum1<<" "<<sum2<<"\n";
        cout<<max(sum1,sum2)<<'\n';


    }
    return 0;
    }