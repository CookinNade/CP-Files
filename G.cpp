#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    set<int>st;
    for(int i=0;i<n;i++)st.insert(arr[i]);
    if((int)st.size() > 2){
        cout<<"No";
        return 0;
    }
    if((int)st.size() == 1){
        int a = arr[0];
        if(a == n-1 or a*2 <=n)cout<<"Yes";
        else cout<<"No";
        return 0;
    }
    sort(arr,arr+n);
    int a = arr[0];
    int b = arr[n-1]; // joto ta distinct color ase
    int cnt = 0;
    int cntd = 0;
    for(int i=0;i<n;i++)if(a == arr[i])cnt++;
    for(int i=0;i<n;i++)if(b == arr[i])cntd++;
    int multi = b - cnt; // joto ta at least 2 ta wala ase 
    // cout<<multi<<" "<<cntd<<" "<<cnt;
    // cnt + cntd == b
    if(b-a == 1 and multi > 0 and multi*2 <= cntd and cnt + multi*2 <= n)cout<<"Yes";
    else cout<<"No";


    return 0;
    }