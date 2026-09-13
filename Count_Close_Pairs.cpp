#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    int cnt = 0;
    int ans = 0;
    int i = 1;
    for(int j=1;j<=n;j++){
        if(i >= j)continue;
        cout<<"? "<<i<<" "<<j<<endl;
        cin>>s;
        if(s == "Yes")continue;
        else{
            ans = ans + j - i - 1;
            j--;
            i++;
        }
        if(i >= n)break;
    }
    for(;i<=n;i++)ans = ans + n - i;
    cout<<"! "<<ans<<endl;
    return 0;
    }