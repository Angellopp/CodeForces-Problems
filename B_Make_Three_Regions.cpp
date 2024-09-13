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

int f(string s){
    int n = s.size();
    int ans = 2;
    for (int i = 1; i <n; i++) {
        if(s[i] == s[i-1]) ans++;
        else ans+=2;
    }
    return ans;
}

const int maxn = 2e5+3;
char a[2][maxn];
void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i+1 < n; i++) {
        if(a[0][i] == '.') {
            if(a[0][i-1] == '.' and a[0][i+1] == '.' and a[1][i] == '.' and a[1][i-1] == 'x' and a[1][i+1] == 'x'){
                ans++;
            }
        }
    }
    for (int i = 1; i+1 < n; i++) {
        if(a[1][i] == '.') {
            if(a[1][i-1] == '.' and a[1][i+1] == '.' and a[0][i] == '.' and a[0][i-1] == 'x' and a[0][i+1] == 'x'){
                ans++;
            }
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
