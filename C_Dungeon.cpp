#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.first != b.first)
        return a.first < b.first;   
    return a.second > b.second;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m;
        multiset<ll>st;
        for(int i=0;i<n;i++){
            cin>>a;
            st.insert(a);
        }
        pair<ll,ll>arr[m];
        vector<ll>v;
        for(int i=0;i<m;i++)cin>>arr[i].first;
        for(int i=0;i<m;i++){
            cin>>arr[i].second;
            if(arr[i].second==0)v.push_back(arr[i].first);
        }
        sort(arr,arr+m,cmp);
        sort(v.begin(),v.end());
        cnt=0;
        for(int i=0;i<m;i++){
            if(arr[i].second ==0)continue;
            auto it =st.lower_bound(arr[i].first);
            if(it==st.end())break;
            else {
                cnt++;
                st.erase(it);
                st.insert(max(arr[i].second,(*it)));
            }
        }
        for(int i=0;i<v.size();i++){
            auto it = st.lower_bound(v[i]);
            if(it==st.end())break;
            else{
                st.erase(it);
                cnt++;
            }
        }
        cout<<cnt<<endl;

    }
    return 0;
    }