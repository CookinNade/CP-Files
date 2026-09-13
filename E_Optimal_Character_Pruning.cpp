#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        char c='a';
        cin>>n>>s;
        map<char,int> mp;
        int arr[n];
        fill(arr,arr+n,1);
        for(int i=0;i<26;i++){
            cin>>a; 
            mp[c]=a;
            c++;
        }
        c='a';
        for(int i=0;i<26;i++,c++){
            if(mp[c]<1)continue;
            else{
                int big=0; int smol=0; int own=0; 
                for(int k=0;k<n;k++){
                    if(c<s[k])big++;
                    else if(c==s[k])own++;
                    else if(c>s[k] and arr[k]==1){
                        smol=k;
                        if(own){
                            break;
                        }
                    }
                }
                own=0;
                for(int j=0;j<n;j++){
                    if(s[j]==c)own++;
                    if(c>s[j] and arr[j]==1 and own)break;
                    if(s[j]>c)big--;
                    if(c==s[j] and mp[c]>0 and big!=0){
                        mp[c]--;
                        arr[j]=0;
                    }
                    if(big==0 or mp[c]==0)break;
                }
            }
        }

        c='a';
        for(int i=0;i<n;i++){
            if(s[i]>c)c=s[i];
        }
        
        for(int i=0;i<n;i++){
            if(s[i]==c or arr[i])cout<<s[i];
        }cout<<endl;
    }
    return 0;
    }