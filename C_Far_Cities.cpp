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
        int d = 1;
        int h = 0;
        int hv = 0;
        int out = 0;
        int root = 1;
        for(int i=2;i<=n;i++){
            cout<<"? "<<root<<" "<<i<<" "<<d<<endl;
            cin>>out;
            if(out){
                hv = i;
                while(out !=0){
                    h = d;
                    if(d == n-1)break;
                    d++;
                    cout<<"? "<<root<<" "<<i<<" "<<d<<endl;
                    cin>>out;
                }
            }
            if(d == n)break;
        }
        root = hv;
        hv = 1;
        for(int i=1;i<=n;i++){
            if(root == i)continue;
            cout<<"? "<<root<<" "<<i<<" "<<d<<endl;
            cin>>out;
            if(out){
                hv = i;
                while(out !=0){
                    h = d;
                    if(d == n-1)break;
                    d++;
                    cout<<"? "<<root<<" "<<i<<" "<<d<<endl;
                    cin>>out;
                }
            }
            if(d == n)break;
        }
        cout<<"! "<<root<<" "<<hv<<" "<<h<<endl;

    }
    return 0;
    }