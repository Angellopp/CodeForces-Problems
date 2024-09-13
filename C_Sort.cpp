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
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector <vector<int>> prea(n+1, vector<int>(26));
    vector <vector<int>> preb(n+1, vector<int>(26));
    for (int i = 0; i < n; i++) {
        prea[i+1] = prea[i];
        prea[i+1][(int)(a[i] - 'a')]++;
    }
    for (int i = 0; i < n; i++) {
        preb[i+1] = preb[i];
        preb[i+1][(int)(b[i] - 'a')]++;
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        vector <int> res(26);
        ll ans = 0;
        for (int i = 0; i < 26; i++) {
            res[i] = (prea[r][i] - prea[l-1][i]) - (preb[r][i] - preb[l-1][i]);
            ans += abs(res[i]);
        }
        cout << ans /2 << endl;

    }

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