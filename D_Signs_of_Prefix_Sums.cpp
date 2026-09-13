#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        char arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        int f = 0;
        char c = arr[0];
        vector<pair<char,int>>v;
        v.push_back({'0',1});
        for(int i=0;i<n;i++){
            if(c == arr[i])f++;
            else{
                v.push_back({c,f});
                f = 1;
                c = arr[i];
            }
        }
        v.push_back({c,f});
        // for(auto x:v){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        int sz = (int)v.size();
        bool yes = true;
        int ans = 0;
        if(v[1].first == '0'){
            cout<<-1<<'\n';
            continue;
        }
        for(int i=1;i<sz;i++){
            if(v[i].first == '0' and v[i].second > 1){
                yes = false;
                break;
            }
            if(v[i-1].first == '0'){ // 0 theke sign e jacchi
                if(i == sz-1)ans = max(ans,1);
                else if(v[i].second % 2 == 0)ans = max(ans,2);
                else ans = max(ans,1);
            }
            else{ // sign theke sign or sign theke zero
                if(v[i].first == '0')ans = max(ans,1); // sign theke zero 
                else{
                    if(i != sz-1 and v[i].second == 2 and v[i+1].first == '0')ans = max(ans,2);
                    else if(i == sz-1 and v[i].second == 2)ans = max(ans,2);
                    else if(v[i].second == 2)ans = max(ans,3); // sign theke 2 length
                    else ans = max(ans,2); // sign theke any other lengh than 2 
                }
            }
            // cout<<ans<<" yo "<<i<<'\n';
        }   
        if(!yes)cout<<-1<<'\n';
        else if(sz == 2)cout<<1<<'\n';
        else cout<<ans<<'\n';
    }
    return 0;
    }