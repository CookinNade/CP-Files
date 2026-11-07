#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
bool hmm(int k){
    if(k % 3 == 0 or k % 5 == 0)return true;
    return false;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cnt = 0;
        int q;
        cin>>n>>q;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++)if(hmm(arr[i]))cnt++;
        cout<<cnt<<" ";
        while(q--){
            int i,x;
            cin>>i>>x;
            i--;
            if(hmm(arr[i]) and hmm(x)){
                cout<<cnt<<" ";
            }
            else if(hmm(arr[i]) and !hmm(x)){
                cnt--;
                cout<<cnt<<" ";
            }
            else if(!hmm(arr[i]) and hmm(x)){
                cnt++;
                cout<<cnt<<" ";
            }
            else if(!hmm(arr[i]) and !hmm(x))cout<<cnt<<" ";
            arr[i] = x;
        }
        cout<<'\n';
    }
    return 0;
    }