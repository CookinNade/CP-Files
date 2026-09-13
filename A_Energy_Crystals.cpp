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
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int stat,ed,val,val1;
        val=0;
        for(int i=0;i<n;i++){
            stat=i;ed=i;
            if(arr[stat]==arr[stat+1] and stat!=n-1){
                for(int i=stat;i<n;i++){
                    if(arr[stat]==arr[stat+1] and stat!=n-1){
                        ed++; 
                        
                    }
                    else if(arr[stat]==arr[stat+1] and stat==n-1){
                        ed++;
                        
                        int del = ed-stat;
                        val1=(n-del)*arr[stat];
                        if(val==0 or val1<val){
                            val=val1;
                        }
                        break;
                    }
                    else{
                        cout<<"it has reached here";
                        int del = ed-stat;
                        val1=(n-del)*arr[stat];
                        if(val==0 or val1<val){
                            cout<<"it has reached here";
                            val=val1;
                        }
                        i--;
                        break;
                    }
                }
                    
            }
        }
        sort(arr,arr+n);
        int n_1=n-1;
        m=arr[0]*n_1;
        // if(val!=0){
        //     cout<<min(m,val)<<endl;
        // }
        // else cout<<m<<endl;
        cout<<min(m,val)<<endl;
        cout<<m<<" this is m "<<endl<<"this is val "<<val<<endl;
    }    
    return 0;
}