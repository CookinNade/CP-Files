#include<bits/stdc++.h>
 
using namespace std;
// typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        int arr[n]; int sarr[n];
        for(int i=0;i<n;i++){
           cin>>a;
           arr[i]=a;
           sarr[i]=a;
        }
        sort(sarr,sarr+n);
        // for(int i=0; i<n;i++){
        //     cout<<sarr[i]<<" ";
        // }
        int lng=0;int l1=-1; int r1=-2;l=-1;r=0;
        for(int i=0; i<n;i++){
            cnt=1;
            int hi = n-1; int lo=0;
            int tfnd = arr[i];
           while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(sarr[mid]>tfnd){
                hi = mid;
            }
            else if(sarr[mid]<=tfnd){
                lo=mid;
            }
           }
           if(tfnd == sarr[lo]){
                if(lo!=0 and sarr[lo-1] == tfnd){
                    cnt++;
                }
                else if(sarr[lo+1]==tfnd and lo<n-1){
                    cnt++;
                }
                
           }
           else if(tfnd == sarr[hi]){
                if(hi!=n-1 and sarr[hi+1]==tfnd){
                    cnt++;
                }
                else if(sarr[hi-1] == tfnd and hi!=0){
                    cout<<sarr[hi+1]<<endl<<hi<<endl;
                    cnt++;
                }
                
           }
           if(cnt==1 and l==-1){
                l=i+1;
                r=i+1;
                lng = r-l;
                if(lng>=r1-l1){
                    l1=l;r1=r;
                }
           }
           else if(cnt==1 and l!=-1){
                l=i+1;
                lng = r-l;
                if(lng>=r1-l1){
                    l1=l;r1=r;
                }
                l=i+2;
           }
           else if(cnt==1 and i==n-1 and r==l){
            r1=i+1;
           }
           else if(cnt>1 and l!=-1){
                r=i;
                lng = r-l;
                if(lng>=r1-l1){
                    l1=l;r1=r;
                }
                l=i+2;
           }
           else if(cnt>1 and r1==-2){
                continue;
           }
           
           

            // if(cnt==1){
            //     l=i+1;
            //     for (;i<n;i++){
            //         cnt = count(arr,arr+n,arr[i]);
            //         if(cnt>1){
            //             r=i;
            //             i--;
            //             break;
            //         }
            //         else if(i==n-1){
            //             r=i+1;
            //         }
            //     }
            //     lng = r-l;
            //     if(lng>r1-l1){
            //         l1=l;r1=r;
            //     }
            // }

        }

        //Print parts
        
        if(n==1){
            cout<<1<<" "<<1<<endl;
        }
        else if (r1==-2){
            cout<<0<<endl;
        }
        else cout<<l1<<" "<<r1<<endl;

    }
    return 0;
    }