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
        cin>>s;
        
        
            int dig1 = s[0]-'0';
            int dig2=s[1]-'0';
            int dig3=s[3]-'0';
            int dig4=s[4]-'0';
            int h  = dig1*10 + dig2;
            m = dig3*10 + dig4;
            if(h==0 and m==0){
                cout<<"00:00"<<endl;
            }
            else if(h==11 and m==11){
                cout<<"11:11"<<endl;
            }
            else if(h==22 and m==22){
                cout<<"22:22"<<endl;
            }
            else if(h>=0 and h<=11){
                if(h==11 and m>11){
                    cout<<"22:22"<<endl;
                }
                else cout<<"11:11"<<endl;
            }
            else if(h>=11 and h<=22){
                if(h==22 and m>22){
                    cout<<"00:00"<<endl;
                }
                else cout<<"22:22"<<endl;
                
            }
            else cout<<"00:00"<<endl;
        


    }
    return 0;
    }