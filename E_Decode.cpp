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

vector <pair<int,int>> v(5e5+5);
int n;

bool f(double k) {
    dbg(k);
    double xam = (v[0].S > 0) ? 1.0 * v[0].F + k * v[0].S : -2e19;
    for (int i = 1; i < n; i++) {
        double b = 1.0 * v[i].F + k * v[i].S;
        if(v[i].S > 0) xam = max(xam, b);
        else if (b <= xam) return 1;  
    } 
    return 0;
}

double lower_bound(double i, double nn){
    double lo = i;
    double hi = nn;
    int ex = 0;
    while(1e-10 < hi - lo and ex <= 200){
        double mid = (hi + lo) / 2.0;
        if(!f(mid)) lo = mid;
        else hi = mid;
        ex++;
    }
    return lo;
}

int mod = 1e9 + 7;
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i].F >> v[i].S;
    sort(v.begin(), v.begin() + n-1);
    if (v[0].S == v[n-1].S) {
        cout << -1 << endl;
        return;
    }
    double ans = lower_bound(0, 2e9+56);
    cout << ((ans == 2e9+56) ? -1 : ans) << endl;
    return;

}

int main() {
    fastio;
    int q = 1;
    cout << fixed << setprecision(11);
    cerr << fixed << setprecision(11);
    while(q--) {
        solve();
    }
    return 0;
}