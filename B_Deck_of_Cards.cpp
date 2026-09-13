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
        cin>>n>>k>>s;
        int cnt1=0; int cnt0=0; int cnt2=0;
        char arr[n];
        fill(arr,arr+n,'+');
        for(int i=0;i<k;i++){
            if(s[i]=='1')cnt1++;
            else if(s[i]=='0')cnt0++;
            else cnt2++;
        }
        // cout<<s<<endl;
        // cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<endl;
        for(int i=0;i<cnt0;i++){
            arr[i]='-';
        }
        for(int i=n-1; cnt1>0 and i>=0;i--,cnt1--){
            arr[i]='-';
        }
        int pluscnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]=='+')pluscnt++;
        }
        l = cnt2;

        if(cnt2>=pluscnt){
            for(int i=0;i<n;i++){
                if(arr[i]!='-')arr[i]='-';
            }
        }
        else{
            if(cnt2>0){
                for(int i=0;i<n;i++){
            if(arr[i]=='+'){
                arr[i]='?';
                l--;
            }
            if(l==0)break;
            }
            for(int i=n-1;i>=0;i--){
                if(arr[i]=='+'){
                    arr[i]='?';
                    cnt2--;
                }
                if(cnt2==0)break;
            }
            }
            
        }
        
        for(auto x: arr){
            cout<<x;
        }cout<<endl;

        
    }
    return 0;
    }