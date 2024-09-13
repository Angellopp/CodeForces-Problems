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

vector <int> f;
int n, k;

tuple<int, int> extended_gcd(int a, int b) {
    if (b == 0) {
        return {1, 0}; // Caso base: gcd(a, 0) = a, x = 1, y = 0
    }
    int x1, y1;
    tie(x1, y1) = extended_gcd(b, a % b);
    int x = y1;
    int y = x1 - (a / b) * y1;
    return {x, y};
}

void solve() {
    cin >> n >> k;
    // f[k-2];
    if(k-3 >= f.size()) {
        cout << 0 << endl;
        return;
    }
    /*

            3     4
    x1 x2 x1+x2 x1+2x2  2x1+3x2
           0 1   1 2
    */
   int ans = 0;
    for (int i = 0; i * f[k-3] <= n; i++) {
        if((n - i*f[k-3]) % f[k-2] == 0 and (n - i*f[k-3]) / f[k-2] >= i) ans++;
    }
    cout << ans << endl;

}
int main() {
    fastio;
    int q;
    cout << fixed << setprecision(10);
    cin >> q;
    f.emplace_back(1); f.emplace_back(1);
    for (int i = 2; f.back() <= 2e5; i++) {
        f.emplace_back(f[i-1] + f[i-2]);
    }
    dbg(f.size());
    while(q--) {
        solve();
    }
    return 0;
}
