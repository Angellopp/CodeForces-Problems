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

// vector <int> f;
int n, k;

void solve() {
    cin >> n;
    vector <int> v(n);
    map <int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]]++;
    }
    int ans = -1;
    for (auto x : m) {
        ans = max(x.S, ans);
    }
    cout << n - ans << endl;
}
int main() {
    fastio;
    int q;
    cout << fixed << setprecision(10);
    cin >> q;
    // f.emplace_back(1); f.emplace_back(1);
    // for (int i = 2; f.back() <= 2e5; i++) {
    //     f.emplace_back(f[i-1] + f[i-2]);
    // }
    while(q--) {
        solve();
    }
    return 0;
}
