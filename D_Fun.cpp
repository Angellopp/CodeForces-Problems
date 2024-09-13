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

typedef double tipo;
struct pto {
    tipo x, y;
    pto operator+(const pto& o) const { return {x+o.x, y+o.y}; }
    pto operator-(const pto& o) const { return {x-o.x, y-o.y}; }
    tipo operator*(const pto& o) const { return x*o.x + y*o.y; }
    tipo operator^(const pto& o) const { return x*o.y - y*o.x; }
};

pto operator*(tipo k, const pto& p) { return {k*p.x, k*p.y}; }
pto operator/(const pto& p, tipo k) { return {p.x/k, p.y/k}; }
ostream &operator<<(ostream& os, const pto& p) {
    return os << "(" << p.x << "," << p.y << ")";
}
istream &operator>>(istream& is, pto& p) {
    return is >> p.x >> p.y;
}

tipo d(pto p1, pto p2) {
    pto dis = p1 - p2;
    return 1.0 * sqrt(dis.x * dis.x + dis.y * dis.y);
}
int a[1000][1000];

int maxn = -1e9;
void solve() {
    int n, x;
    cin >> n >> x;
    ll ans = min(x/3, (int)(sqrt(n/3)));
    // dbg(ans);
    for (int a = 1; a <= n-2; a++) {
        ll dif = max(0*1ll, min((1ll*n - 1ll*a*a) / (2*a), 1ll*x - 2*a*1ll));
        if(a <= dif and dif != 0) dif--;
        ans += dif * 3;
    }
    // dbg(ans);
    for (ll a = 1; a <= (int)sqrt(n); a++) {
        for(ll b = a+1; b <= (int)sqrt(n); b++) {
            ll dif = min((n - a*b) / (a+b), x - a - b);
            dif = max(0*1ll, dif - b);
            ans += 6 * dif;
        }
    }
    cout << ans << endl;


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
