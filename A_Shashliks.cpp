#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        int y;
        cin>>k>>a>>b>>x>>y;
        cnt=0;
        if(x==y){
            int m=min(a,b);
            if(k>=m){
                cnt = (k-m)/x;
                cnt++;
            }
        }
        else if(x<y){
            if(k>=a){
                int cnta=(k-a)/x;
                cnta++;
                cnt=cnt+cnta;
                k=k-cnta*x;
            }
            if(k>=b){
                int cntb=(k-b)/y;
                cntb++;
                cnt=cnt+cntb;
            }
        }
        else if(y<x){
            if(k>=b){
                int cntb=(k-b)/y;
                cntb++;
                cnt=cnt+cntb;
                k=k-cntb*y;
            }
            // cout<<"value of cnt "<<cnt;
            if(k>=a){
                int cnta=(k-a)/x;
                cnta++;
                cnt=cnt+cnta;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
    }