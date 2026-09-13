#include<bits/stdc++.h>
 
using namespace std;
// typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        int N=2e5;
        int arr[N+1]={0};
        cin>>n;
        int bar[n];
        
        for (int i=1;i<=n;i++){
            cin>>a;
            arr[a]++;
            bar[i]=a;
            
        }
        int trc=0;int l=0;int r=0;int l1=1;int r1=0;
        for(int i=1;i<=n;i++){
            if(arr[bar[i]]==1 and trc<1){
                trc++;
                l=i;r=i;
                if(r1-l1<=r-l){
                    r1=r;
                    l1=l;
                }
            }
            else if(arr[bar[i]]==1 and i==n){
                r=i;
                if(r1-l1<=r-l){
                    r1=r;
                    l1=l;
                }

            }
            else if(arr[bar[i]]==1){
                r=i;
            }
            else if(arr[bar[i]]>1 and trc<1){
                continue;
            }
            else if(arr[bar[i]]>1 and i==n){
                if(r1-l1<=r-l){
                    r1=r;
                    l1=l;
                }
                l=i+1;
            }
            else if(arr[bar[i]]>1){
                if(r1-l1<=r-l){
                    r1=r;
                    l1=l;
                }
                l=i+1;
            }
        }
        if(l1==1 and r1==0){
            cout<<0<<endl;
        }
        else cout<<l1<<" "<<r1<<endl;
    }    
    return 0;
}