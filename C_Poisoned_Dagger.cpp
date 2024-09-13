#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define cp(x) cerr << " [ " << #x << " = (" << x.F << ", " << x.S << ") ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define all(x) x.begin(), x.end()
#define ll long long 
#define clz(x) __builtin_clz(x) 
#define ctz(x) __builtin_ctz(x) 

using namespace std;


ll n, h;
vector <int> v(100+6);

bool f(ll mid) {
    ll acc = mid;
    for (int i = 0; i < n-1; i++) {
        acc += min(1ll * v[i+1] - v[i], mid);
    }
    return (acc < h);
}

ll lower_bound(ll i, ll n){
    ll lo = i;
    ll hi = n;
    while(lo < hi){
        ll mid = lo + (hi - lo) / 2;
        if(f(mid)) lo = mid+1;
        else hi = mid;
    }
    return lo;
}

void solve() {
    cin >> n >> h;
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << lower_bound(0, h) << endl;

}
int main() {
    fastio;
    int q;
    cout << fixed << setprecision(10);
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
