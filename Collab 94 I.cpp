#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
vector<string>v;
const ll N=1e6+2;
ll dp[N][3];
set<char>st;
ll k(int i, int d){
    if(i>=(int)v.size())return 0;
    if(dp[i][d]!=-1)return dp[i][d];
    ll ways=1e7;
    if(d==0){
        if(st.find(v[i][0])==st.end()){
            // cout<<"reutrned 1e7 at "<<i<<endl;
            return dp[i][d]=1e7;
        }
        ways=min(ways,1+k(i+1,2));
    }
    if(d==1){
        // 1 ta nibo
        if(st.find(v[i][0])!=st.end()) ways = min(ways,1+k(i+1,2));
        if(st.find(v[i][0])==st.end())ways = min(ways,1+k(i+1,0));
        // 2 ta nibo

        if(v[i].size()>=2 and st.find(v[i][0])==st.end() and st.find(v[i][1])!=st.end()) ways = min(ways,2+k(i+1,2));
    }
    if(d==2){
        if(st.find(v[i][0])!=st.end()){
            ways = min(ways,1+k(i+1,2));
        }
        if(st.find(v[i][0])==st.end()){
            ways = min(ways,1+k(i+1,1));
        }
        if(v[i].size()>=2 and st.find(v[i][0]) == st.end() and st.find(v[i][1])!=st.end()){
            ways = min(ways,2+k(i+1,2));
        }
        if(v[i].size()>=3 and st.find(v[i][0])== st.end() and st.find(v[i][1])==st.end() and st.find(v[i][2])!=st.end()){
            ways = min(ways,3+k(i+1,2));
        }
    }
    // cout<<i<<" "<<ways<<endl;
    return dp[i][d]=ways;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    st.insert('A');
    st.insert('E');
    st.insert('I');
    st.insert('O');
    st.insert('U');
    st.insert('Y');
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
        // cout<<v[v.size()-1]<<endl;
    }
    // for(int i=0;i<n;i++)cout<<v[i]<<endl;
    int ans= k(0,2);
    if(ans>=1e7)cout<<'*';
    else cout<<ans;
    return 0;
}