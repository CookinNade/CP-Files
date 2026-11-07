
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+2;
ll arr[N];
int n,m;
bool hobe(ll a){
    ll sum = 0;
    int cnt = 1;
    for(int i=0;i<n;i++){
        if(sum + arr[i] > a){
            cnt++;
            sum = arr[i];
        }
        else sum += arr[i];
    }
    // cout<<cnt<<" "<<a<<endl;
    return (cnt <= m);
}
int main() {
    cin>>n;
    if(m > n){
        cout<<-1<<'\n';
        return 0;
    }
    for(int i=0;i<n;i++)cin>>arr[i];
    cin>>m;
    if(m > n){
        cout<<-1<<'\n';
        return 0;
    }
    ll hi = accumulate(arr,arr+n,0ll);
    ll lo = *max_element(arr,arr+n);
    // hobe(113);
    // hobe(2);
    while(hi - lo > 1){
        ll mid = hi+lo;
        mid /= 2;
        if(hobe(mid))hi = mid;
        else lo  = mid + 1;
    }
    if(hobe(lo))cout<<lo<<'\n';
    else if(hobe(hi))cout<<hi<<'\n';
    else cout<<-1<<'\n';
}