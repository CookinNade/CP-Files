#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int state[11];
int n;
// int num = 0;
void yo(int i){
    if(i==0)return;
    yo(i-1);
    if(state[i]){
        cout<<"Move "<<i<<" from B1 to B2\n";
        // num -= (1ll<<(i-1));
        // cout<<num<<'\n';
        state[i] = 0;

    }
    else{
        cout<<"Move "<<i<<" from B2 to B1\n";
        // num += (1ll<<(i-1));
        // cout<<num<<'\n';
        state[i] = 1;
    }
    yo(i-1);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n>>k;
        for(int i=0;i<=n;i++)state[i] = 0;
        for(int i=0;i<k;i++){
            int a;
            cin>>a;
            state[a] = 1;
            // num += (1ll << (a-1));
        }
        // cout<<num<<endl;
        yo(n);
        cout<<'\n';
    }
    return 0;
    }