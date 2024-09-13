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

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int cnt = 0;
    while (x > 1 and k > 0) {
        int r = y - (x % y);
        int xd = min(r, k);
        x += xd;
        k -= xd;
        while (x % y == 0) x/=y; 
    }
    if(k) x += k % (y-1);
    cout << x << endl;

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
