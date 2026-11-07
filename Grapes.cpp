#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int arr[n];
    fill(arr,arr+n,0);
    for(int i=0;i<n;i++)arr[i] = m/n;
    m = m%n;
    for(int i=0;i<n;i++)if(m){
        arr[i]++;
        m--;
    }
    for(int i=0;i<n;i++)cout<<arr[i]<<'\n';
    return 0;
    }