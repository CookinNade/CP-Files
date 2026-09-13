#include<bits/stdc++.h>
 
using namespace std;
typedef int ll;
set<pair<int,int>>st;
int bfs(int x1, int y1 , int x2, int y2){
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{x1,y1}});;
    int ans=-1;
    while(!q.empty()){
        int a = q.front().second.first;
        int b = q.front().second.second;
        int level = q.front().first;
        if(a==x2 and b==y2){
            ans=level;
            break;
        }
        q.pop();
        if(st.find({a+1,b+1})!=st.end()){
            q.push({level+1,{a+1,b+1}});
            st.erase({a+1,b+1});
        }
        if(st.find({a+1,b-1})!=st.end()){
            q.push({level+1,{a+1,b-1}});
            st.erase({a+1,b-1});
        }
        if(st.find({a+1,b})!=st.end()){
            q.push({level+1,{a+1,b}});
            st.erase({a+1,b});
        }
        if(st.find({a-1,b+1})!=st.end()){
            q.push({level+1,{a-1,b+1}});
            st.erase({a-1,b+1});
        }
        if(st.find({a-1,b-1})!=st.end()){
            q.push({level+1,{a-1,b-1}});
            st.erase({a-1,b-1});
        }
        if(st.find({a-1,b})!=st.end()){
            q.push({level+1,{a-1,b}});
            st.erase({a-1,b});
        }
        if(st.find({a,b-1})!=st.end()){
            q.push({level+1,{a,b-1}});
            st.erase({a,b-1});
        }
        if(st.find({a,b+1})!=st.end()){
            q.push({level+1,{a,b+1}});
            st.erase({a,b+1});
        }
    }
    return ans;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    t=1;
    string s;
    while (t--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int n,r,a,b; cin>>n;
        for(int i=0;i<n;i++){
            cin>>r>>a>>b;
            for(int j=a;j<=b;j++) st.insert({r,j});
        }
        cout<<bfs(x1,y1,x2,y2)<<endl;

    }
    return 0;
    }