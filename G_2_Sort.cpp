#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    int cse=1;
    while (t--){
        long double x;
        cin>>x;
        long double tax=12500;
        if(x==0)cout<<tax<<endl;
        if(x>0){
            if(x>7500){
                tax=tax+7500*5;
                x=x-7500;
            }
            else {
                tax=tax+x*5;
                x=0;
            }
        }
        cout<<x<<" "<<tax<<endl;
        if(x>0){
            if(x>20000){
                tax=tax+50000;
                x=x-20000;
            }
            else{
                tax=tax+x*2.5;
                x=0;
            }
        }
        cout<<x<<" "<<tax<<endl;
        if(x>0){
            if(x>10000){
                tax=tax+50000;
                x=x-10000;
            }
            else{
                tax=tax+x*5;
                x=0;
            }
        }
        cout<<x<<" "<<tax<<endl;
        if(x>0){
            tax=tax+(x*40)/9;
        }
        cout<<tax<<endl;

    }
    return 0;
    }