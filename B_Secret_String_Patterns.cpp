#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        cout<<"? 1 "<<n<<endl;
        int ase;
        cin>>ase;
        if(ase == n){
            cout<<"! NO"<<endl;
            continue;
        }
        ase = n - ase;
        cout<<"? "<<n-ase+1<<" "<<n<<endl;
        cin>>ase;
        if(ase == 0)cout<<"! NO"<<endl;
        else cout<<"! YES"<<endl;
    }
    return 0;
    }