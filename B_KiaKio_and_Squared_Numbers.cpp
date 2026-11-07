#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll hoise[n];
        int mx = 0;
        for(int i=0;i<n;i++){
            int a = arr[i];
            set<int>st;
            cnt = 0;
            st.clear();
            while(true){
                if(st.find(a) != st.end()){
                    mx = max(cnt,mx);
                    hoise[i] = cnt;
                    arr[i] = a;
                    break;
                }
                else st.insert(a);
                cnt++;
                string s = to_string(a);
                ll sum = 0;
                for(int j = 0; j<(int)s.size();j++){
                    ll num = s[j] - '0';
                    sum = sum + (num * num);
                }
                a = sum;
            }
        }
        ll ans = 0;
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            int a = arr[i];
            for(int j = 0;j<mx-hoise[i];j++){
                string s = to_string(a);
                ll sum = 0;
                for(int j = 0; j<(int)s.size();j++){
                    ll num = s[j] - '0';
                    sum = sum + (num * num);
                }
                a = sum;
            }
            arr[i] = a;
        }
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto it = mp.begin();it!=mp.end();++it){
            ll a = (*it).second;
            // cout<<(*it).first<<" "<<(*it).second<<'\n';
            ans = ans + a*(a-1)/2;
        }
        cout<<ans<<'\n';
    }
    return 0;
    }