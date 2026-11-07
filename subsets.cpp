
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int n;
int arr[16];
vector<vector<int>>subs;
vector<int>can;
void sub(int i){
    if(i == n){
        subs.push_back(can);
        return;
    }
    sub(i+1);
    can.push_back(arr[i]);
    sub(i+1);
    can.pop_back();
}
bool com(vector<int>&a, vector<int>&b){
    if((int)a.size() != (int)b.size())return ((int)a.size() < (int)b.size());
    return a < b;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    sub(0);
    sort(subs.begin(),subs.end(), com);
    cout<<'[';
    for(int i=0;i<(int)subs.size();i++){
        cout<<'[';
        for(int j = 0;j<subs[i].size();j++){
            if(j!=(int)subs[i].size()-1) cout<<subs[i][j]<<", ";
            else cout<<subs[i][j];
        }
        if(i!=(int)subs.size()-1)cout<<"], ";
        else cout<<"]";
    }
    cout<<']';
    cout<<'\n';
    return 0;
    }