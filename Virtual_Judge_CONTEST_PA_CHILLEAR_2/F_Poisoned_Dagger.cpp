#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define ll long long
using namespace std;
vector <ll> v(100+2);
ll n, h;
bool f(ll k){
    ll dam = 0;
    for(int i = 1; i < n; i++){
        dam += min(v[i] - v[i-1], k);
    }
    dam += k;
    return dam >= h;

}

// Primer f() = 0
// 1 1 1 1 ... 1 |0| 0 .... 0
ll lower_bound(ll i, ll n){
    ll lo = i;
    ll hi = n;
    while(lo < hi){
        ll mi = lo + (hi - lo) / 2;
        if(!f(mi)) lo = mi+1;
        else hi = mi;
    }
    return lo;
}
int main() {
    fastio;
    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n >> h;
        for(int i = 0; i < n; i++) cin >> v[i];
        ll ans = lower_bound(0, h);
        cout << ans << "\n";

    }



}