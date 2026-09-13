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
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<int>v(n);
        for(int i=0;i<n;i++)v[i]=arr[i];
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()), v.end());
        for(int i=0;i<n;i++){
            arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
        }
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        int rn = 0;
        int l = -1;
        map<int, vector<pair<int,int>>> mp;
        for(int i=0;i<n;i++){
            if(rn != arr[i]){
                mp[rn].push_back({l,i-1});
                rn = arr[i];
                l = i;
            }
        }
        mp[rn].push_back({l,n-1});
        mp.erase(0);
        int yes =  true;
        int a = 0;
        int b = 0;
        for(auto it = mp.begin(); it!=mp.end(); ++it ){
            b = (*it).first;
            int sz = (int)mp[b].size();
            if(sz>=4){
                yes = false; 
                break;
            }
            else if(sz>=2 and !a){
                a = b;
            }
        }
        if(!yes)cout<<"NO\n";
        else if(a){
            vector<int>p;
            for(int i=0;i<(int)mp[a].size();i++){
                p.push_back(mp[a][i].first);
                if(mp[a][i].first == mp[a][i].second)continue;
                p.push_back(mp[a][i].second);
            }
            bool st[n+1];
            for(int i=0;i<(int)p.size();i++){
                for(int j = 0; j<(int)p.size(); j++){
                    if(j == i)continue;
                    int o = p[i];
                    int u = p[j];

                    if(o != 0) swap(arr[o-1],arr[u]);
                    rn = -1;
                    yes = true;
                    fill (st,st+n+1,false);
                    for(l = 0 ; l<n ; l++){
                        if(arr[l] != rn){
                            if(st[arr[l]]){
                                yes = false;
                                break;
                            }
                            st[rn] = true;
                            rn = arr[l];
                        }
                    }
                    if(o != 0) swap(arr[o-1],arr[u]);
                    if(yes) break;
                    if(o != n-1) swap(arr[o+1],arr[u]);
                    rn = -1;
                    yes = true;
                    fill (st,st+n+1,false);
                    for(l = 0 ; l<n ; l++){
                        if(arr[l] != rn){
                            if(st[arr[l]]){
                                yes = false;
                                break;
                            }
                            st[rn] = true; 
                            rn = arr[l];
                        }
                    }
                    if(o != n-1) swap(arr[o+1],arr[u]);
                    if(yes) break;
                }
                if(yes) break;
                else continue;
            }
            if(yes)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
    return 0;
    }