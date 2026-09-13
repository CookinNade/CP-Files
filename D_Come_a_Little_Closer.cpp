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
        cin>>n;
        int y;
        set<pair<int,int>>x1;
        set<pair<int,int>>y1;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            x1.insert({x,y});
            y1.insert({y,x});
        }
        int val1,val2,m1,m2,mx,mn;
        ll area1,area2,area3,area4,result;
        l=0;
        if(n>2){

        // lowest y removed
        auto blyit=y1.begin();
        val1=blyit->first;
        val2=blyit->second;
        x1.erase({val2,val1});
        y1.erase({val1,val2});
        auto lyit=y1.begin();
        auto mxit=(--x1.end());
        auto myit=(--y1.end());
        auto lxit=x1.begin();
        m1=((myit->first)-(lyit->first)+1);
        m2=((mxit->first)-(lxit->first)+1);
        area1=1ll*((myit->first)-(lyit->first)+1)*((mxit->first)-(lxit->first)+1);
        
        if (area1<n){
            mx=max(m1,m2);
            mn=min(m1,m2);
            mx++;
            area1=1ll*mx*mn;
            result=area1;
            l++;
        }
        x1.insert({val2,val1});
        y1.insert({val1,val2});
        //highest y removed
        auto bmyit2=(--y1.end());
        val1=bmyit2->first;
        val2=bmyit2->second;
        x1.erase({val2,val1});
        y1.erase({val1,val2});
        auto lyit2=y1.begin();
        auto mxit2=(--x1.end());
        auto myit2=(--y1.end());
        auto lxit2=x1.begin();
        m1=((myit2->first)-(lyit2->first)+1);
        m2=((mxit2->first)-(lxit2->first)+1);
        area2=1ll*((myit2->first)-(lyit2->first)+1)*((mxit2->first)-(lxit2->first)+1);
        if (area2<n){
            mx=max(m1,m2);
            mn=min(m1,m2);
            mx++;
            area2=1ll*mx*mn;
            if(l>0){
            result=min(result,area2);
            }
            else result=area2;
            l++;
        }
        x1.insert({val2,val1});
        y1.insert({val1,val2});

        //highest x removed
        auto bmxit3=(--x1.end());
        val1=bmxit3->first;
        val2=bmxit3->second;
        x1.erase({val1,val2});
        y1.erase({val2,val1});
        auto lyit3=y1.begin();
        auto mxit3=(--x1.end());
        auto myit3=(--y1.end());
        auto lxit3=x1.begin();
        m1=((myit3->first)-(lyit3->first)+1);
        m2=((mxit3->first)-(lxit3->first)+1);
        area3=1ll*((myit3->first)-(lyit3->first)+1)*((mxit3->first)-(lxit3->first)+1);
        if (area3<n){
            mx=max(m1,m2);
            mn=min(m1,m2);
            mx++;
            area3=1ll*mx*mn;
            if(l>0){
            result=min(result,area3);
            }
            else result=area3;
            l++;
        }
        x1.insert({val1,val2});
        y1.insert({val2,val1});

        //lowest x removed
        auto blxit4=x1.begin();
        val1=blxit4->first;
        val2=blxit4->second;
        x1.erase({val1,val2});
        y1.erase({val2,val1});
        auto lyit4=y1.begin();
        auto mxit4=(--x1.end());
        auto myit4=(--y1.end());
        auto lxit4=x1.begin();
        m1=((myit4->first)-(lyit4->first)+1);
        m2=((mxit4->first)-(lxit4->first)+1);
        area4=1ll*((myit4->first)-(lyit4->first)+1)*((mxit4->first)-(lxit4->first)+1);
        if (area4<n){
            mx=max(m1,m2);
            mn=min(m1,m2);
            mx++;
            area4=1ll*mx*mn;
            if(l>0){
            result=min(result,area4);
            }
            else result=area4;
            l++;
        }
        x1.insert({val1,val2});
        y1.insert({val2,val1});
        if(l==0)
        result = min(min(area1,area2),min(area3,area4));
    }


        if(n==1 or n==2){
            cout<<n<<endl;
        }
        else cout<<result<<endl;
    }
    return 0;
    }