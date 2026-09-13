#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int c;
        cin>>n>>c;
        int a[n];
        int b[n];
        int ase[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            ase[i] = a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(a[i] >= b[i])ans = ans + (a[i] - b[i]);
            else {
                ans = 1e9;
                break;
            }
        }
        int sum = c;
        sort(b,b+n);
        sort(a,a+n);

        for(int i=0;i<n;i++){
            if(a[i] >= b[i])sum = sum + (a[i] - b[i]);
            else {
                sum = 1e9;
                break;
            }
        }
        if(min(ans,sum) == 1e9)cout<<-1<<endl;
        else cout<<min(ans,sum)<<endl;
    }
    return 0;
    }