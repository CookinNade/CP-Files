#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 3e6;
bool siv[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int>prime;
    siv[1] = true;
    for(int i=2;i<3e5;i++){
        if(!siv[i]){
            // cout<<i<<" ";
            prime.push_back(i);
            for(int j=2*i;j<3e5;j+=i) siv[j] = true;
        }
    }  
    int t; 
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){
            // cout<<arr[i]<<" ";
            auto it = lower_bound(prime.begin(),prime.end(),arr[i]);
            int b = (*it);
            cout<<b<<" ";
        }
        // for(auto x:arr)cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
    }