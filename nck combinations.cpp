#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<vector<int>>ans;
vector<int>v;
void combo(int i, int k, vector<int>&arr){
    if(k == 0){
        ans.push_back(v);
        return;
    }
    if(i==n)return;
    v.push_back(arr[i]);
    combo(i+1, k-1, arr);
    v.pop_back();
    combo(i+1,k,arr);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i = 0;i<n;i++)cin>>arr[i];
    combo(0,k,arr);
    for(auto c:ans){
        for(auto x:c)cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
    }