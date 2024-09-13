#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 1e8;

typedef ll tipo;
struct pto {
    tipo x, y;
    bool operator<(const pto& o) const { return (x == o.x) ? (y < o.y) : (x < o.x); }
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

int main() {
    fastio;
    ll n, a, b;
    cin >> n >> a >> b;
    vector <pto> v(n);
    map <ll, vector<pto>> mp;
    a*=-1;
    pto q = {a, 1}, ve;
    for (int i = 0; i < n; i++) {
        cin >> b >> ve;
        mp[q*ve].push_back(ve);
    }
    ll ans = 0;
    for(auto x : mp) {
        map<pto, ll> mm;
        ll s = 1ll * x.S.size() * x.S.size();
        for(auto y : x.S) mm[y]++;
        for(auto y : mm) s -= y.S * y.S;
        ans+=s;
    }
    cout << ans << endl;
}
