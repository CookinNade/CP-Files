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
        cin>>n>>s;
        if(n>4)cout<<"NO\n";
        else if(n==1)cout<<"YES\n";
        else if(n==2){
            int num = stoi(s);
            if(num%2==0)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            int sum=0;
            int noer=0;
            for(int i=0;i<3;i++){
                int dig = s[i]-'0';
                if(dig%2 and i!=0){
                    noer++; break;
                }
                sum=sum+dig;
            }
            if(sum%3==0){
                //yo
            }
            else noer++;
            if(n==4){
                for(int i=1;i<n;i++){
                int dig = s[i]-'0';
                if(dig%2){
                    noer++; break;
                }
                sum=sum+dig;
                }
                if(sum%3==0){
                    //yo
                }
                else noer++;
                int num= stoi(s);
                if(num%4)noer++;
            }
            if(noer)cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
    return 0;
    }