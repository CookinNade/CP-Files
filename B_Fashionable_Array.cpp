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
        map<int,int>mp;
        for(int i=0;i<n;i++)mp[arr[i]]++;
        sort(arr,arr+n,greater<int>());
        int cnt = 0;
        int jabe = 0;
        for(int i=0;i<n;i++){
            int a = arr[i];
            if(mp.find(a) == mp.end())continue;
            if(mp.find(a) != mp.end()){
                jabe = mp[a];
                for(int j=0;j<jabe;j++)cout<<a<<" ";
                mp.erase(a);
            }
            for(auto it = mp.begin();it!=mp.end();++it){
                for(int j = 0;j<min(jabe, (*it).second);j++)cout<<(*it).first<<" ";
                mp[(*it).first] -= min(jabe, (*it).second);
            }
            for(int j = 0;j<n;j++){
                if(mp.find(arr[j]) != mp.end() and mp[arr[j]] == 0)mp.erase(arr[j]);
            }
            if(mp.empty())break;
        }
        cout<<'\n';
    }
    return 0;
    }