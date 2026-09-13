#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    int arr[10]={4,7,44,47,74,77,444,447,474,477};
    int yesser=0;
    for(int i=0;i<10;i++){
        if(n%arr[i]==0){
            yesser++;break;
        }
    }
    cout<<(yesser?"YES\n":"NO\n");
    return 0;
    }