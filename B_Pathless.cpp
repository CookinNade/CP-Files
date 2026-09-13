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
    int s;
    while (t--){
        cin>>n>>s;
        int cnt2=0; int cnt1=0; int cnt0=0; int sum=0;
        for(int i=0;i<n;i++){
            cin>>a;
            sum=sum+a;
            if(a==0)cnt0++;
            else if(a==1)cnt1++;
            else cnt2++;
        }
        if(sum>s or sum+1==s){
            for(int i=0;i<cnt0;i++){
                cout<<0<<" ";
            }
            for(int i=0;i<cnt2;i++){
                cout<<2<<" ";
            }
            for(int i=0;i<cnt1;i++){
                cout<<1<<" ";
            }cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
    }