#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        vector<ll>one;
        vector<ll>zero;
        string s;
        cin>>n>>s;
        char c = s[0];
        cnt = 1;
        for(int i=1;i<n;i++){
            if(s[i] == c)cnt++;
            else{
                if(c == '1')one.push_back(cnt);
                else zero.push_back(cnt);
                cnt = 1;
                c = s[i];
            }
        }
        if(c == '1')one.push_back(cnt);
        else zero.push_back(cnt);
        ll sum1 = accumulate(one.begin(),one.end(),0);
        ll sum0 = accumulate(zero.begin(),zero.end(),0);
        // cout<<sum1<<" "<<sum0<<endl;
        if(max(sum1,sum0) - min(sum1,sum0) > 2){
            cout<<-1<<'\n';
            continue;
        }
        // if(min(sum1,sum0) == 0 and max(sum1,sum0) > 2){
        //     cout<<-1<<'\n';
        //     continue;
        // }
        sum1 = 0;
        sum0 = 0;
        for(int i=0;i<(int)one.size();++i){
            sum1 = sum1 + one[i] - 1;
        }
        for(int i=0;i<(int)zero.size();++i){
            sum0 = sum0 + zero[i] - 1;
        }
        if(sum1 == sum0)cout<<2*sum1<<'\n';
        else cout<<2*max(sum1,sum0) - 1<<'\n';


    }
    return 0;
    }