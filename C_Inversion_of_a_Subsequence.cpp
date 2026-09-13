#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        int a[n]; int b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        int ache = 0;
        int lagbe = 0;
        int hobe = 0;
        int sum = accumulate(a,a+n,0);
        for(int i=0;i<n;i++){
            if(a[i] == 1 and b[i] == 0) ache++;
            if(a[i] == 0 and b[i] == 0) lagbe++;
            if(a[i] != b[i])hobe++;
        }
        if(hobe == 0)cout<<0<<endl;
        else if(ache and ache%2)cout<<1<<endl;
        else if(ache and ache%2==0)cout<<2<<endl;
        else if(sum and lagbe)cout<<2<<endl;
        else cout<<-1<<endl;
    }
    return 0;
    }