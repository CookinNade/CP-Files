#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        cin>>s;
        ll boom[n+1];
        fill(boom,boom+1+n,0);
        ll arr[n+1];
        arr[0] = -1;
        for(int i=0;i<n;i++){
            if(s[i] == '1')arr[i+1] = 1;
            else arr[i+1] = 0;
        }
        for(int i=1;i<=n-1;i++){
            if(s[i] == s[i+1])boom[i+1] = 1;
        }
        for(int i=1;i<=n-1;i++){
            boom[i+1] = boom[i] + boom[i+1];
        }
        for(int i=1;i<=n;i++)cout<<arr[i];
        ll one[n+1];
        ll zero[n+1];
        fill(one,one+1+n,0);
        fill(zero,zero+1+n,0);
        for(int i=1;i<=n;i++){
            if(arr[i] == 0){
                one[i] = 1;
                zero[i] = 2;
            }
            else{
                one[i] = 2;
                zero[i] = 1;
            }
        }
        for(int i=1;i<=n;i++){
            zero[i] = zero[i-1] + zero[i];
            one[i] = one[i-1] + one[i];
        }
        cout<<endl;
        for(int i=1;i<=n;i++)cout<<one[i]<<"  ";
        cout<<endl;
        for(int i=1;i<=n;i++)cout<<zero[i]<<"  ";

    }
    return 0;
    }