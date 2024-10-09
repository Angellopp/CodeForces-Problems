#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20, '=') << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

const int N = 2e5 + 50;
const int MOD = 998244353;

const ll MX = 5e3+10;

int mul_mod(int a, int b) {
    return 1ll * a * b % MOD;
}
int sum_mod(int a, int b) {
    return (1ll * a + 1ll*b) % MOD;
}

int pow_mod(int a, int e) {
    int r = 1;
    while(e) {
        if (e & 1) r = mul_mod(r, a);
        a = mul_mod(a, a);
        e >>= 1;
    }
    return r;
}

int inv_mod(int a) { 
    return pow_mod(a, MOD - 2);
}

int factorial[N];

int C(int n, int k) {
    if (k > n) return 0;
    int num = factorial[n];
    int den = mul_mod(factorial[k], factorial[n - k]);
    return mul_mod(num, inv_mod(den));
}

int n, m;
vector<vector<int>> dp(MX, vector<int> (15, 0));
vector<vector<bool>> vis(MX, vector<bool> (15, 0));

int f(int falta, int sz) {
    if(vis[falta][sz]) return dp[falta][sz];
    vis[falta][sz] = 1;
    if (falta % 2) return dp[falta][sz] = 0; 
    if (sz == 1) return dp[falta][1] = (2 * falta <= n);
    for (int i = 0; i <= n and i <= falta; i+=2) {
        dp[falta][sz] = sum_mod(dp[falta][sz], mul_mod(C(n, i),f((falta-i)/2, sz-1)));
    }
    return dp[falta][sz];
}

void solve() {
    cin >> n >> m;
    int ans = 0;
    f(m, 14);
    cout << dp[m][14];
}

int main() {
    fastio;
    factorial[0] = 1;
    for (int i = 1; i < N; i++) {
        factorial[i] = 1ll * factorial[i - 1] * i % MOD;
    }
    int tt = 1;
    while(tt--) {
        solve();
    }
}