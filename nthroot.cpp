#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
double nthroot(double a, int n) {
    bool neg = a < 0;
    if (neg) a = -a;               // assumes odd n if a was negative
    double lo = 0, hi = max(1.0, a); 
    /*  
        hi emne newar karon if a is less than zero taile
        root is larger than the the number a, the real root is out of search window 
    */
    for (int it = 0; it < 100; it++) { 
        /*
            100 iteration should be plenty. otherwise there is a chance of
            getting stuck in a while loop
        */
        double mid = (lo + hi) / 2;
        if (pow(mid, n) < a) lo = mid; 
        /*
            apparently this pow is strong enough to be accurate
            pow does go wrong in some cases, but should be strong enough for this one
            also its O(1) instead of naively writing in O(N)
            it goes wrong when the value is over 2^53
        */
        else hi = mid;
    }
    double r = (lo + hi) / 2;
    return neg ? -r : r;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double a,b;
    cin>>a>>b;
    cout<<nthroot(a,b);
    
    return 0;
    }