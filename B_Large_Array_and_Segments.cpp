#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k>>x;
        ll arr[n];
        ll size = n*k;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll sum=0,sheshans;
        ll shuruans=-1;
        sheshans=size+1;
        for(int i=n-1;;i--){
            sum=sum+arr[i];
            if(sum>=x){
                shuruans = size-n+i+1;
                break;
            }
            if(i==0){
                break;
            }
        }
        int noer=0;
        if(sum<x){
            ll potans= x/sum;
            if(potans*sum>=x and potans*n<=size){
                sheshans=size-n*potans+1;
                // cout<<"from here asd\n";
            }
            else if(potans*sum<x and potans*n<size){
                ll ronaldo = potans*sum;
                for(int i=n-1;;i--){
                   ronaldo=ronaldo+arr[i];
                   if(ronaldo<x){
                    continue;
                   }
                //    else if(ronaldo==x){
                //     sheshans=size-potans*n-n+i+1;
                //     break;
                //    }
                   else if(ronaldo>=x){
                    sheshans=size-potans*n-n+i+1;
                    break;
                   }
                   if(i==0){
                    break;
                   }
                }   
            }
        }
        if(shuruans>0){
            cout<<shuruans<<endl;
        }
        else if(sheshans<=size){
            cout<<sheshans<<endl;
        }
        else cout<<0<<endl;


    }
    return 0;
    }