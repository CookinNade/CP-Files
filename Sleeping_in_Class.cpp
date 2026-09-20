#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1e5+2;
const int INF = 1e8;
int arr[N];
int n;
int hobe(int v){
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(i == n-1){
            if(v == arr[i])return cnt;
            else return INF;
        }
        if(arr[i] > v)return INF;
        if(arr[i] < v) {
            arr[i+1] += arr[i];
            cnt++;
        }
    }
    return INF;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        for(int i=0;i<n;i++)cin>>arr[i];
        int a = arr[0];
        bool yes = true;
        int b[n];
        for(int i=0;i<n;i++)b[i] = arr[i];
        for(int i=0;i<n;i++) yes &= (a == arr[i]);
        if(yes){
            cout<<0<<'\n';
            continue;
        }
        int ans = n-1;
        int sum = accumulate(arr,arr+n,0ll);
        for(int i=1;i*i<=sum;i++){
            if(sum % i == 0){
                ans = min(ans, hobe(sum / i));
                for(int i=0;i<n;i++)arr[i] = b[i];
                ans = min(ans, hobe(i));
                for(int i=0;i<n;i++)arr[i] = b[i];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
    }