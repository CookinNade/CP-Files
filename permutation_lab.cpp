#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<vector<int>>ans;
void perm(int j, vector<int>&arr){
    if(j==n){
        ans.push_back(arr);
        return;
    }
    for(int i=j;i<n;i++){
        swap(arr[i],arr[j]);
        perm(j+1, arr);
        swap(arr[i],arr[j]);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    perm(0,arr);
    sort(ans.begin(),ans.end());
    for(auto v:ans){
        for(auto x:v)cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
    }