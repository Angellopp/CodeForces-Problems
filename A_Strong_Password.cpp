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

int f(string s){
    int n = s.size();
    int ans = 2;
    for (int i = 1; i <n; i++) {
        if(s[i] == s[i-1]) ans++;
        else ans+=2;
    }
    return ans;
}

int maxn = -1e9;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < 26; j++) {
    //         cp.insert(s.begin() + i, 'a' + j);
    //         dbg(cp);
    //         ans = max(ans, f(cp));
    //         if(f(cp) >= ans) {
    //             ans = f(cp);
    //             ss = cp;
    //         } 
    //         cp = s;
    //     }
    // }
    // cout << ss << endl;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) {
            j = i;
            break;
        }
    }
    for (int i = 0; i < j; i++) {
        cout << s[i];
    }
    if(s[j] == 'x') cout << 'y';
    else cout << 'x';
    for (int i = j; i < n; i++) {
        cout << s[i];
    }
    cout << endl;



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
